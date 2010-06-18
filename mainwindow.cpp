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


*
*   Special thanks given to ארתיום בייליס, for the great help with gettext on windows. Thanks.
*

*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

/*

  Kaluach clone:


  Provides:
    - Basic calandar interface:
        - Hebrew / English date
        - Hebrew / English interface
        - Change date, location, timezone

    - Zmanim obainted from ZmanimCLI

    - Daf yomi , (eventually should have other "yomi" stuff too)

    - Print snapshots


  Stuff to add:

    - Events
    - Haftarot
    - Dalvening calculation
    - Other cool features ;-)

*/

//TODO: Make libzmanim a seperate package

//TODO: System tray icon

//TODO: Special shabatot

//TODO: ברכת החמה

//TODO: Comments!!!


//List of all day button shown
QList <dayButton *> dayList;
//Points to the selected button
dayButton * lastselected;

QStringList weekdays;
vector <QLabel *>  weekdaylbls;
QStringList engmonths;

QProcess *zmanimproc;


//Default is Jerusalem
QString locationName;
double latitude; //קו רוחב
double longitude; //קו אורך
QString TimeZone;
double elavation;
double candleLightingOffset;
bool hool;

bool ShowGDate;
bool ShowZmanim;
QString LANG;


QString ZMANIMCLIPATH = "ZmanimCLI.jar";


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    //Restores the window's state from the last run
    restoreWindowState();

    //Set all QString to work with unicode
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf8"));

    //Configure paths:
    QFile f("ZmanimCLI.jar");

    if (!f.exists()) //Files are not in this dir (such as after installation in *nix)
    {
        if (!f.exists("/usr/share/Luach/ZmanimCLI.jar"))
        {
            QMessageBox::warning (this,tr("ZmanimCLI not found!") ,tr("Can't find ZmanimCLI! Hiding Zmanim!"));

            //Hide times:
            ui->zmanimpanelaction->setVisible(false);
            ui->changelocationaction->setVisible(false);
            toggleZmanimPanel(false);
        }

        ZMANIMCLIPATH = "/usr/share/Luach/ZmanimCLI.jar";
    }

    setWindowIcon(QIcon(":/Icons/calendar.png"));
    setWindowTitle(tr("Luach"));

    connect( &current, SIGNAL(month_changed()), this, SLOT(redraw()));


    removeDockWidget(ui->dockWidget);
    addDockWidget(Qt::LeftDockWidgetArea, ui->dockWidget);
    ui->dockWidget->show();


    loadConfs();


    weekdays << tr("Sunday") << tr("Monday") << tr("Tuesday") << tr("Wednesday") << tr("Thursday") << tr("Friday") << tr("Saturday");
    engmonths << tr("January") << tr("February") << tr("March") << tr("April") << tr("May") << tr("June") << tr("July") << tr("August") << tr("September") << tr("October") << tr("November") << tr("December");


    putenv("LANGUAGE=C");

    //Adjust for hebrew if needed
    if (LANG == "Hebrew") toRTL();


    lastselected = NULL;

    connect(ui->exitaction, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->changelocationaction, SIGNAL(triggered()), this, SLOT(changeLocationForm()));
    connect(ui->gdateaction, SIGNAL(toggled(bool)), this, SLOT(toggleGDate(bool)));
    connect(ui->zmanimpanelaction, SIGNAL(triggered(bool)), this, SLOT(toggleZmanimPanel(bool)));
    connect(ui->translateaction, SIGNAL(triggered()), this, SLOT(translateAction()));
    connect(ui->aboutaction, SIGNAL(triggered()), this, SLOT(aboutForm()));
    connect(ui->printaction, SIGNAL(triggered()), this, SLOT(printSnap()));


    //Add weekday labels
    for (int i=0; i<7; i++)
    {
        QLabel *lbl = new QLabel(weekdays[i]);
        lbl->setLayoutDirection(Qt::RightToLeft);
        lbl->setAlignment(Qt::AlignCenter);
        ui->gridLayout->addWidget(lbl, 0, i);

        QFont q;
        q.setPixelSize(19);
        lbl->setFont(q);

        weekdaylbls.push_back(lbl);
        //lbl->setStyleSheet("QLabel { background-color: blue }");
    }


    //Create the day buttons: (Invisible for now)
    for (int i = 0; i<30; i++)
    {
        dayButton *d = new dayButton(this, 0, ShowGDate, hool);
        dayList << d;

        d->hide();

        connect(d, SIGNAL(clicked(dayButton*)), this, SLOT(dayClicked(dayButton*)));
    }



    for (int i=0; i<ui->gridLayout->count(); i++) ui->gridLayout->setRowStretch(i,1);

    //A Hdate starts with todays date, so "current" is set to today
    showMonth(&current);

    //Current time (do something with this):
    //QTime t;
    //print (t.currentTime().toString());

    //Hide candel lighting labels
    ui->clllbllbl->hide();
    ui->candellightinglbl->hide();

    ui->tslbl->hide();
    ui->tslbllbl->hide();
}


