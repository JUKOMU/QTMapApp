#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    /* 初始化 */
    db = new Database;
    path = new Path();
    Mode = "navigationMap";
    // 存储经纬度
    lon_lat_map = new QVector<pair<QString,QString>>;
    // 存储名称地址
    name_address_map = new QVector<pair<QString,QString>>;
    // 存储注册和导航信息
    info = new QVector<pair<QString,QString>>;
    // 存储图像位置
    imagePath = new QVector<QString>;
    // 存储地点个数
    number = 0;
    rewriteInfo = new QDialog;
    upload = false;
    // 滚动条
    scrollArea = new QScrollArea;
    ui->setupUi(this);
    // 标题
    setWindowTitle ("新生校园导航系统");

    m_view=new QWebEngineView(this);
    QNetworkProxyFactory::setUseSystemConfiguration(false);
    setCentralWidget(m_view);
    channel = new QWebChannel(this);   //创建通道对象用于与JS交互
    channel->registerObject ("mainWindow",(QObject*)this);
    /*
    这里注册对象名"mainWindow"需要与JS函数用到的名称一致
    window.mainWindow_js = channel.objects.mainWindow;
    C++对象"mainWindow", JS对象mainWindow_js.
    JS调用QT中C++函数只需mainWindow_js.getCoordinate(e.point.lng, e.point.lat);网页向QT传递经纬度坐标
    这就实现了JS调用C++函数，实现网页向QT传递数据
    QString cmd=QString("js_function(%0,%1)")
                      .arg(ui->lon->text ())
                      .arg(ui->lon->text());
    把要调用的JS命令(js_function)当做QString传递给网页,这就实现了QT通过C++调用JS函数
    m_view->page()->runJavaScript(cmd);
    */
    m_view->page()->setWebChannel(channel);
    m_view->page()->load(QUrl ("qrc:/new/prefix1/baidumap.html"));//load the map in relevant path

    // 提示信息,编辑时显示
    ui->Tips->setText ("点击地图或直接输入");
    ui->Tips->hide ();
    // 设置按钮状态
    ui->index->setReadOnly (true);
    ui->name->setReadOnly (true);
    ui->address->setReadOnly (true);
    ui->lon->setReadOnly (true);
    ui->lat->setReadOnly (true);
    ui->guid_info->setReadOnly (true);
    ui->preparation_info->setReadOnly (true);
    ui->selectPicture->setEnabled (false);
    ui->clearImage->setEnabled (false);
    ui->confirmButton->setEnabled (false);
    ui->cancelButton->setEnabled (false);
    ui->createMapButton->setEnabled (true);
    ui->editMapButton->setEnabled (false);
    // 继续添加,存在路径时显示
    ui->continueAdd->hide ();
    // 上传，存在路径时显示
    ui->upload->hide ();


    //搜索按钮
    search_btn = new QPushButton(this);
    search_btn->setFixedSize(32, 32);//设置固定大小
    search_btn->setFlat(true);//去掉按钮边框
    search_btn->setToolTip("搜索");//设置鼠标悬浮的提示
    search_btn->setStyleSheet("QPushButton {border-image: url(:/new/prefix1/searchlogo_nothover.png)}"
                              "QPushButton:hover {border-image: url(:/new/prefix1/searchlogo.png)}"
                              "QPushButton:clicked {border-image: url(:/new/prefix1/searchlogo.png)}");
    //第一个编辑框
    search_edit = new QLineEdit(this);
    //设置编辑框位置大小
    search_edit->setGeometry(550, 30, 400, 35);
    //设置编辑框文字的边距，防止文字写到按钮上 参数：左 上 右 下
    search_edit->setTextMargins(0, 0, search_btn->width(), 0);
    //水平布局
    QHBoxLayout *hlayout = new QHBoxLayout;
    hlayout->addStretch();
    hlayout->addWidget(search_btn);//将按钮加到布局中
    hlayout->setContentsMargins(0, 0, 0, 0);//设置布局的边距
    //第一个编辑框添加布局（将按钮放在编辑框上）
    search_edit->setLayout(hlayout);
    search_edit->setStyleSheet("background-color: rgba(0, 0, 0, 0);border:0;border-radius:3px");

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addWidget (search_edit);

    // 浏览模式,切换地点
    connect (ui->index,&QLineEdit::editingFinished,this,[=](){selectPoit (ui->index->text ());});
    // 创建路径
    connect (ui->createMapButton,SIGNAL(clicked()),this,SLOT(createMode()));
    // 编辑路径
    connect (ui->editMapButton,SIGNAL(clicked()),this,SLOT(editMode()));
    // 确认,创建和编辑可用
    connect (ui->confirmButton,SIGNAL(clicked()),this,SLOT(confirm()));
    // 取消,创建和编辑可用
    connect (ui->cancelButton,SIGNAL(clicked()),this,SLOT(cancel()));
    //
    connect (ui->preparation_info,&QLineEdit::textChanged,this,[=](){
        int index = ui->index->text ().toInt () - 1;
        (*info)[index] = pair(ui->preparation_info->text (),(*info)[index].second);
    });
    connect (ui->guid_info,&QLineEdit::textChanged,this,[=](){
        int index = ui->index->text ().toInt () - 1;
        (*info)[index] = pair((*info)[index].first,ui->guid_info->text ());
    });
    // 图片
    connect (ui->selectPicture,SIGNAL(clicked()),this,SLOT(selectPicture()));
    connect (ui->clearImage,SIGNAL(clicked()),this,SLOT(clearImage()));
    // 上传和继续添加,仅浏览模式可用
    connect (ui->upload,SIGNAL(clicked()),this,SLOT(submit()));
    connect (ui->continueAdd,SIGNAL(clicked()),this,SLOT(continueAdd()));

    connect (search_btn,&QPushButton::clicked ,this,[=](){
        search_edit->setStyleSheet("background-color: rgba(255,255,255, 1);border:0;border-radius:5px");
        QString name = search_edit->text ();
        if (name == ""){

        }else{
            QVector<QString> nameList = db->findPath (name);

            if (nameList.length () == 1 && nameList[0] == name){
                updateInterface (navigationMap);
                path->setName (name);
                ui->pathName->setText (name);
                ui->index_2->setText ("1");
                ui->index_2->setReadOnly (true);
                ui->name_2->setReadOnly (true);
                ui->address_2->setReadOnly (true);
                ui->preparation_info_2->setReadOnly (true);
                ui->guid_info_2->setReadOnly (true);
                QVector<pair<QString,QString>> *points = path->getPoints ();
                QVector<pair<QString,QString>> *nameAddress = path->getNameAddressOfPoints ();
                QVector<pair<QString,QString>> *info = path->getInfo ();
                QVector<QPixmap> *images = path->getImages ();
                this->lon_lat_map = points;
                this->name_address_map = nameAddress;
                this->info = info;
                this->images = images;
                this->number = path->getNumber ();
                showInfo (1);
                drawMap ();
            }
        }
    });
    connect (search_edit,&QLineEdit::textChanged,this,[=](){
        //qDebug()<<1;
        QString name = search_edit->text ();
        QVector<QString> nameList = db->findPath (name);
        QStringList list;
        foreach (QString str, nameList) {
            list.append (str);
        };
        QCompleter *completer = new QCompleter(list,this);
        search_edit->setCompleter (completer);
    });

    connect (ui->prev,&QPushButton::clicked,this,[=](){
        int index = ui->index_2->text ().toInt ()-1;
        if (index < 1){
            index = number;
        }
        showInfo (index);
    });
    connect (ui->next,&QPushButton::clicked,this,[=](){
        int index = ui->index_2->text ().toInt ()+1;
        if (index > number){
            index = 1;
        }
        showInfo (index);
    });

    QTimer *timer = new QTimer(this);
    connect (ui->guid,&QPushButton::clicked,this,[=](){
        if (number != 0){
            times = 0;
            i = 0;
            timer->start(500);
        }
    });

    connect(timer, &QTimer::timeout, this,[=](){
        if (i == 11){
            i = 0;
            times++;
        }
        if (times < number-1){
            double betweenX = (*lon_lat_map)[times+1].first.toDouble () - (*lon_lat_map)[times].first.toDouble ();
            double betweenY = (*lon_lat_map)[times+1].second.toDouble () - (*lon_lat_map)[times].second.toDouble ();
            double x = (*lon_lat_map)[times].first.toDouble () + betweenX/10*i;
            double y = (*lon_lat_map)[times].second.toDouble () + betweenY/10*i;
            qDebug()<<x<<y;
            ui->index_2->setText (QString::number (times+1));
            ui->name_2->setText ((*name_address_map)[times].first);
            ui->address_2->setText ((*name_address_map)[times].second);
            ui->preparation_info_2->setText ((*info)[times].first);
            ui->guid_info_2->setText ((*info)[times].second);

            ui->vbox1_2->addWidget (scrollArea);
            scrollArea->setWidgetResizable(true);
            scrollArea->setWidget(ui->Picture_2);
            ui->Picture_2->setPixmap ((*images)[times]);
            ui->Picture->adjustSize();
            QString cmd = QString("visitPoint(%0,%1)").arg (x).arg(y);
            m_view->page()->runJavaScript(cmd);
            i++;
        }else{
            timer->stop ();
            showInfo (number);

        }

    });

}



