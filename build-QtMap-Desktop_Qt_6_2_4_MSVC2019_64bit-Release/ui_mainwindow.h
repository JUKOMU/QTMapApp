#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *about;
    QAction *manager;
    QAction *user;
    QAction *useness;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu_2;
    QMenu *menu_3;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *infoDockWidget;
    QWidget *infoWidget;
    QVBoxLayout *verticalLayout;
    QLabel *Tips;
    QHBoxLayout *hbox1;
    QLabel *label_index;
    QLineEdit *index;
    QHBoxLayout *hbox2;
    QLabel *label_name;
    QLineEdit *name;
    QHBoxLayout *hbox3;
    QLabel *label_address;
    QLineEdit *address;
    QHBoxLayout *hbox4;
    QLabel *label_lon;
    QLineEdit *lon;
    QHBoxLayout *hbox5;
    QLabel *label_lat;
    QLineEdit *lat;
    QHBoxLayout *hbox5_2;
    QLabel *label_preparation;
    QLineEdit *preparation_info;
    QHBoxLayout *hbox5_3;
    QLabel *label_guid;
    QLineEdit *guid_info;
    QVBoxLayout *vbox1;
    QHBoxLayout *hbox6;
    QLabel *labelPicture;
    QPushButton *clearImage;
    QPushButton *selectPicture;
    QLabel *Picture;
    QVBoxLayout *vbox2;
    QHBoxLayout *hbox7;
    QPushButton *confirmButton;
    QHBoxLayout *hbox8;
    QPushButton *cancelButton;
    QHBoxLayout *hbox9;
    QPushButton *createMapButton;
    QHBoxLayout *hbox10;
    QPushButton *editMapButton;
    QHBoxLayout *hbox10_3;
    QPushButton *continueAdd;
    QHBoxLayout *hbox10_2;
    QPushButton *upload;
    QSpacerItem *verticalSpacer;
    QDockWidget *infoDockWidget_2;
    QWidget *infoWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *pathName;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *guid;
    QHBoxLayout *hbox1_2;
    QLabel *label_index_2;
    QLineEdit *index_2;
    QHBoxLayout *hbox2_2;
    QLabel *label_name_2;
    QLineEdit *name_2;
    QHBoxLayout *hbox3_2;
    QLabel *label_address_2;
    QLineEdit *address_2;
    QHBoxLayout *hbox5_5;
    QLabel *label_preparation_2;
    QLineEdit *preparation_info_2;
    QHBoxLayout *hbox5_6;
    QLabel *label_guid_2;
    QLineEdit *guid_info_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *prev;
    QPushButton *next;
    QVBoxLayout *vbox1_2;
    QLabel *labelPicture_2;
    QLabel *Picture_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1338, 742);
        about = new QAction(MainWindow);
        about->setObjectName(QString::fromUtf8("about"));
        manager = new QAction(MainWindow);
        manager->setObjectName(QString::fromUtf8("manager"));
        user = new QAction(MainWindow);
        user->setObjectName(QString::fromUtf8("user"));
        useness = new QAction(MainWindow);
        useness->setObjectName(QString::fromUtf8("useness"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1338, 25));
        menuBar->setMinimumSize(QSize(0, 0));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        infoDockWidget = new QDockWidget(MainWindow);
        infoDockWidget->setObjectName(QString::fromUtf8("infoDockWidget"));
        infoDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea);
        infoWidget = new QWidget();
        infoWidget->setObjectName(QString::fromUtf8("infoWidget"));
        verticalLayout = new QVBoxLayout(infoWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Tips = new QLabel(infoWidget);
        Tips->setObjectName(QString::fromUtf8("Tips"));

        verticalLayout->addWidget(Tips);

        hbox1 = new QHBoxLayout();
        hbox1->setSpacing(6);
        hbox1->setObjectName(QString::fromUtf8("hbox1"));
        label_index = new QLabel(infoWidget);
        label_index->setObjectName(QString::fromUtf8("label_index"));

        hbox1->addWidget(label_index);

        index = new QLineEdit(infoWidget);
        index->setObjectName(QString::fromUtf8("index"));
        index->setStyleSheet(QString::fromUtf8("border-radius:3px"));

        hbox1->addWidget(index);


        verticalLayout->addLayout(hbox1);

        hbox2 = new QHBoxLayout();
        hbox2->setSpacing(6);
        hbox2->setObjectName(QString::fromUtf8("hbox2"));
        label_name = new QLabel(infoWidget);
        label_name->setObjectName(QString::fromUtf8("label_name"));

        hbox2->addWidget(label_name);

        name = new QLineEdit(infoWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setStyleSheet(QString::fromUtf8("border-radius:3px"));

        hbox2->addWidget(name);


        verticalLayout->addLayout(hbox2);

        hbox3 = new QHBoxLayout();
        hbox3->setSpacing(6);
        hbox3->setObjectName(QString::fromUtf8("hbox3"));
        label_address = new QLabel(infoWidget);
        label_address->setObjectName(QString::fromUtf8("label_address"));

        hbox3->addWidget(label_address);

        address = new QLineEdit(infoWidget);
        address->setObjectName(QString::fromUtf8("address"));
        address->setStyleSheet(QString::fromUtf8("border-radius:3px"));

        hbox3->addWidget(address);


        verticalLayout->addLayout(hbox3);

        hbox4 = new QHBoxLayout();
        hbox4->setSpacing(6);
        hbox4->setObjectName(QString::fromUtf8("hbox4"));
        label_lon = new QLabel(infoWidget);
        label_lon->setObjectName(QString::fromUtf8("label_lon"));

        hbox4->addWidget(label_lon);

        lon = new QLineEdit(infoWidget);
        lon->setObjectName(QString::fromUtf8("lon"));
        lon->setStyleSheet(QString::fromUtf8("border-radius:3px"));

        hbox4->addWidget(lon);


        verticalLayout->addLayout(hbox4);

        hbox5 = new QHBoxLayout();
        hbox5->setSpacing(6);
        hbox5->setObjectName(QString::fromUtf8("hbox5"));
        label_lat = new QLabel(infoWidget);
        label_lat->setObjectName(QString::fromUtf8("label_lat"));

        hbox5->addWidget(label_lat);

        lat = new QLineEdit(infoWidget);
        lat->setObjectName(QString::fromUtf8("lat"));
        lat->setStyleSheet(QString::fromUtf8("border-radius:3px"));

        hbox5->addWidget(lat);


        verticalLayout->addLayout(hbox5);

        hbox5_2 = new QHBoxLayout();
        hbox5_2->setSpacing(6);
        hbox5_2->setObjectName(QString::fromUtf8("hbox5_2"));
        label_preparation = new QLabel(infoWidget);
        label_preparation->setObjectName(QString::fromUtf8("label_preparation"));

        hbox5_2->addWidget(label_preparation);

        preparation_info = new QLineEdit(infoWidget);
        preparation_info->setObjectName(QString::fromUtf8("preparation_info"));
        preparation_info->setStyleSheet(QString::fromUtf8("border-radius:3px"));

        hbox5_2->addWidget(preparation_info);


        verticalLayout->addLayout(hbox5_2);

        hbox5_3 = new QHBoxLayout();
        hbox5_3->setSpacing(6);
        hbox5_3->setObjectName(QString::fromUtf8("hbox5_3"));
        label_guid = new QLabel(infoWidget);
        label_guid->setObjectName(QString::fromUtf8("label_guid"));

        hbox5_3->addWidget(label_guid);

        guid_info = new QLineEdit(infoWidget);
        guid_info->setObjectName(QString::fromUtf8("guid_info"));
        guid_info->setStyleSheet(QString::fromUtf8("border-radius:3px"));

        hbox5_3->addWidget(guid_info);


        verticalLayout->addLayout(hbox5_3);

        vbox1 = new QVBoxLayout();
        vbox1->setSpacing(6);
        vbox1->setObjectName(QString::fromUtf8("vbox1"));
        hbox6 = new QHBoxLayout();
        hbox6->setSpacing(6);
        hbox6->setObjectName(QString::fromUtf8("hbox6"));
        labelPicture = new QLabel(infoWidget);
        labelPicture->setObjectName(QString::fromUtf8("labelPicture"));
        labelPicture->setMaximumSize(QSize(16777215, 16777215));
        labelPicture->setLayoutDirection(Qt::LeftToRight);

        hbox6->addWidget(labelPicture);

        clearImage = new QPushButton(infoWidget);
        clearImage->setObjectName(QString::fromUtf8("clearImage"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(clearImage->sizePolicy().hasHeightForWidth());
        clearImage->setSizePolicy(sizePolicy);

        hbox6->addWidget(clearImage);

        selectPicture = new QPushButton(infoWidget);
        selectPicture->setObjectName(QString::fromUtf8("selectPicture"));
        sizePolicy.setHeightForWidth(selectPicture->sizePolicy().hasHeightForWidth());
        selectPicture->setSizePolicy(sizePolicy);

        hbox6->addWidget(selectPicture);


        vbox1->addLayout(hbox6);

        Picture = new QLabel(infoWidget);
        Picture->setObjectName(QString::fromUtf8("Picture"));
        Picture->setMaximumSize(QSize(16777215, 16777215));

        vbox1->addWidget(Picture);


        verticalLayout->addLayout(vbox1);

        vbox2 = new QVBoxLayout();
        vbox2->setSpacing(6);
        vbox2->setObjectName(QString::fromUtf8("vbox2"));
        hbox7 = new QHBoxLayout();
        hbox7->setSpacing(6);
        hbox7->setObjectName(QString::fromUtf8("hbox7"));
        confirmButton = new QPushButton(infoWidget);
        confirmButton->setObjectName(QString::fromUtf8("confirmButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(confirmButton->sizePolicy().hasHeightForWidth());
        confirmButton->setSizePolicy(sizePolicy1);
        confirmButton->setMinimumSize(QSize(30, 0));
        confirmButton->setMaximumSize(QSize(200, 16777215));
        confirmButton->setCursor(QCursor(Qt::ArrowCursor));
        confirmButton->setMouseTracking(false);
        confirmButton->setLayoutDirection(Qt::LeftToRight);
        confirmButton->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:white;\n"
"border: 1px solid black"));

        hbox7->addWidget(confirmButton);


        vbox2->addLayout(hbox7);

        hbox8 = new QHBoxLayout();
        hbox8->setSpacing(6);
        hbox8->setObjectName(QString::fromUtf8("hbox8"));
        cancelButton = new QPushButton(infoWidget);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setMaximumSize(QSize(200, 16777215));
        cancelButton->setCursor(QCursor(Qt::ArrowCursor));
        cancelButton->setMouseTracking(false);
        cancelButton->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:white;\n"
"border: 1px solid black"));

        hbox8->addWidget(cancelButton);


        vbox2->addLayout(hbox8);

        hbox9 = new QHBoxLayout();
        hbox9->setSpacing(6);
        hbox9->setObjectName(QString::fromUtf8("hbox9"));
        createMapButton = new QPushButton(infoWidget);
        createMapButton->setObjectName(QString::fromUtf8("createMapButton"));
        createMapButton->setMaximumSize(QSize(200, 16777215));
        createMapButton->setCursor(QCursor(Qt::ArrowCursor));
        createMapButton->setMouseTracking(false);
        createMapButton->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:white;\n"
"border: 1px solid black"));

        hbox9->addWidget(createMapButton);


        vbox2->addLayout(hbox9);

        hbox10 = new QHBoxLayout();
        hbox10->setSpacing(6);
        hbox10->setObjectName(QString::fromUtf8("hbox10"));
        editMapButton = new QPushButton(infoWidget);
        editMapButton->setObjectName(QString::fromUtf8("editMapButton"));
        editMapButton->setMaximumSize(QSize(200, 16777215));
        editMapButton->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:white;\n"
