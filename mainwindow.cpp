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

#include "mainwindow.h"
#include "ui_mainwindow.h"

/*

  Kaluach clone:


  Provides:
    - Basic calandar interface:
        - Hebrew / English date
        - Change date, location, timezone

    - Zmanim obainted from ZmanimCLI

    - Daf yomi , (eventually should have other "yomi" stuff)

  Stuff to add:
    - Print snapshots

    - Other cool features of course

*/



//TODO: finish Candle lighting for other holidays too


//TODO: Sfirat Haomer
//TODO: Days of חנוכה וחול המועד
//TODO: ברכת החמה

//TODO: OK, clean all this mess up...
//TODO: Comments! comments, comments comments!


//List of all day button shown
QList <dayButton *> dayList;
//Points to the selected button
dayButton * lastselected;

QStringList weekdays;
QStringList engmonths;

QProcess *zmanimproc;


QString locationName;
double latitude = 31.77805; //קו רוחב
double longitude = 35.235149; //קו אורך
QString TimeZone = "Israel";
double elavation = 800;
double candleLightingOffset = 18.0;


bool ShowGDate = true;

#define LOCATIONCONFPATH ".locationconf"
#define DISPCONFPATH ".dispconf"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set all QString to work with unicode
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));


    //
    zmanimproc = new QProcess(this);


    setWindowIcon(QIcon(":/Icons/calendar.png"));
    setWindowTitle("QT Luach");

    connect( &current, SIGNAL(month_changed()), this, SLOT(redraw()));


    weekdays << "ראשון" << "שני" << "שלישי" << "רביעי" << "חמישי" << "שישי" << "שבת";

    engmonths << "ינואר" << "פברואר" << "מרס" << "אפריל" << "מאי" << "יוני" << "יולי" << "אוגוסט" << "ספטמבר" << "אוקטובר" << "נובמבר" << "דצמבר";
    
    lastselected = NULL;


    //Force the locale to hebrew, so Hdate will give Hebrew strings. Yup, I don't like this either.
    // TODO: test on windows
    setlocale (LC_ALL, "he_IL.UTF-8");
    setlocale (LC_ALL, "he_IL.utf8");
    
    locationName = "ירושלים";

    loadConfs();

    connect(ui->exitaction, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->changelocationaction, SIGNAL(triggered()), this, SLOT(changeLocationForm()));
    connect(ui->gdateaction, SIGNAL(toggled(bool)), this, SLOT(toggleGDate(bool)));
    connect(ui->zmanimpanelaction, SIGNAL(toggled(bool)), this, SLOT(toggleZmanimPanel(bool)));
    connect(ui->aboutaction, SIGNAL(triggered()), this, SLOT(aboutForm()));

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
    hdate::Hdate today, d;

    current.set_hd(today.get_hday(), today.get_hmonth(), today.get_hyear());

    showMonth(&current);

    //Current time (do something with this):
    QTime t;
    print (t.currentTime ().toString());

}