MainWindow::~MainWindow()
{
    QList<QObject *> list = ui->infoDockWidget->findChildren<QObject *> ();
    foreach (QObject *obj, list) {
        obj->deleteLater ();
    }
    delete ui;
}

// 模式切换
void MainWindow::on_user_triggered(){
    this->close ();
    MainWindow *w = new MainWindow;
    w->selectLoginMode (UserLogin);
    w->show ();
    this->deleteLater ();
}
void MainWindow::on_manager_triggered(){
    this->close ();
    MainWindow *w = new MainWindow;
    w->selectLoginMode (ManagerLogin);
    w->show ();
    this->deleteLater ();
}

void MainWindow::selectLoginMode(Login mode){
    if (mode == UserLogin){
        ui->infoDockWidget->hide ();
        return;
    }
    if (mode == ManagerLogin){
        ui->infoDockWidget_2->hide ();
        return;
    }
    return;
}

void MainWindow::updateInterface(statusMode mode){
    if (mode == createMap) {
        Mode = "createMap";
        ui->index->setReadOnly (true);
        ui->name->setReadOnly (true);
        ui->address->setReadOnly (true);
        ui->lon->setReadOnly (true);
        ui->lat->setReadOnly (true);
        ui->preparation_info->setReadOnly (false);
        ui->guid_info->setReadOnly (false);
        ui->selectPicture->setEnabled (true);
        ui->confirmButton->setEnabled (true);
        ui->cancelButton->setEnabled (true);
        ui->createMapButton->setEnabled (false);
        ui->editMapButton->setEnabled (false);
        ui->continueAdd->setEnabled (false);
        ui->upload->setEnabled (false);
    }
    if (mode == editMap){
        Mode = "editMap";
        ui->index->setReadOnly (false);
        ui->name->setReadOnly (false);
        ui->address->setReadOnly (false);
        ui->lon->setReadOnly (false);
        ui->lat->setReadOnly (false);
        ui->preparation_info->setReadOnly (false);
        ui->guid_info->setReadOnly (false);
        ui->selectPicture->setEnabled (true);
        ui->confirmButton->setEnabled (false);
        ui->cancelButton->setEnabled (false);
        ui->createMapButton->setEnabled (false);
        ui->editMapButton->setEnabled (false);
        ui->continueAdd->setEnabled (false);
        ui->upload->setEnabled (false);
    }
    if (mode == navigationMap){
        ui->Tips->hide ();
        Mode = "navigationMap";
        ui->index->setReadOnly (false);
        ui->name->setReadOnly (true);
        ui->address->setReadOnly (true);
        ui->lon->setReadOnly (true);
        ui->lat->setReadOnly (true);
        ui->preparation_info->setReadOnly (true);
        ui->guid_info->setReadOnly (true);
        ui->selectPicture->setEnabled (false);
        ui->confirmButton->setEnabled (false);
        ui->cancelButton->setEnabled (false);
        if (upload){
            ui->createMapButton->setEnabled (false);
            ui->upload->show ();
            ui->continueAdd->show ();
            ui->upload->setEnabled (true);
            ui->continueAdd->setEnabled (true);
        }
        else {
            ui->createMapButton->setEnabled (true);
        }
        ui->editMapButton->setEnabled (true);
    }
    if (mode == continueAddMap){
        ui->Tips->show ();
        Mode = "continueAddMap";
        continueAddStatus = true;
        ui->index->setReadOnly (true);
        ui->name->setReadOnly (false);
        ui->address->setReadOnly (false);
        ui->lon->setReadOnly (false);
        ui->lat->setReadOnly (false);
        ui->selectPicture->setEnabled (true);
        ui->confirmButton->setEnabled (true);
        ui->cancelButton->setEnabled (true);
        ui->createMapButton->setEnabled (false);
        ui->editMapButton->setEnabled (false);
        ui->continueAdd->setEnabled (false);
        ui->upload->setEnabled (false);
    }
    return;
}

