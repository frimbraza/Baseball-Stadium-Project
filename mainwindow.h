#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "binarytree.h"
#include "stadiuminfo.h"

struct Souvenir
{
private:
    string name;
    double price;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // Fix these up to be compatible with the GUI
    BinaryTree<StadiumInfo> sortByTeamName();
    BinaryTree<StadiumInfo> sortByStadiumName();
    BinaryTree<StadiumInfo> sortByDate();

    void grassList();
    void alList();
    void nlList();

private:
    Ui::MainWindow *ui;
    BinaryTree<StadiumInfo> stadiumList;


};

#endif // MAINWINDOW_H