"border: 1px solid black"));

        hbox10->addWidget(editMapButton);


        vbox2->addLayout(hbox10);

        hbox10_3 = new QHBoxLayout();
        hbox10_3->setSpacing(6);
        hbox10_3->setObjectName(QString::fromUtf8("hbox10_3"));
        continueAdd = new QPushButton(infoWidget);
        continueAdd->setObjectName(QString::fromUtf8("continueAdd"));
        continueAdd->setMaximumSize(QSize(200, 16777215));
        continueAdd->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:white;\n"
"border: 1px solid black"));

        hbox10_3->addWidget(continueAdd);


        vbox2->addLayout(hbox10_3);

        hbox10_2 = new QHBoxLayout();
        hbox10_2->setSpacing(6);
        hbox10_2->setObjectName(QString::fromUtf8("hbox10_2"));
        upload = new QPushButton(infoWidget);
        upload->setObjectName(QString::fromUtf8("upload"));
        upload->setMaximumSize(QSize(200, 16777215));
        upload->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:white;\n"
"border: 1px solid black"));

        hbox10_2->addWidget(upload);


        vbox2->addLayout(hbox10_2);


        verticalLayout->addLayout(vbox2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        infoDockWidget->setWidget(infoWidget);
        MainWindow->addDockWidget(Qt::LeftDockWidgetArea, infoDockWidget);
        infoDockWidget_2 = new QDockWidget(MainWindow);
        infoDockWidget_2->setObjectName(QString::fromUtf8("infoDockWidget_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(infoDockWidget_2->sizePolicy().hasHeightForWidth());
        infoDockWidget_2->setSizePolicy(sizePolicy2);
        infoDockWidget_2->setAllowedAreas(Qt::RightDockWidgetArea);
        infoWidget_2 = new QWidget();
        infoWidget_2->setObjectName(QString::fromUtf8("infoWidget_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(infoWidget_2->sizePolicy().hasHeightForWidth());
        infoWidget_2->setSizePolicy(sizePolicy3);
        infoWidget_2->setMinimumSize(QSize(0, 0));
        infoWidget_2->setMaximumSize(QSize(800, 16777215));
        verticalLayout_2 = new QVBoxLayout(infoWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pathName = new QLabel(infoWidget_2);
        pathName->setObjectName(QString::fromUtf8("pathName"));

        verticalLayout_2->addWidget(pathName);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        guid = new QPushButton(infoWidget_2);
        guid->setObjectName(QString::fromUtf8("pushButton"));
        guid->setMinimumSize(QSize(50, 30));
        guid->setMaximumSize(QSize(100, 16777215));
        guid->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:#00aaff;\n"
"border: 1px solid blackrgb(0, 170, 255);\n"
"color:white;"));

        horizontalLayout_2->addWidget(guid);


        verticalLayout_2->addLayout(horizontalLayout_2);

        hbox1_2 = new QHBoxLayout();
        hbox1_2->setSpacing(6);
        hbox1_2->setObjectName(QString::fromUtf8("hbox1_2"));
        label_index_2 = new QLabel(infoWidget_2);
        label_index_2->setObjectName(QString::fromUtf8("label_index_2"));

        hbox1_2->addWidget(label_index_2);

        index_2 = new QLineEdit(infoWidget_2);
        index_2->setObjectName(QString::fromUtf8("index_2"));
        index_2->setStyleSheet(QString::fromUtf8("border-radius:3px"));
        index_2->setReadOnly(true);

        hbox1_2->addWidget(index_2);


        verticalLayout_2->addLayout(hbox1_2);

        hbox2_2 = new QHBoxLayout();
        hbox2_2->setSpacing(6);
        hbox2_2->setObjectName(QString::fromUtf8("hbox2_2"));
        label_name_2 = new QLabel(infoWidget_2);
        label_name_2->setObjectName(QString::fromUtf8("label_name_2"));

        hbox2_2->addWidget(label_name_2);

        name_2 = new QLineEdit(infoWidget_2);
        name_2->setObjectName(QString::fromUtf8("name_2"));
        name_2->setStyleSheet(QString::fromUtf8("border-radius:3px"));
        name_2->setReadOnly(true);

        hbox2_2->addWidget(name_2);


        verticalLayout_2->addLayout(hbox2_2);

        hbox3_2 = new QHBoxLayout();
        hbox3_2->setSpacing(6);
        hbox3_2->setObjectName(QString::fromUtf8("hbox3_2"));
        label_address_2 = new QLabel(infoWidget_2);
        label_address_2->setObjectName(QString::fromUtf8("label_address_2"));

        hbox3_2->addWidget(label_address_2);

        address_2 = new QLineEdit(infoWidget_2);
        address_2->setObjectName(QString::fromUtf8("address_2"));
        address_2->setStyleSheet(QString::fromUtf8("border-radius:3px"));
        address_2->setReadOnly(true);

        hbox3_2->addWidget(address_2);


        verticalLayout_2->addLayout(hbox3_2);

        hbox5_5 = new QHBoxLayout();
        hbox5_5->setSpacing(6);
        hbox5_5->setObjectName(QString::fromUtf8("hbox5_5"));
        label_preparation_2 = new QLabel(infoWidget_2);
        label_preparation_2->setObjectName(QString::fromUtf8("label_preparation_2"));

        hbox5_5->addWidget(label_preparation_2);

        preparation_info_2 = new QLineEdit(infoWidget_2);
        preparation_info_2->setObjectName(QString::fromUtf8("preparation_info_2"));
        preparation_info_2->setStyleSheet(QString::fromUtf8("border-radius:3px"));
        preparation_info_2->setReadOnly(true);

        hbox5_5->addWidget(preparation_info_2);


        verticalLayout_2->addLayout(hbox5_5);

        hbox5_6 = new QHBoxLayout();
        hbox5_6->setSpacing(6);
        hbox5_6->setObjectName(QString::fromUtf8("hbox5_6"));
        label_guid_2 = new QLabel(infoWidget_2);
        label_guid_2->setObjectName(QString::fromUtf8("label_guid_2"));

        hbox5_6->addWidget(label_guid_2);

        guid_info_2 = new QLineEdit(infoWidget_2);
        guid_info_2->setObjectName(QString::fromUtf8("guid_info_2"));
        guid_info_2->setStyleSheet(QString::fromUtf8("border-radius:3px"));
        guid_info_2->setReadOnly(true);

        hbox5_6->addWidget(guid_info_2);


        verticalLayout_2->addLayout(hbox5_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        prev = new QPushButton(infoWidget_2);
        prev->setObjectName(QString::fromUtf8("prev"));
        prev->setMaximumSize(QSize(70, 30));
        prev->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:white;\n"
"border: 1px solid black"));

        horizontalLayout->addWidget(prev);

        next = new QPushButton(infoWidget_2);
        next->setObjectName(QString::fromUtf8("next"));
        sizePolicy.setHeightForWidth(next->sizePolicy().hasHeightForWidth());
        next->setSizePolicy(sizePolicy);
        next->setMaximumSize(QSize(70, 30));
        next->setStyleSheet(QString::fromUtf8("border-radius:5px;\n"
"background-color:white;\n"
"border: 1px solid black"));

        horizontalLayout->addWidget(next);


        verticalLayout_2->addLayout(horizontalLayout);

        vbox1_2 = new QVBoxLayout();
        vbox1_2->setSpacing(6);
        vbox1_2->setObjectName(QString::fromUtf8("vbox1_2"));
        labelPicture_2 = new QLabel(infoWidget_2);
        labelPicture_2->setObjectName(QString::fromUtf8("labelPicture_2"));
        labelPicture_2->setMaximumSize(QSize(16777215, 16777215));
        labelPicture_2->setLayoutDirection(Qt::LeftToRight);

        vbox1_2->addWidget(labelPicture_2);

        Picture_2 = new QLabel(infoWidget_2);
        Picture_2->setObjectName(QString::fromUtf8("Picture_2"));
        Picture_2->setMaximumSize(QSize(16777215, 16777215));

        vbox1_2->addWidget(Picture_2);


        verticalLayout_2->addLayout(vbox1_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        infoDockWidget_2->setWidget(infoWidget_2);
        MainWindow->addDockWidget(Qt::RightDockWidgetArea, infoDockWidget_2);

        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu_2->addAction(about);
        menu_2->addAction(useness);
        menu_3->addAction(user);
        menu_3->addAction(manager);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        about->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        manager->setText(QCoreApplication::translate("MainWindow", "\347\256\241\347\220\206\345\221\230", nullptr));
        user->setText(QCoreApplication::translate("MainWindow", "\347\224\250\346\210\267", nullptr));
        useness->setText(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\346\250\241\345\274\217", nullptr));
        Tips->setText(QString());
        label_index->setText(QCoreApplication::translate("MainWindow", "\345\272\217\345\217\267(\350\276\223\345\205\245\345\272\217\345\217\267\345\271\266\347\224\250\345\233\236\350\275\246\351\224\256\351\200\211\346\213\251):", nullptr));
        label_name->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260:", nullptr));
        label_address->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\235\200:", nullptr));
        label_lon->setText(QCoreApplication::translate("MainWindow", "\347\273\217\345\272\246:", nullptr));
        label_lat->setText(QCoreApplication::translate("MainWindow", "\347\272\254\345\272\246:", nullptr));
        label_preparation->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\274\225\345\257\274\346\263\250\345\206\214\344\277\241\346\201\257:", nullptr));
        label_guid->setText(QCoreApplication::translate("MainWindow", "\346\267\273\345\212\240\345\257\274\350\210\252\344\277\241\346\201\257:", nullptr));
        labelPicture->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207", nullptr));
        clearImage->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244", nullptr));
        selectPicture->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251", nullptr));
        Picture->setText(QString());
        confirmButton->setText(QCoreApplication::translate("MainWindow", "\347\241\256\345\256\232", nullptr));
        cancelButton->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
        createMapButton->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\350\267\257\347\272\277", nullptr));
        editMapButton->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\350\267\257\347\272\277", nullptr));
        continueAdd->setText(QCoreApplication::translate("MainWindow", "\347\273\247\347\273\255\346\267\273\345\212\240", nullptr));
        upload->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\274\240", nullptr));
        pathName->setText(QString());
        guid->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\345\257\274\350\210\252", nullptr));
        label_index_2->setText(QCoreApplication::translate("MainWindow", "\345\272\217\345\217\267:", nullptr));
        label_name_2->setText(QCoreApplication::translate("MainWindow", "\345\220\215\347\247\260:", nullptr));
        label_address_2->setText(QCoreApplication::translate("MainWindow", "\345\234\260\345\235\200:", nullptr));
        label_preparation_2->setText(QCoreApplication::translate("MainWindow", "\346\263\250\345\206\214\344\277\241\346\201\257:", nullptr));
        label_guid_2->setText(QCoreApplication::translate("MainWindow", "\345\257\274\350\210\252\344\277\241\346\201\257:", nullptr));
        prev->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\344\270\252", nullptr));
        next->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
        labelPicture_2->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207", nullptr));
        Picture_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

