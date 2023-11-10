#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QMessageBox>
#include <QSettings>
#include <QSqlError>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QBuffer>
#include <QVector>
#include <QByteArray>

using namespace std;
class Database
{
public:
    Database();
    ~Database();
    /* 创建 */
    void create_database();
    /* 查询 */
    int getId(QString name); // 获取pathId
    int getNumber(int id);
    QVector<QString> findPath(QString name); // 包含name的路径名
    QVector<pair<QString,QString>> *getNameAddress(int pathId); // 获取点的name和address
    QVector<pair<QString,QString>> *getPoint(int pathId);
    QVector<pair<QString,QString>> *getInfo(int pathId);
    QVector<QString> *getImage(int pathId);
    /* 插入数据 */
    void insertNewpath(QString pathName);
    void insertNewPathPoint(int pathId,int order,QString name,QString address,pair<QString,QString> point,pair<QString,QString> info,QByteArray  image);
    void updatePath(int pathId,int order,QString name,QString address,pair<QString,QString> point,pair<QString,QString> info,QByteArray  image);
    /* 删除 */
    bool deletePath(int id);
    bool deleteAll();

private:
    QSqlDatabase db;
};

#endif // DATABASE_H