//Rebuild the calendar from the given first day of the month
void MainWindow::showMonth(hdate::Hdate *dayinmonth)
{
    //Go to first day of the month
    hdate::Hdate *firstday = new hdate::Hdate();
    firstday->set_hdate(1, dayinmonth->get_hmonth(), dayinmonth->get_hyear());

    //Clear last month
    clearMonth();

    updateLabels(&current);

    //A defualt Hdate class has today's date
    hdate::Hdate today;

    hdate::Hdate tmpday;
    tmpday.set_hdate(firstday->get_hday(), firstday->get_hmonth(), firstday->get_hyear());

    int jd = tmpday.get_julian();
    int firstweekday = tmpday.get_day_of_the_week()-1;

    QSize widest(0,0);

    for (int i = firstweekday; tmpday.get_hmonth() == firstday->get_hmonth(); i++)
    {
        //
        //print (tmpday.get_format_date(0));

        dayButton *d = new dayButton(this, jd, ShowGDate);
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

    lastselected = NULL;
}

void MainWindow::redraw()
{
    lastselected = NULL;

    showMonth(&current);
}

void MainWindow::dayClicked(dayButton * day)
{
    if (lastselected != NULL) lastselected->Unselect();

    day->Select();
    lastselected = day;

    current.set_jd(day->getHDate()->get_julian());

    updateLabels(&current);
}

MainWindow::~MainWindow()
{
    saveDispConfs();

    clearMonth();

    delete ui;
}

//Change the current day by the given offset
void MainWindow::changeDay(int i)
{
    if (i < 0) for (int j=0; j > i; j--) current.removeDay();
    else for (int j=0; j < i; j++) current.addDay();

    if (lastselected != NULL) lastselected->Unselect();

    dayList[current.get_julian() - dayList[0]->getHDate()->get_julian()]->Select();
    lastselected = dayList[current.get_julian() - dayList[0]->getHDate()->get_julian()];

    updateLabels(&current);
}

void MainWindow::updateLabels(mHdate *date)
{
    ui->monthlabel->setText(date->get_hebrew_month_string(0));
    ui->yearlabel->setText(date->get_hebrew_year_string());
    ui->engyearlbl->setText(stringify(date->get_gyear()));
    ui->hmonthlbl->setText(date->get_hebrew_month_string(0));


    ui->daylabel->setText(current.get_hebrew_day_string());
    ui->engdaylbl->setText(stringify(current.get_gday()));
    ui->engmonthlbl->setText(engmonths[current.get_gmonth() - 1]);

    hdate::Hdate e;

    e.set_hdate(1, date->get_hmonth(), date->get_hyear());
    QString gmonths = engmonths[e.get_gmonth() - 1];

    e.set_hdate(date->getMonthLength(), date->get_hmonth(), date->get_hyear());
    if (engmonths[e.get_gmonth()-1] != gmonths) gmonths += " - " + engmonths[e.get_gmonth()-1];
    ui->gmonthlbl->setText(gmonths);

    if (dafYomi(current.get_julian()) != "")
    {
        ui->dafyomislbllbl->show();
        ui->dafyomilbl->show();
        ui->dafyomilbl->setText(dafYomi(current.get_julian()));
    }
    else
    {
        ui->dafyomilbl->hide();
        ui->dafyomislbllbl->hide();
    }

    //Show times:

    /* Invokes an istance of ZmanimCLI, telling it to give a list of times for our location and date;
       The output is sent to "gotTimes()" which updates the time labels by that. */

    //delete zmanimproc;
    //zmanimproc = new QProcess(this);
    zmanimproc->kill();

    QStringList args;

    QString dstr = stringify(date->get_gyear()) + "/" + stringify(date->get_gmonth()) + "/" + stringify(date->get_gday());

    args << "-jar" << "/usr/bin/ZmanimCLI.jar" << "-d" << dstr << "-lat" << stringify(latitude) << "-lon" << stringify(longitude) << "-e" << stringify(elavation) << "-tz" << TimeZone;
    zmanimproc->start("java", args);

    connect(zmanimproc, SIGNAL(readyReadStandardOutput()), this, SLOT(gotTimes()));
}

void MainWindow::gotTimes()
{
    QString str =  zmanimproc->readAllStandardOutput();

    QStringList times = str.split('\n');

    for (int i=0; i<times.size(); i++)
    {
        QString t = times[i].mid(times[i].lastIndexOf(" ") + 1);
        //A time
        if (times[i][0] == '*')
        {
            if (times[i].startsWith("* AlosHashachar:") == true)
            {
                //Clear all labels, as this is the first time:
                // (Maybe unneccesary: )
                ui->sunriselabel->setText("");
                ui->shmamgalbl->setText("");
                ui->shmagralbl->setText("");
                ui->tfilamgalbl->setText("");
                ui->tfilagralbl->setText("");
                ui->hatzotlbl->setText("");
                ui->minchagdolalbl->setText("");
                ui->minchaktanalbl->setText("");
                ui->plaglbl->setText("");
                ui->skialbl->setText("");
                ui->tzitslbl->setText("");
                ui->tzits72lbl->setText("");


                //Show alos
                ui->aloslabel->setText(t);
            }
            if (times[i].startsWith("* sunrise:") == true)
            {
                ui->sunriselabel->setText(t);
            }
            if (times[i].startsWith("* SofZmanShmaMGA:") == true)
            {
                ui->shmamgalbl->setText(t);
            }
            if (times[i].startsWith("* SofZmanShmaGRA:") == true)
            {
                ui->shmagralbl->setText(t);
            }
            if (times[i].startsWith("* SofZmanTfilaMGA:") == true)
            {
                ui->tfilamgalbl->setText(t);
            }
            if (times[i].startsWith("* SofZmanTfilaGRA:") == true)
            {
                ui->tfilagralbl->setText(t);
            }
            if (times[i].startsWith("* Chatzos:") == true)
            {
                ui->hatzotlbl->setText(t);
            }
            if (times[i].startsWith("* MinchaGedola:") == true)
            {
                ui->minchagdolalbl->setText(t);
            }
            if (times[i].startsWith("* MinchaKetana:") == true)
            {
                ui->minchaktanalbl->setText(t);
            }
            if (times[i].startsWith("* PlagHamincha:") == true)
            {
                ui->plaglbl->setText(t);
            }
            if (times[i].startsWith("* Sunset:") == true)
            {
                ui->skialbl->setText(t);

                //TODO: rest of the חגים too
                //Candel lighting:
                if (current.get_day_of_the_week() == 7 || current.get_holyday_type() == 3)
                {
                    ui->clllbllbl->show();
                    ui->candellightinglbl->show();

                    QTime sunset = QTime::fromString(t, "h:mm:ss");

                    QTime cl = sunset.addSecs(-1 * (candleLightingOffset * 60));

                    ui->candellightinglbl->setText(cl.toString("h:mm:ss"));
                }
                else
                {
                    ui->clllbllbl->hide();
                    ui->candellightinglbl->hide();
                }
            }
            if (times[i].startsWith("* Tzais:") == true)
            {
                ui->tzitslbl->setText(t);
            }
            if (times[i].startsWith("* Tzais72:") == true)
            {
                ui->tzits72lbl->setText(t);
            }
        }
    }
}

void MainWindow::saveConfs()
{
    QString confs = "";

    confs += "LocationName=" + locationName + "\n";
    confs += "Latitude=" + stringify(latitude) + "\n";
    confs += "Longitude=" + stringify(longitude) + "\n";
    confs += "TimeZone=" + TimeZone + "\n";
    confs += "Elavation=" + stringify(elavation) + "\n";
    confs += "CandleLightingOffset=" + stringify(candleLightingOffset) + "\n";

    writetofile(LOCATIONCONFPATH, confs, true);
}

void MainWindow::saveDispConfs()
{
    QString confs = "";

    if (ShowGDate) confs += "ShowGDate=True\n";
    else confs += "ShowGDate=False\n";

    writetofile(DISPCONFPATH, confs, true);
}


void MainWindow::loadConfs()
{
    QFile infile(LOCATIONCONFPATH);

    if ((infile.open(QIODevice::ReadOnly)))
    {
        QString text = infile.readAll();
        infile.close();

        QStringList lines = text.split('\n');

        for (int i=0; i<lines.size(); i++)
        {
            QStringList p = lines[i].split('=');

            if (p.size() == 2)
            {
                if (p[0] == "LocationName") locationName = p[1];
                if (p[0] == "Latitude")
                {
                    bool ok; p[1].toDouble(&ok);
                    if (ok) latitude = p[1].toDouble(&ok);
                }
                if (p[0] == "Longitude")
                {
                    bool ok; p[1].toDouble(&ok);
                    if (ok) longitude = p[1].toDouble(&ok);
                }
                if (p[0] == "TimeZone") TimeZone = p[1];
                if (p[0] == "Elavation")
                {
                    bool ok; p[1].toDouble(&ok);
                    if (ok) elavation = p[1].toDouble(&ok);
                }
                if (p[0] == "CandleLightingOffset")
                {
                    bool ok; p[1].toDouble(&ok);
                    if (ok) candleLightingOffset = p[1].toDouble(&ok);
                }
            }
        }
    }

    //Display Confs

    infile.setFileName(DISPCONFPATH);
    if ((infile.open(QIODevice::ReadOnly)))
    {
        QString text = infile.readAll();
        infile.close();

        QStringList lines = text.split('\n');

        for (int i=0; i<lines.size(); i++)
        {
            QStringList p = lines[i].split('=');

            if (p.size() == 2)
            {
                if (p[0] == "ShowGDate")
                {
                    if (p[1] == "False")
                    {
                        ui->gdateaction->setChecked(false);

                        ShowGDate = false;
                        ui->engdaylbl->setVisible(false);
                        ui->engmonthlbl->setVisible(false);
                        ui->engyearlbl->setVisible(false);
                        ui->gmonthlbl->setVisible(false);
                        ui->hmonthlbl->setVisible(false);
                        
                        ui->nextgdayBTN->setVisible(false);
                        ui->backgdayBTN->setVisible(false);
                        ui->nextgmonthBTN->setVisible(false);
                        ui->backgmonthBTN->setVisible(false);
                        ui->nextgYearBTN->setVisible(false);
                        ui->doublenextgYearBTN->setVisible(false);
                        ui->backgYearBTN->setVisible(false);
                        ui->doublebackgYearBTN->setVisible(false);

                        for (int i=3; i<7; i++) ui->gridLayout_2->setColumnStretch(i,0);
                    }
                }
            }
        }
    }

}

void MainWindow::toggleGDate(bool show)
{
    ShowGDate = show;
    redraw();

    ui->engdaylbl->setVisible(show);
    ui->engmonthlbl->setVisible(show);
    ui->engyearlbl->setVisible(show);
    ui->gmonthlbl->setVisible(show);
    ui->hmonthlbl->setVisible(show);
    
    ui->nextgdayBTN->setVisible(show);
    ui->backgdayBTN->setVisible(show);
    ui->nextgmonthBTN->setVisible(show);
    ui->backgmonthBTN->setVisible(show);
    ui->nextgYearBTN->setVisible(show);
    ui->doublenextgYearBTN->setVisible(show);
    ui->backgYearBTN->setVisible(show);
    ui->doublebackgYearBTN->setVisible(show);

    if (show == false) for (int i=3; i<7; i++) ui->gridLayout_2->setColumnStretch(i,0);
    else for (int i=0; i<7; i++) ui->gridLayout_2->setColumnStretch(i,100);
}

void MainWindow::toggleZmanimPanel(bool show)
{
    ui->dockWidget->setVisible(show);
}

void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    ui->zmanimpanelaction->setChecked(visible);
}

