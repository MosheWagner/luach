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

#define VERSION "0.001"


About::About(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::About)
{
    m_ui->setupUi(this);

    setWindowIcon(QIcon(":/Icons/ToratEmet.png"));

    QString text = "<center><b> QT Luach, (עוד) לוח שנה עברי - ";
    text += VERSION;
    text += "<br> </b></center>";

    text += "   <a href=\"http://luach.googlecode.com\">http://luach.googlecode.com</a> <br><br>";

    text += "<br>";
    text += "התוכנה כאן מובאת ללא כל התחייבות הלכתית. <br> כל שימוש בנתונים המובאים כאן נעשה על אחריו המשתמש בלבד.";

    text += "<br><br>";
    text += "   משה וגנר - ";
    text += "   moshe.wagner@gmail.com, תש''ע";

    m_ui->label->setText(text);

}

About::~About()
{
    delete m_ui;
}

void About::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void About::on_label_linkActivated(QString link)
{
    //Open the project's site in a browser
    QDesktopServices::openUrl(QUrl(link));
}
