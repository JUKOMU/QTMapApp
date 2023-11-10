#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWebEngineView>
#include<QtWebEngineWidgets/QWebEngineView>
#include <QWebChannel>
#include <QNetworkProxyFactory>
#include <QDebug>
#include <QVector>
#include <QDialog>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QScrollArea>
#include <QImageReader>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QPushButton>
#include <QLineEdit>
#include "database.h"
#include "path.h"
#include <QListView>
#include <QStringList>
#include <QStringListModel>
#include <QCompleter>
#include <QTest>
#include <QTimer>
#include<QDebug>
#include <QString>
#include <QDir>
#include <QWebChannel>

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QWebEngineView *m_view;
    QWebChannel *channel;

    enum Login{UserLogin,ManagerLogin};
    enum statusMode{createMap,editMap,navigationMap,continueAddMap};

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void selectLoginMode(Login LoginMode); // 登录方式
    void updateInterface(statusMode mode); // 控制按钮状态
    void fresh();

    void drawMap();


signals:
    void sigYourName(const QString &name);
public slots:
    void on_user_triggered();
    void on_manager_triggered();

    void getYourName();

    void selectPoit(QString index);

    //void getCoordinate(QString lon,QString lat);

    // 存储地点信息 if mode == 1, QString name,QString address
    void storeInfo(QString mode,QString lon,QString lat);

    void showInfo(int index);

private slots:
    void createMode();

    void editMode();

    void navigateMode();

    void continueAdd();

    void confirm();

    void cancel();

    void selectPicture(QString filePath = " ");

    void clearImage();

    void showImage(QString filePath);

    void submit();

    /*
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
*/
private:
    Ui::MainWindow *ui;
    QDialog *rewriteInfo;
    QPushButton *search_btn;
    QLineEdit *search_edit;

    int times = 0;
    int i = 0;

    bool upload;

    QString Mode;
    bool continueAddStatus;

    QVector<pair<QString,QString>> *lon_lat_map; // 存储经纬度
    QVector<pair<QString,QString>> *name_address_map; // 存储名称地址
    QVector<pair<QString,QString>> *info; // 存储注册和导航信息
    QVector<QString> *imagePath; // 存储图像位置,提交数据库时将图像从原位置复制到文件夹，名称与点的序号匹配(减少存储的字段)
    QVector<QPixmap> *images;
    int number; // 存储个数

    // 用来恢复编辑前的点
    QString old_name;
    QString old_address;
    QString old_lon;
    QString old_lat;
    QString old_preparation;
    QString old_guidance;
    QString old_image;

    // 图片
    QScrollArea *scrollArea;

    Database *db;

    Path *path;
};

#endif // MAINWINDOW_H

