#include "path.h"

Path::Path(){
    this->db = new Database;
    this->points = new QVector<pair<QString,QString>>;
    this->info = new QVector<pair<QString,QString>>;
    this->images = new QVector<QPixmap>;
}

Path::Path(QString name){
    this->name = name;
    this->db = new Database;
    this->id = db->getId (name);
    this->number = db->getNumber (id);
    this->points = new QVector<pair<QString,QString>>;
    this->info = new QVector<pair<QString,QString>>;
    this->images = new QVector<QPixmap>;
    loadPoints();
    loadNameAddressOfPoints ();
    loadInfo();
    loadImage();
}
Path::~Path (){
}

void Path::setName(QString name){
    this->name = name;
    qDebug()<<name;
    this->id = db->getId (name);
    qDebug()<<id;
    this->number = db->getNumber (id);
    qDebug()<<number;
    loadPoints();
    loadNameAddressOfPoints ();
    loadInfo();
    loadImage();
}

int Path::getId(){
    return id;
}
int Path::getNumber(){
    return number;
}
/* 将点、信息和图片都按顺序排列存储,被构造函数调用 */
void Path::loadPoints(){
    this->points = db->getPoint (id);
    qDebug()<<"1";
}
void Path::loadNameAddressOfPoints(){
    this->nameAddressOfPoints = db->getNameAddress (id);
        qDebug()<<"2";
}
void Path::loadInfo(){
    this->info = db->getInfo (id);
    qDebug()<<"3";
}
void Path::loadImage(){
    QVector<QString> *list = db->getImage (id);
    for (int i = 0; i < list->length (); ++i) {
        QString p_b = (*list)[i];//base64字符串
        QPixmap image;
        image.loadFromData(QByteArray::fromBase64(p_b.toLocal8Bit()));
        this->images->push_back (image);
    }
        qDebug()<<"4";
}
/* 获取点、信息和图片的集合 */
QVector<pair<QString,QString>> *Path::getPoints(){
    qDebug()<<"points";
    return points;
}
QVector<pair<QString,QString>> *Path::getNameAddressOfPoints(){
    qDebug()<<"NameAddressOfPoints";
    return nameAddressOfPoints;
}
QVector<pair<QString,QString>> *Path::getInfo(){
    qDebug()<<"Info";
    return info;
}
QVector<QPixmap> *Path::getImages(){
    qDebug()<<"Images";
    return images;
}
/* 存储点、信息和图片的集合 */
void Path::setPoints(QVector<pair<QString,QString>> *points){
    this->points = points;
}
void Path::setNameAddressOfPoints(QVector<pair<QString,QString>> *nameAddressOfPoints){
    this->nameAddressOfPoints = nameAddressOfPoints;
}
void Path::setInfo(QVector<pair<QString,QString>> *info){
    this->info = info;
}
void Path::setImages(QVector<QString> *images){
    this->imagePath = images;
    for (int i = 0;i < images->length ();i++){
        QString filepath = (*images)[i];
        QPixmap p;
        p.load (filepath);
        this->images->push_back (p);
    }
}

bool Path::uploadPath(int number){
    bool flag = true;
    db->insertNewpath (name);
    id = db->getId (name);
    for (int i = 0;i < number;i++){
        //qDebug()<<"path";
        try {
            QImage image((*imagePath)[i]);
            QByteArray ba;
            QBuffer buf(&ba);
            image.save(&buf, "png");
            //qDebug() << ba.toBase64();

            db->insertNewPathPoint (id,i+1,(*nameAddressOfPoints)[i].first,(*nameAddressOfPoints)[i].second,(*points)[i],(*info)[i],ba.toBase64());
            buf.close();
        } catch (...) {
            flag = false;
            return flag;
        }
    }
    return flag;
}
