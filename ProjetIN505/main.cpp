#include "mainwindow.h"
#include <QApplication>
#include "Rock.h"
#include<QRect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Rock* r= new Rock();
    QRect* rect= r->printQTRock();

    w.show();

    return a.exec();
}
