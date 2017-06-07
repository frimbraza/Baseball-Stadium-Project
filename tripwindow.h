#ifndef TRIPWINDOW_H
#define TRIPWINDOW_H

#include <QDialog>

namespace Ui {
class TripWindow;
}

class TripWindow : public QDialog
{
    Q_OBJECT

public:
    explicit TripWindow(QWidget *parent = 0);
    ~TripWindow();

private:
    Ui::TripWindow *ui;
};

#endif // TRIPWINDOW_H
