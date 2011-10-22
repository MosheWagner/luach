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

#include "about.h"
#include "ui_about.h"

#define VERSION "0.082"

About::About(QString info, QWidget *parent) : QDialog(parent), m_ui(new Ui::About)
{
    m_ui->setupUi(this);

    setWindowIcon(QIcon(":/Icons/ToratEmet.png"));

    QString aboutText = "";

    aboutText = tr("<center><b> QT Luach (Yet another Hebrew calander) - ");
    aboutText += VERSION;
    aboutText += "<br> </b>";

    aboutText += "<a href=\"http://luach.googlecode.com\">http://luach.googlecode.com</a> <br><br>";

    aboutText += "<br>";

    aboutText += tr("This program comes with absolutely no Halachic warranty. <br> Use it at your own risk.");

    aboutText += "<br><br>";
    aboutText += tr("Comments, complaints and gifts are greatly welcome at -<br>");
    aboutText += tr("   moshe.wagner@gmail.com");


    QString accuracyText = "";

    accuracyText = tr("<center><b> Notice about accuracy of <i>Zmanim</i> :</b></center>");
    accuracyText += "<br>";
    accuracyText += "<small>";
    accuracyText += tr("<i>Luach</i> uses <i>KosherJava's</i> <i>Zmanim</i> library to calculate the <i>Zmanim</i>. Although that algorithim is very accurate, <i>Zmanim</i> should allways be treated as inaccurate (<i>lechumra</i>), for the following reasons:");
    accuracyText += "<br><br>";
    accuracyText += tr("- There are many <i>Shitot</i> to calculate every <i>Zman</i>, varying greatly. The difference between some <i>Shitot</i> in <i>Alos Hashacar</i>, for instance, can be of over 20 minutes!");
    accuracyText += "<br><br>";
    accuracyText += tr("- <i>Luach</i> calculates the sunrise and sunset from sea level only. Many <i>Shitot</i> require taking the elevation into account, a parameter that changes greatly even within the same city. Some <i>Shitot</i> even require taking the mountains surrounding the city into account.");
    accuracyText += "<br><br>";
    accuracyText += tr("- The location given to the program isn't always exact, especially in large cities. That could end up changing all the calculations by a few minutes.");
    accuracyText += "<br><br>";
    accuracyText += tr("- Your clock and the one the <i>luach</i> uses are probably not exactly the same, anyway.");
    accuracyText += "</small>";

    QString shitotText = "";

    shitotText = tr("<center><b> <i>Zmanim</i> used by the <i>Luach</i>:</b></center>");

    shitotText += "<br> <br>";

    shitotText += tr("The <i>Zmanim</i> are shown according to the following <i>Shitot</i>: ");

    shitotText += "<br><br>";

    shitotText += tr("- <i>Alos Hashacar</i> (90 min /72 min) - 90/72 fixed minutes before sunrise.");
    shitotText += "<br>";
    shitotText += tr("- <i>Misheyakir</i> - Sun at 11 degrees below horizon. ");
    shitotText += "<br>";
    shitotText += tr("- <i>Sunrise</i> - Astronomical sunrise <b>at sea level</b>.");
    shitotText += "<br>";
    shitotText += tr("- <i>Shma/Tfila MG\"A</i> - Based on <i>Alos</i> of 72 fixed minutes before sunrise.");
    shitotText += "<br>";
    shitotText += tr("- <i>Tzais (24 min)</i> - 24 fixed minutes after sunset.");

    shitotText += "<br><br>";
    shitotText += tr("There are many other <i>Shitot</i> for each <i>Zman</i>. I have choosen the most common ones that I've seen used, but it's your own responsability to see what <i>Shita</i> your <i> Kehila</i> follows.");


    if (info == "About") m_ui->label->setText(aboutText);
    else if (info == "Accuracy") m_ui->label->setText(accuracyText);
    else if (info == "Shitot") m_ui->label->setText(shitotText);

}

About::~About()
{
    delete m_ui;
}

void About::on_label_linkActivated(QString link)
{
    //Open the project's site in a browser
    QDesktopServices::openUrl(QUrl(link));
}

void About::on_pushButton_clicked()
{
    close();
}
