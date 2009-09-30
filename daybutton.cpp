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

dayButton::dayButton(QWidget * parent, int jd, bool showGDate)
{
    date.set_jd(jd);

    selected = false;
    today = false;

    updateStyle();

    vbox = new QVBoxLayout();
    setLayout(vbox);

    hbox = new QHBoxLayout();

    vbox->addLayout(hbox);

    hebday = new QLabel(date.get_hebrew_day_string());

    engday = new QLabel("");
    if (showGDate)
    {
        engday->setText(stringify(date.get_gday()));
    }


    hbox->addWidget(hebday);
    hbox->addStretch(1);

    hbox->addWidget(engday);

    QString holiday = date.get_holyday_string(0);
    //No politics or anything, these are just not holidays...
    if (holiday == "יום הזכרון ליצחק רבין" || holiday == "יום המשפחה" || holiday == "יום זאב זבוטינסקי" ) holiday = "";
    event = new QLabel(holiday);
    vbox->addWidget(event);

    reading = new QLabel();
    if (QString(date.get_parasha_string(0)) != "חסר") reading->setText(date.get_parasha_string(0));
    vbox->addWidget(reading);

    setLayoutDirection(Qt::RightToLeft);

    vbox->addStretch(1);
    vbox->setSpacing(7);

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
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


void dayButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit clicked(this);
        //setStyleSheet(style(checked));
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


void dayButton::updateStyle()
{
    QString selcolor = "#BBBBFF;";

    QString basecolor = "";

    //if (today) basecolor = "#CCFFFF; ";
    //else
    //{
        if (!selected) basecolor += "#EEFFEE;";
        else basecolor += selcolor;
    //}


    QString str =
            "dayButton { "
            "background-color:";
    str +=  basecolor;

    str +=
            "border-radius: 10px; "
            "border-style: solid;"
            "border-color:#BBBBFF;"
            "border-width:3px;"
            "} " ;
    str +=
            "dayButton:hover { "
            "background-color: #99CCFF;"
            "border-color: #99CCFF;"
            "} ";

    setStyleSheet(str);
}

Hdate *dayButton::getHDate() { return &date; }
