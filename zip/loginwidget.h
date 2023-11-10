#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QImage>
#include <QImageReader>
#include <QPainter>
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QStyle>
#include <QStyleOption>
#include <QMouseEvent>
#include <QTimer>
#include "mainwindow.h"

class LoginWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();
    void paintEvent(QPaintEvent* event);

signals:
public slots:
    void windowclosed();//最小化 关闭
    void windowmin();
    void winmax();
    void userLogin();
    void managerLogin();

private:
    int times;
    int i;
    QPoint clickPos;
    QPixmap maxPix;
    QPixmap restore;
    QToolButton *minButton;
    QToolButton *maxButton;
    QToolButton *closeButton;
protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
};

#endif // LOGINWIDGET_H