//Restores the window's state from the last run
void MainWindow::restoreWindowState()
{
    QSettings settings("Luach", "user");

    settings.beginGroup("MainWindow");

        QDesktopWidget *widget = QApplication::desktop();
        int desktop_width = widget->width();
        int desktop_height = widget->height();

        restoreState(settings.value("state", "").toByteArray());

        resize(settings.value("size", QSize(desktop_width, desktop_height-50)).toSize());
        move(settings.value("pos", QPoint(0, 0)).toPoint());

    settings.endGroup();
}

//Overrides the normal "closeEvent", so it can save tha window's state before quiting
void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings("Luach", "user");

    settings.beginGroup("MainWindow");

        settings.setValue("size", size());
        settings.setValue("pos", pos());
        settings.setValue("state", saveState());

    settings.endGroup();
}


void MainWindow::translateAction()
{
    if (LANG == "Hebrew") LANG = "English";
    else LANG = "Hebrew";

    QSettings settings("Luach", "user");
    settings.setValue("Language", LANG);

    //Make sure the lang is saved before the reboot
    QApplication::processEvents();

    //Reboot the program
    QProcess::startDetached("\"" + QApplication::applicationFilePath() + "\"");
    exit(0);
}

void MainWindow::toRTL()
{
    setLayoutDirection(Qt::RightToLeft);
    ui->centralWidget->setLayoutDirection(Qt::RightToLeft);


    ui->horizontalLayout->setDirection(QBoxLayout::RightToLeft);
    ui->horizontalLayout_2->setDirection(QBoxLayout::RightToLeft);
    ui->horizontalLayout_3->setDirection(QBoxLayout::RightToLeft);
    ui->horizontalLayout_4->setDirection(QBoxLayout::RightToLeft);
    ui->horizontalLayout_5->setDirection(QBoxLayout::RightToLeft);
    ui->horizontalLayout_6->setDirection(QBoxLayout::RightToLeft);

    ui->formLayout_3->layout()->setContentsMargins(0,0,0,0);

    ui->dockWidget->setLayoutDirection(Qt::RightToLeft);

    removeDockWidget(ui->dockWidget);
    addDockWidget(Qt::RightDockWidgetArea, ui->dockWidget);
    if (ShowZmanim) ui->dockWidget->show();

    ui->menu->setLayoutDirection(Qt::RightToLeft);
    ui->menu_2->setLayoutDirection(Qt::RightToLeft);
    ui->menu_3->setLayoutDirection(Qt::RightToLeft);
    ui->menuBar->setLayoutDirection(Qt::RightToLeft);

    //Set Env variable LANGUAGE to "he_IL", to force Hebrew year numbers, etc'
    putenv("LANGUAGE=he_IL");
}


