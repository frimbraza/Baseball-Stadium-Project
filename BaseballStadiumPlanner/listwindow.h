#ifndef LISTWINDOW_H
#define LISTWINDOW_H

#include <QDialog>
// #include "mainwindow.h" // remember you added this. Should remove later
#include <string>

namespace Ui {
class ListWindow;
}

class ListWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ListWindow(QWidget *parent = 0);
    ~ListWindow();

    void setAllStadiumsString(std::string input);

private slots:
    void on_listAllStadiums_clicked();

    void on_listAmLeagueStadiums_clicked();

    void on_listNLStadiums_clicked();

    void on_ListGrassStadiums_clicked();

    void on_ListChronologicalStadium_clicked();

private:
    Ui::ListWindow *ui;
    std::string AllStadInfo;
    std::string AmStadInfo;
    std::string NlStadInfo;
    std::string grassStadInfo;

};

#endif // LISTWINDOW_H
