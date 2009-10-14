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

#include "daybutton.h"


dayButton::dayButton(QWidget * parent, int jd, bool showGDate, bool hool)
{
    setParent(parent);

    setDate(jd, hool);


    vbox = new QVBoxLayout();
    setLayout(vbox);

    hbox = new QHBoxLayout();

    vbox->addLayout(hbox);

    //hebday = new QLabel(date.get_hebrew_day_string());
    hebday = new QLabel();

    engday = new QLabel("");
    /*
    if (showGDate)
    {
        engday->setText(stringify(date.get_gday()));
    }
    */


    hbox->addWidget(hebday);
    hbox->addStretch(1);

    hbox->addWidget(engday);

    /*
    QString holiday = date.get_holyday_string(0);
    //No politics or anything, these are just not holidays...
    if (holiday == "יום הזכרון ליצחק רבין" || holiday == "יום המשפחה" || holiday == "יום זאב זבוטינסקי" ) holiday = "";

    //event = new QLabel(holiday);
    */
    event = new QLabel();
    vbox->addWidget(event);
    event->setAlignment(Qt::AlignCenter);

    reading = new QLabel();

    //if (QString(date.get_parasha_string(0)) != "חסר") reading->setText(date.get_parasha_string(0));

    vbox->addWidget(reading);
    reading->setAlignment(Qt::AlignCenter);

    setLayoutDirection(Qt::RightToLeft);

    vbox->addStretch(1);
    vbox->setSpacing(7);

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);


    showInfo(showGDate);
}

dayButton::~dayButton()
{
    delete hebday;
    delete engday;
    delete event;
    delete reading;

    delete hbox;
    delete vbox;
}

void dayButton::setDate(int jd, bool hool)
{
    date.set_jd(jd);

    //
    if (hool) date.set_diaspora();

    selected = false;
    today = false;

    updateStyle();
}


void dayButton::showInfo(bool showGDate)
{
    hebday->setText(date.get_hebrew_day_string());

    if (showGDate)
    {
        engday->setText(stringify(date.get_gday()));
    }


    QString holiday = date.get_holyday_string(0);
    //No politics or anything, these are just not holidays...
    if (holiday == "יום הזכרון ליצחק רבין" || holiday == "יום המשפחה" || holiday == "יום זאב זבוטינסקי" ) holiday = "";

    event->setText(holiday);

    if (QString(date.get_parasha_string(0)) != "חסר") reading->setText(date.get_parasha_string(0));
}

void dayButton::resetDate(int jd, bool hool, bool showGDate)
{
    setDate(jd, hool);
    showInfo(showGDate);

    //Unmark "today"
    QFont q; q.setPixelSize(16);
    hebday->setFont(q);
    engday->setFont(q);

    updateStyle();
}

void dayButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked(this);
    }
}

void dayButton::Select()
{
    selected = true;
    updateStyle();
}

void dayButton::Unselect()
{
    selected = false;
    updateStyle();
}

void dayButton::setToday()
{
    QFont q; q.setBold(true); q.setPixelSize(17);
    hebday->setFont(q);
    engday->setFont(q);
    
    today = true;
    updateStyle();
}


#define unselectedcolor "#EEFFEE;";
#define selectedcolor "#BBBBFF;";
#define bordercolor "#BBBBFF;";
#define hovercolor "#B3CCFF;";

//Updates the style sheet (changes the color if selected, etc')
void dayButton::updateStyle()
{
    QString basecolor = "";

    //Base color changes if the day's selected
    if (!selected)
    {
        basecolor += unselectedcolor;
    }
    else basecolor += selectedcolor;


    QString str =
            "dayButton { "
            "background-color:";
    str +=  basecolor;

    str +=
            "border-radius: 10px; "
            "border-style: solid;"
            "border-color:";
    str +=  bordercolor;
    str +=
            "border-width:3px;"
            "} " ;
    str +=
            "dayButton:hover { "
            "background-color:";
    str +=  hovercolor;
    str +=
            "border-color:";
    str +=  hovercolor;
    str +=
            "} ";

    setStyleSheet(str);
}

hdate::Hdate *dayButton::getHDate() { return &date; }
