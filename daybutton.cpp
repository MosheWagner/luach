#include "daybutton.h"

dayButton::dayButton(QWidget * parent, int jd)
{
    date.set_jd(jd);

    selected = false;
    today = false;

    updateStyle();

    vbox = new QVBoxLayout();
    setLayout(vbox);

    hbox = new QHBoxLayout();

    vbox->addLayout(hbox);

    hebday = new QLabel(stringify(date.get_gday()));
    engday = new QLabel(date.get_hebrew_day_string());

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
    today = true;
    updateStyle();
}

void dayButton::updateStyle()
{
    QString basecolor = "";

    if (today) basecolor = "pink; ";
    else
    {
        if (!selected) basecolor += "#F2F5A9;";
        else basecolor += "#FFFF33;";
    }


    QString str =
            "dayButton { "
            "background-color:";
    str +=  basecolor;

    str +=
            "border-radius: 3px; "
            "} " ;
    str +=
            "dayButton:hover { "
            "background-color: #FFFF33; "
            "} ";

    setStyleSheet(str);
}

Hdate *dayButton::getHDate() { return &date; }