ChangeLocation *cl;
void MainWindow::changeLocationForm()
{
    cl = new ChangeLocation (this, &locationName, &latitude, &longitude, &candleLightingOffset, &TimeZone, &elavation);

    connect(cl, SIGNAL(changed()), this, SLOT(redraw()));
    connect(cl, SIGNAL(save()), this, SLOT(saveConfs()));

    cl->show();
}

About *about;
void MainWindow::aboutForm()
{
    about = new About();
    about->show();
}

void MainWindow::keyPressEvent( QKeyEvent *keyEvent )
{
    if ( keyEvent->key() == Qt::Key_Left)
    {
        changeDay(1);
    }
    else if ( keyEvent->key() == Qt::Key_Right)
    {
        changeDay(-1);
    }
    else if ( keyEvent->key() == Qt::Key_Up)
    {
        //Move week back:
         changeDay(-7);
    }
    else if ( keyEvent->key() == Qt::Key_Down)
    {
        //Move week ahead:
         changeDay(7);
    }
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
    changeDay(-1);
}

void MainWindow::on_nextDayBTN_clicked()
{
    changeDay(1);
}

void MainWindow::on_doublenextYearBTN_clicked()
{
    current.addYear(10);
}

void MainWindow::on_doublebackYearBTN_clicked()
{
    current.removeYear(10);
}

void MainWindow::on_backgdayBTN_clicked()
{
    changeDay(-1);
}

void MainWindow::on_nextgdayBTN_clicked()
{
    changeDay(1);
}

void MainWindow::on_backgmonthBTN_clicked()
{
    if (current.get_gmonth() > 1) current.set_gdate(current.get_gday(), current.get_gmonth()-1, current.get_gyear());
    else current.set_gdate(current.get_gday(), 12, current.get_gyear()-1);

    showMonth(&current);
}

void MainWindow::on_nextgmonthBTN_clicked()
{
    if (current.get_gmonth() < 12) current.set_gdate(current.get_gday(), current.get_gmonth()+1, current.get_gyear());
    else current.set_gdate(current.get_gday(), 1, current.get_gyear()+1);

    showMonth(&current);
}

void MainWindow::on_backgYearBTN_clicked()
{
    current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()-1);
    showMonth(&current);
}

void MainWindow::on_nextgYearBTN_clicked()
{
    current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()+1);
    showMonth(&current);
}

void MainWindow::on_doublebackgYearBTN_clicked()
{
    current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()-10);
    showMonth(&current);
}

void MainWindow::on_doublenextgYearBTN_clicked()
{
    current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()+10);
    showMonth(&current);
}
