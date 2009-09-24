#include "mainwindow.h"
#include "ui_mainwindow.h"

/*

  Kaluach clone:

  Should have some day:

    - Build basic "calandar" like interface ( custom widget )
        - Hebrew / English date
        - Change date, location, timezone
        - Events?
    - Connect to "ZmanimCLI"
    - Daf yomi (shiftan?), eventually add other "yomi" stuff
    - Print snapshots?

    - Other cool features of course

*/

//OK, clean all this mess up...


QProcess *proc;

#include <iostream>
#include <hdatepp.h>
#include <locale.h>


using namespace std;
using namespace hdate;

QList <dayButton *> dayList;
dayButton * lastselected;

QStringList weekdays;
QStringList engmonths;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set all QString to work with unicode
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));

    connect( &current, SIGNAL(month_changed()), this, SLOT(redraw()));


    weekdays << "ראשון" << "שני" << "שלישי" << "רביעי" << "חמישי" << "שישי" << "שבת";

    engmonths << "ינואר" << "פברואר" << "מרס" << "אפריל" << "מאי" << "יוני" << "יולי" << "אוגוסט" << "ספטמבר" << "אוקטובר" << "נובמבר" << "דצמבר";
    
    lastselected = NULL;

    //Force the locale to hebrew, so Hdate will give Hebrew strings. I don't like this.
    // TODO: test on windows
    setlocale (LC_ALL, "he_IL.UTF-8");
    
    //Add weekday labels
    for (int i=0; i<7; i++)
    {
        QLabel *lbl = new QLabel(weekdays[i]);
        lbl->setLayoutDirection(Qt::RightToLeft);
        lbl->setAlignment(Qt::AlignCenter);
        ui->gridLayout->addWidget(lbl, 0, i);

        QFont q; q.setBold(true); q.setPixelSize(20);
        lbl->setFont(q);
        //lbl->setStyleSheet("QLabel { background-color: blue }");
        //lbl->setBackgroundRole(QPalette::Highlight);
    }

    //A defualt Hdate class has today's date
    Hdate today, d;

    current.set_hd(today.get_hday(), today.get_hmonth(), today.get_hyear());

    d.set_hdate(1, today.get_hmonth(), today.get_hyear());
    showMonth(&d);
}

void MainWindow::showMonth(Hdate *firstday)
{
    clearMonth();

    //A defualt Hdate class has today's date
    Hdate today;

    ui->monthlabel->setText(firstday->get_hebrew_month_string(0));
    ui->yearlabel->setText(firstday->get_hebrew_year_string());

    ui->daylabel->setText(current.get_hebrew_day_string());

    ui->engdaylbl->setText(stringify(current.get_gday()));


    ui->engmonthlbl->setText(engmonths[current.get_gmonth() - 1]);
    ui->engyearlbl->setText(stringify(current.get_gyear()));
    
    ui->hmonthlbl->setText(firstday->get_hebrew_month_string(0));

    
    QString gmonths = engmonths[current.get_gmonth() - 1];
    Hdate e;
    e.set_hdate(current.getMonthLength(), current.get_hmonth(), current.get_hyear());
    if (engmonths[e.get_gmonth()-1] != gmonths) gmonths += " - " + engmonths[e.get_gmonth()-1];
    ui->gmonthlbl->setText(gmonths);


    Hdate tmpday;
    tmpday.set_hdate(firstday->get_hday(), firstday->get_hmonth(), firstday->get_hyear());

    int jd = tmpday.get_julian();
    int firstweekday = tmpday.get_day_of_the_week()-1;

    QSize widest(0,0);

    for (int i = firstweekday; tmpday.get_hmonth() == firstday->get_hmonth(); i++)
    {
        //
        //print (tmpday.get_format_date(0));

        dayButton *d = new dayButton(this, jd);
        dayList << d;

        ui->gridLayout->addWidget(d, 1+(i/7), (i%7));

        connect(d, SIGNAL(clicked(dayButton*)), this, SLOT(dayClicked(dayButton*)));

        jd++;
        tmpday.set_jd(jd);

        //Find the biggest button's minimum size
        if (d->sizeHint().width() > widest.width()) widest = d->sizeHint();

    }

    if (lastselected != NULL) lastselected->Unselect();

    //Force all buttons to the size of the biggest one
    for (int i = 0; i<dayList.size(); i++)
    {
        dayList[i]->setMinimumSize(widest);
    }

    if (current.get_julian() - firstday->get_julian() >= 0 && current.get_julian() - firstday->get_julian() < dayList.size())
    {
        dayList[current.get_julian() - firstday->get_julian()]->Select();
        lastselected = dayList[current.get_julian() - firstday->get_julian()];
    }

    if (firstday->get_hmonth() == today.get_hmonth() && firstday->get_hyear() == today.get_hyear()) dayList[today.get_julian() - firstday->get_julian()]->setToday();
}

void MainWindow::clearMonth()
{
    for (int i = 0; i<dayList.size(); i++)
    {
        if (dayList[i] != NULL) delete dayList[i];
    }
    dayList.clear();
}

void MainWindow::redraw()
{
    lastselected = NULL;

    Hdate d;
    d.set_hdate(1, current.get_hmonth(),  current.get_hyear());
    showMonth(&d);
}

void MainWindow::dayClicked(dayButton * day)
{
    if (lastselected != NULL) lastselected->Unselect();

    day->Select();
    lastselected = day;

    current.set_jd(day->getHDate()->get_julian());

    ui->daylabel->setText(current.get_hebrew_day_string());
    ui->engdaylbl->setText(stringify(current.get_gday()));
}

void MainWindow::readFromStdout()
{
    std::cout << QString(proc->readAll()).toStdString() << std::endl;
}

MainWindow::~MainWindow()
{
    clearMonth();

    delete ui;
}

//TODO:
void MainWindow::nextDay()
{
    current.addDay();

    if (lastselected != NULL) lastselected->Unselect();

    dayList[current.get_julian() - dayList[0]->getHDate()->get_julian()]->Select();
    lastselected = dayList[current.get_julian() - dayList[0]->getHDate()->get_julian()];

    ui->daylabel->setText(current.get_hebrew_day_string());
    ui->engdaylbl->setText(stringify(current.get_gday()));
}

void MainWindow::backDay()
{
    current.removeDay();

    if (lastselected != NULL) lastselected->Unselect();

    dayList[current.get_julian() - dayList[0]->getHDate()->get_julian()]->Select();
    lastselected = dayList[current.get_julian() - dayList[0]->getHDate()->get_julian()];

    ui->daylabel->setText(current.get_hebrew_day_string());
    ui->engdaylbl->setText(stringify(current.get_gday()));
}



void MainWindow::on_backMonthBTN_clicked()
{
    current.removeMonth();
}

void MainWindow::on_nextMonthBTN_clicked()
{
    current.addMonth();
}

void MainWindow::on_backYearBTN_clicked()
{
    current.removeYear();
}

void MainWindow::on_nextYearBTN_clicked()
{
    current.addYear();
}

void MainWindow::on_backDayBTN_clicked()
{
    backDay();
}

void MainWindow::on_nextDayBTN_clicked()
{
    nextDay();
}

void MainWindow::on_doublenextYearBTN_clicked()
{
    current.addYear(10);
}

void MainWindow::on_doublebackYearBTN_clicked()
{
    current.removeYear(10);
}
