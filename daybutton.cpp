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

QFont sfs, fs, fb;

dayButton::dayButton(QWidget * parent, int jd, bool showGDate, bool hool)
{

    setParent(parent);

    setDate(jd, hool);

    sfs.setPixelSize(11);
    fs.setPixelSize(13);
    fb.setPixelSize(15);


    vbox = new QVBoxLayout();
    setLayout(vbox);

    hbox = new QHBoxLayout();

    vbox->addLayout(hbox);

    //hebday = new QLabel(date.get_hebrew_day_string());
    hebday = new QLabel();
    hebday->setStyleSheet("QLabel { color: purple }");


    engday = new QLabel();


    engday->adjustSize();

    hbox->addWidget(hebday);


    hbox->addStretch(1);

    omer =  new QLabel();
    omer->hide();
    omer->setFont(sfs);


    hbox->addWidget(omer);

    hbox->addStretch(1);

    hbox->addWidget(engday);


    event = new QLabel();
    vbox->addWidget(event);
    event->setAlignment(Qt::AlignCenter);
    event->setFont(fs);


    reading = new QLabel();
    reading->setFont(fs);
    reading->setStyleSheet("QLabel { color: brown }");

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

    ishool = hool;
    if (hool) date.set_diaspora();
    else date.set_israel();

    selected = false;
    today = false;

    updateStyle();
}


void dayButton::showInfo(bool showGDate)
{
    hebday->setText(QString(date.get_hebrew_day_string()).replace("'","").replace("\"",""));

    if (showGDate)
    {
        engday->setText(stringify(date.get_gday()));
        engday->show();
    }
    else engday->hide();


    if (date.getOmerDay() != 0)
    {
        omer->show();
        omer->setText(NumberToGematria(date.getOmerDay()) + " בעומר");
    }
    else
    {
        omer->hide();
        omer->setText("");
    }

    QString holiday = date.get_holyday_string(0);

    //No politics or anything, these are just not holidays...
    if (date.holidayType() == 9) holiday = "";

    //Add number to hol hamoed
    if (date.holidayType() == 3)
    {
        int d = date.get_hday() - 15;

        //Hol hamoed starts a day late in hool
        if (ishool) d--;

        //Besides hoshana raba
        if (date.get_hmonth() == 1 && date.get_hday() == 21) d = 0;

        if (d > 0) holiday = NumberToGematria(d, false) + " " + holiday;
    }

    //Hanuka
    if (date.holidayType() == 4 && (date.get_hmonth() == 3 || date.get_hmonth() == 4))
    {
        hdate::Hdate t;
        t.set_hdate(25, 3, date.get_hyear());
        int d = date.get_julian() - t.get_julian() + 1;

        if (d > 0) holiday = NumberToGematria(d, false) + " " + holiday;
    }

    event->setText(holiday);

    if (QString(date.get_parasha_string(0)) != tr("none")) reading->setText(date.get_parasha_string(0));
    else reading->setText("");
}

void dayButton::resetDate(int jd, bool hool, bool showGDate)
{
    setDate(jd, hool);
    showInfo(showGDate);

    //Unmark "today"
    hebday->setFont(fb);
    engday->setFont(fb);

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
    QFont q; q.setBold(true); q.setPixelSize(15);
    hebday->setFont(q);
    engday->setFont(q);
    
    today = true;
    updateStyle();
}

QSize dayButton::sizeHint() const
{
  return (QSize(0,0));
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
