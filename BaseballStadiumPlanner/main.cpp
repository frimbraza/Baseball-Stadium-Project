/*
* Main window class file
* 
* returns executable
* 
* main class file
*
*/

#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();


}
