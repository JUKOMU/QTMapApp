#ifndef PATH_H
#define PATH_H

#include <QObject>
#include <QVector>
#include <QImageReader>
#include <QImage>
#include <QPixmap>
#include <QBuffer>
#include <QByteArray>
#include <QFileInfo>
#include "database.h"

using namespace std;
class Path
{
public:
    Path();
    Path(QString name);
    ~Path();

    void setName(QString name);

    /* 将点、信息和图片都按顺序排列存储,被构造函数调用 */
    void loadPoints();
    void loadNameAddressOfPoints();
    void loadInfo();
    void loadImage();
    /* 获取点、信息和图片的集合 */
    QVector<pair<QString,QString>> *getPoints();
    QVector<pair<QString,QString>> *getNameAddressOfPoints();
    QVector<pair<QString,QString>> *getInfo();
    QVector<QPixmap> *getImages();
    int getId();
    int getNumber();
    /* 存储点、信息和图片的集合 */
    void setPoints(QVector<pair<QString,QString>> *points);
    void setNameAddressOfPoints(QVector<pair<QString,QString>> *nameAddressOfPoints);
    void setInfo(QVector<pair<QString,QString>> *info);
    void setImages(QVector<QString> *images);

    bool uploadPath(int number);
private:
    int number;
    Database *db;
    int id;
    QString name;
    QVector<pair<QString,QString>> *points;
    QVector<pair<QString,QString>> *nameAddressOfPoints;
    QVector<pair<QString,QString>> *info;
    QVector<QPixmap> *images;
    QVector<QString> *imagePath;
};

#endif // PATH_H