/*
void MainWindow::on_pushButton_clicked()
{
    //QString cmd=QString("addmarker(%0,%1)")
    //        .arg(ui->lon->text())
     //       .arg(ui->lat->text());
    //把要调用的JS命令当做QString传递给网页
    //对应baidumap.html 第77行
    //这就实现了QT通过C++调用JS函数
    //m_view->page()->runJavaScript(cmd);
}

void MainWindow::on_pushButton_3_clicked(){
    QString cmd=QString("change_Polyline(%0,%1,%2)").arg (ui->index->text ()).arg(ui->lon->text()).arg(ui->lat->text());

    //把要调用的JS命令当做QString传递给网页
    //这就实现了QT通过C++调用JS函数
    m_view->page()->runJavaScript(cmd);
}
*/

void MainWindow::getYourName()
{
    emit sigYourName("");
}

void MainWindow::createMode(){
    updateInterface(createMap);
    QString cmd=QString("createMap()");
    m_view->page()->runJavaScript(cmd);
    return;
}

void MainWindow::editMode(){
    updateInterface(editMap);
    QString cmd=QString("editMap()");
    m_view->page()->runJavaScript(cmd);
    // 构建输入窗口
    QDialog *selectWidget = new QDialog;
    selectWidget->setWindowTitle(tr(""));
    QLabel *label = new QLabel("选择要修改的点的序号:");
    QLineEdit *line = new QLineEdit;
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addWidget (label);
    hbox->addWidget (line);
    QDialogButtonBox *button = new QDialogButtonBox(selectWidget);
    button->addButton ("OK", QDialogButtonBox::YesRole);
    button->addButton ("CANCEL", QDialogButtonBox::NoRole);
    QVBoxLayout *layout = new QVBoxLayout(selectWidget);
    layout->addLayout (hbox);
    layout->addWidget (button);
    selectWidget->setLayout (layout);
    selectWidget->setWindowModality(Qt::ApplicationModal);
    selectWidget->show();

    connect(button, &QDialogButtonBox::accepted,this,[=](){
        qDebug()<<90;
        if (line->text () != ""){
            // 输入信息不为空,更新选取的地点信息
            int index = line->text ().toInt ()-1;
            qDebug()<<(*name_address_map)[index].first;
            //selectPoit (line->text ());
            ui->index->setReadOnly (true);
            ui->name->setReadOnly (false);
            ui->address->setReadOnly (false);
            ui->lon->setReadOnly (false);
            ui->lat->setReadOnly (false);
            ui->confirmButton->setEnabled (true);
            ui->cancelButton->setEnabled (true);
            ui->createMapButton->setEnabled (false);
            ui->editMapButton->setEnabled (false);

            ui->index->setText (line->text ());
            old_name = (*name_address_map)[index].first;
            old_address = (*name_address_map)[index].second;
            old_lon = (*lon_lat_map)[index].first;
            old_lat = (*lon_lat_map)[index].second;
            old_preparation = (*info)[index].first;
            old_guidance = (*info)[index].second;
            if (imagePath->length () == 0){
                qDebug()<<"000000";
                old_image = " ";
            }else {
                old_image = (*imagePath)[index];
            }
            qDebug()<<"1";

            selectPoit (ui->index->text ());
            selectWidget->deleteLater ();
        }
        else {
            // 未完成输入,继续输入或者取消
            QMessageBox *box = new QMessageBox;
            box->information (this,tr("Message"),tr("You haven't pick a point!"));
        }
    });
    connect (button, &QDialogButtonBox::rejected,this,[=](){
        navigateMode ();
        selectWidget->deleteLater ();
    });
    return;
}

