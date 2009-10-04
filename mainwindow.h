/* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2
* as published by the Free Software Foundation.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Author: Moshe Wagner. <moshe.wagner@gmail.com>
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QProcess>
#include <QTextCodec>
#include <QTime>
#include <QDir>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

#include <locale.h>

#include "mhdate.h"

#include "daybutton.h"
#include "functions.h"
#include "changelocation.h"
#include "about.h"

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

    void on_doublenextgYearBTN_clicked();
    void on_doublebackgYearBTN_clicked();
    void on_nextgYearBTN_clicked();
    void on_backgYearBTN_clicked();
    void on_nextgmonthBTN_clicked();
    void on_backgmonthBTN_clicked();
    void on_nextgdayBTN_clicked();
    void on_backgdayBTN_clicked();
    void on_dockWidget_visibilityChanged(bool visible);
    void on_doublebackYearBTN_clicked();
    void on_doublenextYearBTN_clicked();
    void on_nextDayBTN_clicked();
    void on_backDayBTN_clicked();
    void on_nextYearBTN_clicked();
    void on_backYearBTN_clicked();
    void on_nextMonthBTN_clicked();
    void on_backMonthBTN_clicked();

    //Destroys all existing daybuttons
    void clearMonth();
    
    //Rebuild the calendar from the given first day of the month
    void showMonth(hdate::Hdate *dayinmonth);

    void dayClicked(dayButton * day);

    void changeDay(int i);

    void redraw();

    void saveConfs();
    void saveDispConfs();
    void loadConfs();

    void toggleGDate(bool show);
    void toggleZmanimPanel(bool show);

    void updateLabels(mHdate *date);

    void gotTimes();

    //Show change location form
    void changeLocationForm();
    void aboutForm();

    void printSnap();
private:
    //Holds current (selected) date
    mHdate current;

    //Deals with keyboard events
    void keyPressEvent( QKeyEvent *keyEvent );


    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
