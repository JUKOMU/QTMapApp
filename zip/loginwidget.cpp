#include "loginwidget.h"

LoginWidget::LoginWidget(QWidget *parent)
    : QWidget{parent}
{
    resize (460,700);
    // 设置无边框
    setWindowFlags(Qt::FramelessWindowHint);

    // 设置背景图片
    setAutoFillBackground (true);
    QImageReader *read = new QImageReader(":/new/prefix1/logo.png");
    read->setScaledSize ({460,700});
    QPixmap img = QPixmap::fromImage (read->read ());
    if (img.isNull()) {
        qWarning() << "Something is wrong:" << read->errorString();
    }
    // 三层图层叠加
    QLabel *back_1 = new QLabel(this);
    back_1->setGeometry(0, 0, this->width(), this->height());
    back_1->setStyleSheet("background-color: white;border-radius:5px;");
    QLabel *background = new QLabel(this);
    background->setGeometry(0, 0, this->width()-3, this->height()-3);
    background->setPixmap (img);
    background->setStyleSheet("border-radius:5px;");
    QLabel *back_2 = new QLabel(this);
    back_2->setGeometry(0, 0, this->width(), this->height());
    back_2->setStyleSheet("background-color: rgba(0, 0, 0, 0.03);border-radius:5px; border: 2px solid white");
    // 设置窗口圆角
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setWindowFlag(Qt::FramelessWindowHint);
    this->setStyleSheet("CNWUserWifi{background-color:#000000;  \
        borderradius:8px;border-radius: 10px;}");
/*
    //构建最小化、最大化、关闭按钮
    minButton = new QToolButton(this);
    maxButton = new QToolButton(this);
    closeButton = new QToolButton(this);
    //获取最小化、关闭按钮图标
    QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);//最大化需要在事件中进行判断更换图标所以设置成数据成员
    //设置最小化、关闭按钮图标
    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);
    maxButton->setIcon(maxPix);

    //设置最小化、关闭按钮在界面的位置
    int wide = width();//获取界面的宽度
    minButton->setGeometry(wide-95,5,30,30);
    closeButton->setGeometry(wide-35,2,35,35);
    maxButton->setGeometry(wide-60,5,30,30);
    //设置鼠标移至按钮上的提示信息
    minButton->setToolTip(tr("最小化"));
    closeButton->setToolTip(tr("关闭"));
    maxButton->setToolTip(tr("最大化"));
    //设置最小化、关闭按钮的样式
    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");
    maxButton->setStyleSheet("background-color:transparent;");
    //每个按钮对应的信号槽
    connect(closeButton, SIGNAL(clicked()), this, SLOT(windowclosed()));
    connect(minButton, SIGNAL(clicked()), this, SLOT(windowmin()));
    connect(maxButton, SIGNAL(clicked()), this, SLOT(winmax()));
*/
    /*
    // 登录按钮
    QPushButton *user = new QPushButton;
    QPushButton *manager = new QPushButton;
    user->setText ("我是用户");
    manager->setText ("我是管理员");
    user->setStyleSheet ("font-family:'方正舒体';font-size:28px;color:white;background-color: rgba(52,135,255,0.95);border-radius:10px;");
    manager->setStyleSheet ("font-family:'方正舒体';font-size:28px;color:white;background-color: rgba(52,135,255,0.95);border-radius:10px;");
    user->setFixedSize (this->width()*0.618, this->height()*0.061);
    manager->setFixedSize (this->width()*0.618, this->height()*0.061);

    // 绑定登录事件
    connect (user,SIGNAL(clicked()),this,SLOT(userLogin()));
    connect (manager,SIGNAL(clicked()),this,SLOT(managerLogin()));

    // 设置按钮位置
    QVBoxLayout *loginButtons = new QVBoxLayout;
    loginButtons->addStretch (this->height()*0.35);
    loginButtons->addWidget (user);
    loginButtons->addWidget (manager);
    loginButtons->setSpacing (this->height()*0.02);
    loginButtons->addStretch (this->height()*0.1);
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch (1000);
    hbox->addLayout (loginButtons);
    hbox->addStretch (1000);
    setLayout (hbox);
*/
    QLabel *loading = new QLabel;
    loading->setText ("启动中");
    loading->setStyleSheet ("font-family:'方正舒体';font-size:28px;color:black;background-color: rgba(255,135,255,0)");
    QVBoxLayout *load = new QVBoxLayout;
    load->addStretch (this->height()*0.35);
    load->addWidget (loading);
    load->setSpacing (this->height()*0.02);
    load->addStretch (this->height()*0.1);
    QHBoxLayout *hbox = new QHBoxLayout;
    hbox->addStretch (1000);
    hbox->addLayout (load);
    hbox->addStretch (1000);
    setLayout (hbox);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this,[=](){
        if (times == 4){
            loading->setText ("启动中");
            times = 0;
            i++;
            if (i == 3){
                this->close ();
                MainWindow *w = new MainWindow;
                w->selectLoginMode (MainWindow::UserLogin);
                w->show();
            }
        }else {
            loading->setText (loading->text ()+".");
            times++;
        }
    });
    timer->start(500);
    times = 0;
    i = 0;
}
LoginWidget::~LoginWidget(){
}


void LoginWidget::windowclosed()
{
    this->close();
}
void LoginWidget::windowmin()
{
    this->showMinimized();//最小化
}
void LoginWidget::winmax()
{
    if (this->isMaximized())
    {
        this->showNormal();//还原事件
        maxPix = style()->standardPixmap(QStyle::SP_TitleBarMaxButton);
        maxButton->setIcon(maxPix);
        maxButton->setToolTip(tr("最大化"));
    }
    else
    {
        this->showMaximized();//最大化事件
        restore = style()->standardPixmap(QStyle::SP_TitleBarNormalButton);
        maxButton->setIcon(restore);
        maxButton->setToolTip(tr("最大化还原"));
    }
}
// 用户登录
void LoginWidget::userLogin(){
    MainWindow *w = new MainWindow;
    w->selectLoginMode (MainWindow::UserLogin);
    w->show();
    close ();
}
// 管理员登录
void LoginWidget::managerLogin(){
    MainWindow *w = new MainWindow;
    w->selectLoginMode (MainWindow::ManagerLogin);
    w->show();
    close ();
}


void LoginWidget::paintEvent(QPaintEvent* event)
{
    QStyleOption opt;
    opt.initFrom (this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}
void LoginWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
        clickPos=e->pos();
}
void LoginWidget::mouseMoveEvent(QMouseEvent *e)
{
    if(e->buttons()&Qt::LeftButton  //左键点击并且移动
        && e->pos().x()>=0      //范围在窗口的上面部分
        && e->pos().y()>=0
        && e->pos().x()<= geometry().width()
        && e->pos().y() <= geometry().height()/10)
    {
        move(e->pos()+pos()-clickPos);  //移动窗口
    }
}