void MainWindow::navigateMode(){
    updateInterface (navigationMap);
    Mode = "navigationMap";
    QString cmd=QString("navigateMap()");
    m_view->page()->runJavaScript(cmd);
    return;
}


void MainWindow::continueAdd(){
    updateInterface (continueAddMap);
    QString cmd=QString("continueAdd()");
    m_view->page()->runJavaScript(cmd);
    return;
}

// 提交到数据库
void MainWindow::submit(){
    if (upload){
        // 构建输入窗口
        QDialog *namedPath = new QDialog;
        namedPath->setWindowTitle(tr(""));
        QLabel *label = new QLabel("路径名:");
        QLineEdit *line = new QLineEdit;
        QHBoxLayout *hbox = new QHBoxLayout;
        hbox->addWidget (label);
        hbox->addWidget (line);
        QDialogButtonBox *button = new QDialogButtonBox(namedPath);
        button->addButton ("OK", QDialogButtonBox::YesRole);
        button->addButton ("CANCEL", QDialogButtonBox::NoRole);
        QVBoxLayout *layout = new QVBoxLayout(namedPath);
        layout->addLayout (hbox);
        layout->addWidget (button);
        namedPath->setLayout (layout);
        namedPath->setWindowModality(Qt::ApplicationModal);
        namedPath->show();

        connect(button, &QDialogButtonBox::accepted,this,[=](){
            if (line->text () != ""){
                path = new Path();
                path->setName (line->text ());
                path->setNameAddressOfPoints (name_address_map);
                path->setPoints (lon_lat_map);
                path->setInfo (info);
                path->setImages (imagePath);
                if (path->uploadPath (number)){
                    namedPath->close ();
                }
            }
            else {
                // 未完成输入,继续输入或者取消
                QMessageBox *box = new QMessageBox;
                box->information (this,tr("Message"),tr("You haven't named the path!"));
            }
        });
        connect (button, &QDialogButtonBox::rejected,this,[=](){
            // 未完成输入,继续输入或者取消
            QMessageBox *box = new QMessageBox;
            box->information (this,tr("Message"),tr("Sorry, failed to submit!"));
            navigateMode ();
            namedPath->deleteLater ();
        });
    }
    return;
}

