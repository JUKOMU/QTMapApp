#include "loginwidget.h"//.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWidget *loginwidget = new LoginWidget;
    loginwidget->show ();
    return a.exec();
}
