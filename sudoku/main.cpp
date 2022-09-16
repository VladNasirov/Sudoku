#include "mainwindow.h"

#include <QApplication>
#include "Tablet.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    grid A;
    A.Print();
    A.TransposeTable();
    A.Print();
    return a.exec();
}