//Rebuild the calendar from the given first day of the month
void MainWindow::showMonth(hdate::Hdate *dayinmonth)
{
    //Clear last month
    for (int i = 0; i<30; i++)
    {
        ui->gridLayout->removeWidget(dayList[i]);
        dayList[i]->hide();
    }

    //Go to first day of the month
    hdate::Hdate firstday;
    firstday.set_hdate(1, dayinmonth->get_hmonth(), dayinmonth->get_hyear());

    hdate::Hdate tmpday;
    tmpday.set_hdate(firstday.get_hday(), firstday.get_hmonth(), firstday.get_hyear());

    int jd = tmpday.get_julian();
    int firstweekday = firstday.get_day_of_the_week()-1;

    QSize widest(0,0);


    //Set and add all dayButtons to where they should be:
    for (int i = firstweekday; tmpday.get_hmonth() == firstday.get_hmonth(); i++)
    {
        //
        //print (tmpday.get_format_date(0));

        dayButton *d = dayList[i-firstweekday];
        
        d->resetDate(jd, hool, ShowGDate);
        d->show();

        ui->gridLayout->addWidget(d, 1+(i/7), (i%7));

        jd++;
        tmpday.set_jd(jd);

        //Find the biggest button's minimum size
        if (d->sizeHint().width() > widest.width()) widest = d->sizeHint();

    }

    if (lastselected != NULL) lastselected->Unselect();

    /*
    //Force all buttons to the size of the biggest one
    for (int i = 0; i<dayList.size(); i++)
    {
        dayList[i]->setMinimumSize(widest);
    }
*/

    if (current.get_julian() - firstday.get_julian() >= 0 && current.get_julian() - firstday.get_julian() < dayList.size())
    {
        dayList[current.get_julian() - firstday.get_julian()]->Select();
        lastselected = dayList[current.get_julian() - firstday.get_julian()];
    }

    //A defualt Hdate class has today's date
    hdate::Hdate today;
    //Mark today
    if (firstday.get_hmonth() == today.get_hmonth() && firstday.get_hyear() == today.get_hyear()) dayList[today.get_julian() - firstday.get_julian()]->setToday();

    updateLabels(&current);
}

void MainWindow::clearMonth()
{
    for (int i = 0; i<dayList.size(); i++) delete dayList[i];

    dayList.clear();

    lastselected = NULL;
}

void MainWindow::redraw()
{
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
        ui->dafyomilbl->show();
        if (LANG == "Hebrew") ui->dafyomilbl->setText("דף יומי - " + dafYomi(current.get_julian()));
        else  ui->dafyomilbl->setText("Day Yomi - " + dafYomi(current.get_julian()));
    }
    else ui->dafyomilbl->hide();

    //Show times:

    /* Invokes an istance of ZmanimCLI, telling it to give a list of times for our location and date;
       The output is sent to "gotTimes()" which updates the time labels by that. */

    if (zmanimproc) zmanimproc->kill();
    delete zmanimproc;
    zmanimproc = new QProcess(this);

    QStringList args;

    QString dstr = stringify(date->get_gyear()) + "/" + stringify(date->get_gmonth()) + "/" + stringify(date->get_gday());

    args << "-jar" << ZMANIMCLIPATH << "-d" << dstr << "-lat" << stringify(latitude) << "-lon" << stringify(longitude) << "-e" << stringify(elavation) << "-tz" << TimeZone;

    zmanimproc->start("java", args);

    connect(zmanimproc, SIGNAL(readyReadStandardOutput()), this, SLOT(gotTimes()));
}

