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


/*
  Widget representing a day in the calendar;

  Shows the hebrew date, english date, reading, and event.


  Changes color by state - Unslected, Selected, and MouseOver.


  Emmits a "clicked" signal when clicked (duh).

*/

#ifndef DAYBUTTON_H
#define DAYBUTTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QFrame>
#include <QLayout>
#include <QLabel>

#include <hdatepp.h>

#include "functions.h"

class dayButton : public QFrame
{
        Q_OBJECT

public:
    dayButton(QWidget * parent, int jd, bool showGDate, bool hool);
    ~dayButton();

    void resetDate(int jd, bool hool, bool showGDate);

private:
    hdate::Hdate date;

    void setDate(int jd, bool hool);
    void showInfo(bool showGDate);

    bool selected;
    bool today;

    //Updates the style sheet (changes the color if selected, etc')
    void updateStyle();

    //Widgets:
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QLabel *hebday, *engday, *event, *reading;

public slots:
    void Select();
    void Unselect();
    void setToday();

    hdate::Hdate *getHDate();

private slots:
    void mousePressEvent(QMouseEvent *event);

signals:
    void clicked(dayButton *);
};

#endif // DAYBUTTON_H
