#include "mainwindow.h"

#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/image/Resource/icon_1.png"));
    MainWindow w;
    w.show();
    w.start();
    return a.exec();
}