void MainWindow::gotTimes()
{
    QString str =  zmanimproc->readAllStandardOutput();

    QStringList times = str.split('\n');

    for (int i=0; i<times.size(); i++)
    {
        times[i].replace('\r',"");

        QString t = times[i].mid(times[i].lastIndexOf(" ") + 1);
        //A time
        if (times[i][0] == '*')
        {
            if (times[i].startsWith("* AlosHashachar:") == true)
            {
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


                //Candel lighting:
                if (current.get_day_of_the_week() == 6 || current.isErevYomTov(hool))
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

                //מוצאי שבת או חג
                if (current.get_day_of_the_week() == 7  || current.isYomTov(hool))
                {
                    ui->tslbllbl->show();

                    if ( current.isYomTov(hool)) ui->tslbllbl->setText(tr("Chag ends"));
                    if (current.get_day_of_the_week() == 7) ui->tslbllbl->setText(tr("Shabbos ends"));

                    ui->tslbl->show();

                    QProcess tzais;
                    QString dstr = stringify(current.get_gyear()) + "/" + stringify(current.get_gmonth()) + "/" + stringify(current.get_gday());
                    QStringList args;
                    args << "-jar" << ZMANIMCLIPATH << "-d" << dstr << "-lat" << stringify(latitude) << "-lon" << stringify(longitude) << "-e" << stringify(elavation) << "-tz" << TimeZone << "TzaisGeonim8Point5Degrees";

                    tzais.start("java", args);

                    tzais.waitForFinished();
                    QByteArray result = tzais.readAllStandardOutput();

                    ui->tslbl->setText(QString(result));


                    //If there is any candle lighting today, it should be at tzais shabat,
                    // and not at the normal time. (unless it's a Yom tov on friday)
                    if (current.get_day_of_the_week() != 6)
                    {
                        ui->candellightinglbl->setText(result);
                    }
                }
                else
                {
                    ui->tslbllbl->hide();
                    ui->tslbl->hide();
                }
            }
            if (times[i].startsWith("* Tzais:") == true)
            {
                ui->tzitslbl->setText(t);
            }
            if (times[i].startsWith("* Tzais72:") == true)
            {
                ui->tzits72lbl->setText(t);


                //This is the last time given:
                QString d = current.get_day_of_week_string(0);
                d += ", ";
                d += current.get_format_date(1);
                d += " - " + locationName;
                ui->dayandlocationlbl->setText(d);
            }
        }
    }
}

void MainWindow::saveConfs()
{
    QSettings settings("Luach", "user");

    settings.setValue("LocationName", locationName);
    settings.setValue("Latitude", latitude);
    settings.setValue("Longitude", longitude);
    settings.setValue("TimeZone", TimeZone);
    settings.setValue("Elavation", elavation);
    settings.setValue("CandleLightingOffset", candleLightingOffset);
    settings.setValue("isHool", hool);
}

void MainWindow::saveDispConfs()
{
    QSettings settings("Luach", "user");
    settings.setValue("ShowGDate", ShowGDate);
    settings.setValue("ShowZmanim", ShowZmanim);
    settings.setValue("Language", LANG);
}


void MainWindow::loadConfs()
{
    QSettings settings("Luach", "user");

    //Default is Jerusalem
    locationName = settings.value("LocationName", tr("Jerusalem, Israel")).toString();
    latitude = settings.value("Latitude", 31.77805).toDouble();
    longitude = settings.value("Longitude", 35.235149).toDouble();
    TimeZone = settings.value("TimeZone", "Israel").toString();
    elavation = settings.value("Elavation", 800).toDouble();
    candleLightingOffset = settings.value("CandleLightingOffset", 18.0).toDouble();
    hool = settings.value("isHool",false).toBool();

    ShowGDate = settings.value("ShowGDate", true).toBool();
    ShowZmanim = settings.value("ShowZmanim", true).toBool();
}

void MainWindow::toggleGDate(bool show)
{
    ShowGDate = show;

    //In case this was triggred from somewhere else
    ui->gdateaction->setChecked(show);

    if (!dayList.isEmpty()) redraw();

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
    ShowZmanim = show;
    ui->dockWidget->setVisible(show);
}

void MainWindow::on_dockWidget_visibilityChanged(bool visible)
{
    ui->zmanimpanelaction->setChecked(visible);
}

ChangeLocation *cl;
void MainWindow::changeLocationForm()
{
    cl = new ChangeLocation (this, &locationName, &latitude, &longitude, &candleLightingOffset, &TimeZone, &elavation, &hool);

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
        if (LANG=="Hebrew") changeDay(1);
        else changeDay(-1);
    }
    else if ( keyEvent->key() == Qt::Key_Right)
    {
        if (LANG=="Hebrew") changeDay(-1);
        else changeDay(1);
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
    else if ( keyEvent->key() == Qt::Key_PageUp)
    {
        //Move month back:
        current.removeMonth();
    }
    else if ( keyEvent->key() == Qt::Key_PageDown)
    {
        //Move month ahead:
        current.addMonth();
    }
}

void MainWindow::on_backMonthBTN_clicked()
{
    if (LANG=="Hebrew") current.removeMonth();
    else current.addMonth();
}

