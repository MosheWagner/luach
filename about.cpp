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

#define VERSION "0.072"

About::About(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::About)
{
    m_ui->setupUi(this);

    setWindowIcon(QIcon(":/Icons/ToratEmet.png"));

    QString text = "";

    text = tr("<center><b> QT Luach (Yet another Hebrew calander) - ");
    text += VERSION;
    text += "<br> </b>";

    text += "<a href=\"http://luach.googlecode.com\">http://luach.googlecode.com</a> <br><br>";

    text += "<br>";

    text += tr("This program comes with absolutely no Halachic warranty. <br> Use it at your own risk.");

    text += "<br><br>";
    text += tr("Comments, complaints and gifts are greatly welcome at -<br>");
    text += tr("   moshe.wagner@gmail.com");

    m_ui->label->setText(text);

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