void MainWindow::confirm(){
    if (Mode == "createMap" || Mode == "continueAddMap"){
        if (number != 0){
            upload = true;
        }
    }
    if (Mode == "editMap"){
        int index = ui->index->text ().toInt () - 1;
        (*lon_lat_map)[index] = pair(ui->lon->text (),ui->lat->text ());
        (*info)[index] = pair(ui->preparation_info->text (),ui->guid_info->text ());
        /* 根据是否修改选择存储旧数据或者更新 */
        // 是否发生修改
        if (ui->name->text().left (4) == "(未指定" || ui->address->text ().left (4) == "(未指定"){
            // name是否发生修改
            if (ui->name->text().left (4) == "(未指定"){
                // address是否发生修改
                if (ui->address->text ().left (4) == "(未指定"){
                    // 都未修改
                    (*name_address_map)[index] = pair(old_name,old_address);
                }else {
                    // 只有address发生修改
                    (*name_address_map)[index] = pair(old_name,ui->address->text ());
                }
            }else{
                // 只有name发生修改
                (*name_address_map)[index] = pair(ui->name->text(),old_address);
            }
        }else{
            // 都修改
            (*name_address_map)[index] = pair(ui->name->text(),ui->address->text ());
        }
        old_name = (*name_address_map)[index].first;
        old_address = (*name_address_map)[index].second;
        old_lon = (*lon_lat_map)[index].first;
        old_lat = (*lon_lat_map)[index].second;
        old_preparation = (*info)[index].first;
        old_guidance = (*info)[index].second;

        selectPoit (ui->index->text ());
    }
    navigateMode ();
}

void MainWindow::cancel(){
    if (Mode == "createMap"){
        name_address_map->clear ();
        lon_lat_map->clear ();
        info->clear ();
        imagePath->clear ();
        number = 0;
        ui->index->setText ("");
        ui->name->setText ("");
        ui->address->setText ("");
        ui->lon->setText ("");
        ui->lat->setText ("");
        ui->preparation_info->setText ("");
        ui->guid_info->setText ("");
        clearImage ();
        QString cmd=QString("cancel()");
        m_view->page()->runJavaScript(cmd);
    }
    if (Mode == "editMap"){
        ui->name->setText (old_name);
        ui->address->setText (old_address);
        ui->lon->setText (old_lon);
        ui->lat->setText (old_lat);
        ui->preparation_info->setText (old_preparation);
        ui->guid_info->setText (old_guidance);
        showImage (old_image);
        QString cmd=QString("change_Polyline(%0,%1,%2)").arg (ui->index->text ()).arg (old_lon).arg(old_lat);
        m_view->page()->runJavaScript(cmd);
    }
    if (Mode == "continueAddMap"){
        //qDebug()<<continueAddStatus;
        if (!continueAddStatus){
            // 更新地图
            QString cmd=QString("delete_Point(%0)").arg (number-1);
            m_view->page()->runJavaScript(cmd);
            // 移除信息
            name_address_map->pop_back ();
            lon_lat_map->pop_back ();
            info->pop_back ();
            imagePath->pop_back ();
            number--;
            fresh ();
        }
    }
    navigateMode ();
}