void MainWindow::on_nextMonthBTN_clicked()
{
    if (LANG=="Hebrew") current.addMonth();
    else current.removeMonth();
}

void MainWindow::on_backYearBTN_clicked()
{
    if (LANG=="Hebrew") current.removeYear();
    else current.addYear();
}

void MainWindow::on_nextYearBTN_clicked()
{
    if (LANG=="Hebrew") current.addYear();
    else current.removeYear();
}

void MainWindow::on_backDayBTN_clicked()
{
    if (LANG=="Hebrew") changeDay(-1);
    else changeDay(1);
}

void MainWindow::on_nextDayBTN_clicked()
{
    if (LANG=="Hebrew") changeDay(1);
    else changeDay(-1);
}

void MainWindow::on_doublenextYearBTN_clicked()
{
    if (LANG=="Hebrew") current.addYear(10);
    else current.removeYear(10);
}

void MainWindow::on_doublebackYearBTN_clicked()
{
    if (LANG=="Hebrew") current.removeYear(10);
    else current.addYear(10);
}

void MainWindow::on_backgdayBTN_clicked()
{
    if (LANG=="Hebrew") changeDay(-1);
    else changeDay(1);
}

void MainWindow::on_nextgdayBTN_clicked()
{
    if (LANG=="Hebrew") changeDay(1);
    else changeDay(-1);
}

void MainWindow::on_backgmonthBTN_clicked()
{
    if (LANG=="Hebrew")
    {
        if (current.get_gmonth() > 1) current.set_gdate(current.get_gday(), current.get_gmonth()-1, current.get_gyear());
        else current.set_gdate(current.get_gday(), 12, current.get_gyear()-1);
    }
    else
    {
        if (current.get_gmonth() < 12) current.set_gdate(current.get_gday(), current.get_gmonth()+1, current.get_gyear());
        else current.set_gdate(current.get_gday(), 1, current.get_gyear()+1);
    }
    showMonth(&current);
}

void MainWindow::on_nextgmonthBTN_clicked()
{
    if (LANG=="Hebrew")
    {
        if (current.get_gmonth() < 12) current.set_gdate(current.get_gday(), current.get_gmonth()+1, current.get_gyear());
        else current.set_gdate(current.get_gday(), 1, current.get_gyear()+1);
    }
    else
    {
        if (current.get_gmonth() > 1) current.set_gdate(current.get_gday(), current.get_gmonth()-1, current.get_gyear());
        else current.set_gdate(current.get_gday(), 12, current.get_gyear()-1);
    }

    showMonth(&current);
}

void MainWindow::on_backgYearBTN_clicked()
{
    if (LANG=="Hebrew") current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()-1);
    else current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()+1);

    showMonth(&current);
}

void MainWindow::on_nextgYearBTN_clicked()
{
    if (LANG=="Hebrew") current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()+1);
    else current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()-1);

    showMonth(&current);
}

void MainWindow::on_doublebackgYearBTN_clicked()
{
    if (LANG=="Hebrew") current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()-10);
    else current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()+10);

    showMonth(&current);
}

void MainWindow::on_doublenextgYearBTN_clicked()
{
    if (LANG=="Hebrew") current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()+10);
    else current.set_gdate(current.get_gday(), current.get_gmonth(), current.get_gyear()-10);

    showMonth(&current);
}

void MainWindow::printSnap()
{
    ui->dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);

    QPixmap pix = QPixmap::grabWidget(this, 10, ui->menuBar->height(), this->width(), this->height());

    QPrinter printer;
    QPrintDialog *dialog = new QPrintDialog(&printer, this);
    dialog->setWindowTitle("הדפס ספר");
    if (dialog->exec() != QDialog::Accepted)
        return;
    else
    {
        printer.setOrientation(QPrinter::Landscape);

        if (pix.width() > printer.width())
        {
            pix = pix.scaledToWidth(printer.width(), Qt::SmoothTransformation);
        }

        QPainter painter;
        painter.begin(&printer);
        painter.drawPixmap (0, 0, pix);
        painter.end();
    }

    ui->dockWidget->setFeatures(QDockWidget::DockWidgetClosable);
}
