#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QProcess>
#include <QTextCodec>
#include <iostream>
#include "daybutton.h"
#include "functions.h"
#include "mhdate.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_doublebackYearBTN_clicked();
    void on_doublenextYearBTN_clicked();
    void on_nextDayBTN_clicked();
    void on_backDayBTN_clicked();
    void on_nextYearBTN_clicked();
    void on_backYearBTN_clicked();
    void on_nextMonthBTN_clicked();
    void on_backMonthBTN_clicked();

    void clearMonth();
    void showMonth(Hdate *firstday);

    void readFromStdout();

    void dayClicked(dayButton * day);

    void nextDay();
    void backDay();

    void redraw();


private:
    mHdate current;
    
    //int currentHDay;
    //int currentHMonth;
    //int currentHYear;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