void MainWindow::selectPoit(QString index){
    int i = index.toInt ();
    ui->name->setText((*name_address_map)[i-1].first);
    ui->address->setText((*name_address_map)[i-1].second);
    ui->lon->setText((*lon_lat_map)[i-1].first);
    ui->lat->setText((*lon_lat_map)[i-1].second);
    ui->preparation_info->setText ((*info)[i-1].first);
    ui->guid_info->setText ((*info)[i-1].second);
    if (old_image == " "){
        qDebug()<<"22222";
        clearImage ();
        qDebug()<<"11111";
        ui->clearImage->setEnabled (true);
        ui->vbox1->addWidget (scrollArea);
        scrollArea->setWidgetResizable(true);
        scrollArea->setWidget(ui->Picture);
        ui->Picture->setPixmap((*images)[i-1]);
        ui->Picture->adjustSize();
    }else {
        showImage ((*imagePath)[i-1]);
    }

}

void MainWindow::fresh(){
    if (number == 0){
        ui->index->setText ("");
        ui->name->setText ("");
        ui->address->setText ("");
        ui->lon->setText ("");
        ui->lat->setText ("");
        ui->preparation_info->setText ("");
        ui->guid_info->setText ("");
        clearImage ();
        upload = false;
    }else {
        ui->index->setText (QString::number (number));
        ui->name->setText((*name_address_map)[number-1].first);
        ui->address->setText((*name_address_map)[number-1].second);
        ui->lon->setText((*lon_lat_map)[number-1].first);
        ui->lat->setText((*lon_lat_map)[number-1].second);
        ui->preparation_info->setText ((*info)[number-1].first);
        ui->guid_info->setText ((*info)[number-1].second);
        showImage ((*imagePath)[number-1]);
    }
}

void MainWindow::drawMap(){

    QString cmd_1=QString("clearPoints()");
    m_view->page()->runJavaScript(cmd_1);
    for (int i = 0; i < number; ++i) {
        QString x = (*lon_lat_map)[i].first;
        QString y = (*lon_lat_map)[i].second;
        QString cmd_2=QString("storePoints(%0,%1)").arg (x).arg (y);
        m_view->page()->runJavaScript(cmd_2);
    }
    QString cmd_3=QString("add_Polyline()");
    m_view->page()->runJavaScript(cmd_3);
}

void MainWindow::clearImage(){
    // 清除上一次的图片
    try {
        ui->Picture->clear ();
        ui->clearImage->setEnabled (false);
    } catch (...) {
    }

}
// 选择图片
void MainWindow::selectPicture(QString filePath){
    if (filePath == " "){
        filePath = QFileDialog::getOpenFileName(this, "选择图片", "", "Images (*.png *.jpg)");
        showImage (filePath);
    }
    // 如果选择了文件
    if (!filePath.isEmpty()){
        if (Mode == "createMap" || Mode == "continueAddMap"){
            (*imagePath)[number-1] = filePath;
        }
        if (Mode == "editMap"){
            int index = ui->index->text ().toInt ()-1;
            (*imagePath)[index] = filePath;
        }
    }
}
void MainWindow::showImage(QString filePath){
    // 加载图片并在标签中显示
    try{
        QImageReader reader(filePath);
        QSize sizeOfImage = reader.size();
        int height = sizeOfImage.height();
        int width = sizeOfImage.width();
        if (width >1000 || height >1000){
            reader.setScaledSize (QSize(width/2,height/2));
        }
        QImage image = reader.read ();
        if (!image.isNull()){
            clearImage ();
            ui->clearImage->setEnabled (true);
            ui->vbox1->addWidget (scrollArea);
            scrollArea->setWidgetResizable(true);
            scrollArea->setWidget(ui->Picture);
            ui->Picture->setPixmap(QPixmap::fromImage(image));
            ui->Picture->adjustSize();
        }
    }catch (...){}
}

