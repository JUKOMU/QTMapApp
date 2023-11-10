#include "database.h"

Database::Database(){
    create_database();
}

Database::~Database (){
}

// 创建数据库,连接数据库
void Database::create_database()
{
    QSqlDatabase db;
    // 避免重复连接数据库
    if(QSqlDatabase::contains("qt_sql_default_connection")) {
        db = QSqlDatabase::database("qt_sql_default_connection");
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("E:\\SqlLite\\DB\\database1.db");     // 设置数据库名称
    }

    if(!db.open()) {
        qDebug() << "database open error：" << db.lastError();;
    } else{
        qDebug() << "database ok!";
    }


    QSqlQuery query(db);

    // 只记录，用于查询表格pathInfo
    if(db.tables().contains("paths")) {
        //qDebug() << "table users already exists!";
    } else {
        // 表格不存在，则创建表格paths
        QString C = "create table paths("
                      "id INTEGER PRIMARY KEY NOT NULL,"
                      "path_name VARCHAR(100) NOT NULL);";
        if(!query.exec(C)) {
            qDebug() << "create users table error!";
        }
    }

    // path信息
    if(db.tables().contains("pathInfo")) {
        //qDebug() << "table images already exists!";
    } else {
        // 表格不存在，则创建表格pathInfo
        QString C = "create table pathInfo("
                      "id INTEGER PRIMARY KEY NOT NULL,"
                      "path_id int NOT NULL,"
                      "order_of_point int NOT NULL,"
                      "name VARCHAR(50),"
                      "address VARCHAR(100),"
                      "preparation_info VARCHAR(200),"
                      "guid_info VARCHAR(200),"
                      "lon VARCHAR(30) NOT NULL,"
                      "lat VARCHAR(30),"
                      "image BLOB)";
        if(!query.exec(C))
        {
            qDebug() << "create pathInfo table error!";
        }
    }
}

/* 查询 */
// 获取id
int Database::getId(QString name){
    int id = -1;
    QSqlQuery query;//执行查询语句
    // 查询
    QString S = QString("select * from paths WHERE path_name = '%0'").arg (name);
    query.exec(S);
    while (query.next()) {
        id = query.value (0).toString ().toInt ();
        return id;
    }
    return id;
}
int Database::getNumber(int id){
    int number = 0;
    QSqlQuery query;//执行查询语句
    // 查询
    QString S = QString("select * from pathInfo WHERE path_id = '%0'").arg (id);
    query.exec(S);
    while (query.next ()) {
        number++;
    }
    return number;
}

 // 包含name的路径名,模糊查询
QVector<QString> Database::findPath(QString name){
    QVector<QString> pathList;
    QSqlQuery query;
    QString S = QString("select * from paths WHERE path_name GLOB '*%0*'").arg (name);
    query.exec (S);
    while (query.next ()) {
        pathList.push_back (QString(query.value (1).toString ()));
    }
    return pathList;
}

// 获取点的name和address
QVector<pair<QString,QString>> *Database::getNameAddress(int pathId){
    QVector<pair<QString,QString>> *list = new QVector<pair<QString,QString>>;
    QSqlQuery query;
    QString S = QString("select * from pathInfo WHERE path_id = '%0'").arg (pathId);
    query.exec (S);
    while (query.next ()) {
        list->push_back (pair(QString(query.value (3).toString ()),QString(query.value (4).toString ())));
    }
    return list;
}

QVector<pair<QString,QString>> *Database::getPoint(int pathId){
    QVector<pair<QString,QString>> *list = new QVector<pair<QString,QString>>;
    QSqlQuery query;
    QString S = QString("select * from pathInfo WHERE path_id = '%0'").arg (pathId);
    query.exec (S);
    while (query.next ()) {
        list->push_back (pair(QString(query.value (7).toString ()),QString(query.value (8).toString ())));
    }
    return list;
}

QVector<pair<QString,QString>> *Database::getInfo(int pathId){
    QVector<pair<QString,QString>> *list = new QVector<pair<QString,QString>>;
    QSqlQuery query;
    QString S = QString("select * from pathInfo WHERE path_id = '%0'").arg (pathId);
    query.exec (S);
    while (query.next ()) {
        list->push_back (pair(QString(query.value (5).toString ()),QString(query.value (6).toString ())));
    }
    return list;
}
QVector<QString> *Database::getImage(int pathId){
    QVector<QString> *list = new QVector<QString>;
    QSqlQuery query;
    QString S = QString("select * from pathInfo WHERE path_id = '%0'").arg (pathId);
    query.exec (S);
    while (query.next ()) {
        list->push_back (query.value(9).toString());
    }
    return list;
}

/* 插入数据 */
void Database::insertNewpath(QString pathName){
    // 检测是否已存在
    QSqlQuery query;
    QString S = QString("select * from paths WHERE path_name = '%0'").arg (pathName);
    query.exec (S);
    while (query.next ()) {
        qDebug()<<"s";
        return;
    }
    qDebug()<<"i";
    QString I = QString("insert into paths values(null,'%1')").arg(pathName);
    query.prepare (I);
    query.exec();
}
void Database::insertNewPathPoint(int pathId,int order_of_point,QString name,QString address,pair<QString,QString> point,pair<QString,QString> info,QByteArray image){
    // 检测是否已存在
    QSqlQuery query;
    QString S = QString("select * from pathInfo WHERE path_id = '%0' AND order_of_point = '%1'").arg (pathId).arg (order_of_point);
    query.exec (S);
    while (query.next ()) {
        return;
    }
    qDebug()<<"point";
    QString I = QString("insert into pathInfo values(null,'%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', :img)")
                    .arg(pathId)
                    .arg(order_of_point)
                    .arg(name)
                    .arg(address)
                    .arg(info.first)
                    .arg(info.second)
                    .arg(point.first)
                    .arg(point.second);
    query.prepare (I);
    query.bindValue (":img",image);
    query.exec();
}

void Database::updatePath(int pathId,int order_of_point,QString name,QString address,pair<QString,QString> point,pair<QString,QString> info,QByteArray image){
    QSqlQuery query;
    QString U = QString("update pathInfo set name = '%0', address = '%1', preparation_info = '%2', guid_info = '%3', lon = '%4', lat = '%5', image = ? WHERE path_id = '%6' AND order_of_point = '%7'")
                    .arg(name)
                    .arg(address)
                    .arg(info.first)
                    .arg(info.second)
                    .arg(point.first)
                    .arg(point.second)
                    .arg(pathId)
                    .arg(order_of_point);

    query.prepare (U);
    query.addBindValue (image);
    query.exec();
}

/* 删除 */
bool Database::deletePath(int id){
    QSqlQuery query;
    QString D1 = QString("DELETE FROM paths WHERE id = '%0'").arg (id);
    QString D2 = QString("DELETE FROM paths WHERE path_id = '%0'").arg (id);
    if (query.exec(D1) && query.exec(D2)){
        return true;
    }
    return false;
}
bool Database::deleteAll(){
    QSqlQuery query;
    if (query.exec("DELETE FROM pathInfo") && query.exec("DELETE FROM paths")){
        return true;
    }
    return false;
}