// mode == 1, QString name,QString address
void MainWindow::storeInfo(QString mode,QString lon,QString lat){
    //qDebug()<<Mode;
    if (Mode == "createMap"){
        imagePath->push_back (" ");
        QString preparation = ui->preparation_info->text ()+" ";
        QString guidance = ui->guid_info->text ()+" ";
        info->push_back (pair(preparation,guidance));
        if (mode == "0"){
            lon_lat_map->push_back (pair(lon,lat));
        }
        if (mode == "1"){
            //qDebug()<<lon<<lat;
            name_address_map->push_back (pair(lon,lat));
            number++;
            QString flag("0");
            /* 选取地点无name和address信息,需要手动指定 */
            if (lon == flag){
                // 构建输入窗口
                rewriteInfo->setWindowTitle(tr("Warning"));
                QLabel *warning = new QLabel(tr(" Please complete the name and address."));
                QLabel *namelabel = new QLabel("名称:");
                QLabel *addresslabel = new QLabel("地址:");
                QLineEdit *nameline = new QLineEdit;
                QLineEdit *addressline = new QLineEdit;
                QHBoxLayout *hbox1 = new QHBoxLayout;
                hbox1->addWidget (namelabel);
                hbox1->addWidget (nameline);
                QHBoxLayout *hbox2 = new QHBoxLayout;
                hbox2->addWidget (addresslabel);
                hbox2->addWidget (addressline);
                QDialogButtonBox *button = new QDialogButtonBox(rewriteInfo);
                button->addButton ("YES", QDialogButtonBox::YesRole);
                button->addButton ("NO", QDialogButtonBox::NoRole);
                QVBoxLayout *layout = new QVBoxLayout(rewriteInfo);
                layout->addWidget (warning);
                layout->addLayout (hbox1);
                layout->addLayout (hbox2);
                layout->addWidget (button);
                rewriteInfo->setLayout (layout);
                rewriteInfo->setWindowModality(Qt::ApplicationModal);
                rewriteInfo->show();

                connect(button, &QDialogButtonBox::accepted,this,[=](){
                    if (nameline->text () != "" && addressline->text () != ""){
                        // 输入信息不为空,更新选取的地点信息
                        (*name_address_map)[number-1] = pair (nameline->text (),addressline->text ());
                        rewriteInfo->close ();
                        warning->deleteLater ();
                        button->deleteLater ();
                        layout->deleteLater ();
                    }
                    else {
                        // 未完成输入,继续输入或者取消
                        QMessageBox *box = new QMessageBox;
                        box->information (this,tr("Message"),tr("Sorry, cannot create this point without necessary infomation."));
                    }
                });
                connect (button, &QDialogButtonBox::rejected,this,[=](){
                    // 取消输入,并移除选取的地点
                    QMessageBox *box = new QMessageBox;
                    box->information (this,tr("Message"),tr("Sorry, cannot create this point without necessary infomation."));
                    // 更新地图
                    QString cmd=QString("delete_Point(%0)").arg (number-1);
                    m_view->page()->runJavaScript(cmd);
                    //qDebug()<<"w";

                    rewriteInfo->close ();
                    warning->deleteLater ();
                    button->deleteLater ();
                    layout->deleteLater ();
                    // 移除信息
                    name_address_map->pop_back ();
                    lon_lat_map->pop_back ();
                    info->pop_back ();
                    imagePath->pop_back ();
                    number--;
                    fresh ();
                    return;
                });

            }
            // 显示选取地点信息
            ui->index->setText (QString::number (number));
            ui->name->setText((*name_address_map)[number-1].first);
            ui->address->setText((*name_address_map)[number-1].second);
            ui->lon->setText((*lon_lat_map)[number-1].first);
            ui->lat->setText((*lon_lat_map)[number-1].second);
            ui->preparation_info->setText ("");
            ui->guid_info->setText ("");
            clearImage ();
        }
    }
    if (Mode == "editMap"){
        if (mode == "0"){
            ui->lon->setText (lon);
            ui->lat->setText (lat);
            QString cmd=QString("change_Polyline(%0,%1,%2)").arg (ui->index->text ()).arg (lon).arg(lat);
            m_view->page()->runJavaScript(cmd);
        }
        if (mode == "1"){
            //qDebug()<<lon;
            ui->name->setText (lon);
            ui->address->setText (lat);
            QString flag("0");
            /* 选取地点无name和address信息,需要手动指定 */
            if (lon == flag){
                ui->name->setText ("(未指定,将使用原名称)"+old_name);
                ui->address->setText ("(未指定,将使用原地址)"+old_address);
            }
        }
    }
    if (Mode == "continueAddMap"){
        imagePath->push_back (" ");
        QString preparation = ui->preparation_info->text ()+" ";
        QString guidance = ui->guid_info->text ()+" ";
        info->push_back (pair(preparation,guidance));
        if (mode == "0"){
            lon_lat_map->push_back (pair(lon,lat));
        }
        if (mode == "1"){
            name_address_map->push_back (pair(lon,lat));
            number++;
            QString flag("0");
            /* 选取地点无name和address信息,需要手动指定 */
            if (lon == flag){
                // 构建输入窗口
                rewriteInfo->setWindowTitle(tr("Warning"));
                QLabel *warning = new QLabel(tr(" Please complete the name and address."));
                QLabel *namelabel = new QLabel("名称:");
                QLabel *addresslabel = new QLabel("地址:");
                QLineEdit *nameline = new QLineEdit;
                QLineEdit *addressline = new QLineEdit;
                QHBoxLayout *hbox1 = new QHBoxLayout;
                hbox1->addWidget (namelabel);
                hbox1->addWidget (nameline);
                QHBoxLayout *hbox2 = new QHBoxLayout;
                hbox2->addWidget (addresslabel);
                hbox2->addWidget (addressline);
                QDialogButtonBox *button = new QDialogButtonBox(rewriteInfo);
                button->addButton ("YES", QDialogButtonBox::YesRole);
                button->addButton ("NO", QDialogButtonBox::NoRole);
                QVBoxLayout *layout = new QVBoxLayout(rewriteInfo);
                layout->addWidget (warning);
                layout->addLayout (hbox1);
                layout->addLayout (hbox2);
                layout->addWidget (button);
                rewriteInfo->setLayout (layout);
                rewriteInfo->show();

                connect(button, &QDialogButtonBox::accepted,this,[=](){
                    if (nameline->text () != "" && addressline->text () != ""){
                        // 输入信息不为空,更新选取的地点信息
                        (*name_address_map)[number-1] = pair (nameline->text (),addressline->text ());
                        rewriteInfo->close ();
                        warning->deleteLater ();
                        button->deleteLater ();
                        layout->deleteLater ();
                        continueAddStatus = false;
                    }
                    else {
                        // 未完成输入,继续输入或者取消
                        QMessageBox *box = new QMessageBox;
                        box->information (this,tr("Message"),tr("Sorry, cannot create this point without necessary infomation."));
                    }
                });
                connect (button, &QDialogButtonBox::rejected,this,[=](){
                    // 取消输入,并移除选取的地点
                    QMessageBox *box = new QMessageBox;
                    box->information (this,tr("Message"),tr("Sorry, cannot create this point without necessary infomation."));
                    // 更新地图
                    QString cmd=QString("delete_Point(%0)").arg (number-1);
                    m_view->page()->runJavaScript(cmd);

                    rewriteInfo->close ();
                    warning->deleteLater ();
                    button->deleteLater ();
                    layout->deleteLater ();
                    // 移除信息
                    name_address_map->pop_back ();
                    lon_lat_map->pop_back ();
                    info->pop_back ();
                    imagePath->pop_back ();
                    number--;
                    fresh ();
                    navigateMode ();
                    return;
                });
            }
            // 显示选取地点信息
            ui->index->setText (QString::number (number));
            ui->name->setText((*name_address_map)[number-1].first);
            ui->address->setText((*name_address_map)[number-1].second);
            ui->lon->setText((*lon_lat_map)[number-1].first);
            ui->lat->setText((*lon_lat_map)[number-1].second);
            ui->preparation_info->setText ("");
            ui->guid_info->setText ("");
            clearImage ();
        }
    }
    if (Mode == "navigationMap"){
    }
}

void MainWindow::showInfo(int index){
    ui->index_2->setText (QString::number (index));
    ui->name_2->setText ((*name_address_map)[index-1].first);
    ui->address_2->setText ((*name_address_map)[index-1].second);
    ui->preparation_info_2->setText ((*info)[index-1].first);
    ui->guid_info_2->setText ((*info)[index-1].second);

    ui->vbox1_2->addWidget (scrollArea);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(ui->Picture_2);
    ui->Picture_2->setPixmap ((*images)[index-1]);
    ui->Picture->adjustSize();

    QString cmd = QString("visitPoint(%0,%1)").arg ((*lon_lat_map)[index-1].first).arg((*lon_lat_map)[index-1].second);
    m_view->page()->runJavaScript(cmd);
}
