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

#include "changelocation.h"
#include "ui_changelocation.h"


QProcess *tzproc;

ChangeLocation::ChangeLocation(QWidget *parent, QString *locationName, double *latitude, double *longitude, double *candleoffset, QString *timeZone, double *elavation)
        : QDialog(parent),  m_ui(new Ui::ChangeLocation)
{
    m_ui->setupUi(this);

    setWindowIcon(QIcon(":/Icons/location.png"));

    //Invoke a call to ZmanimCLI telling is to print available timezones so we can list them
    tzproc = new QProcess(this);

    QStringList args;
    args << "-jar" << "/usr/bin/ZmanimCLI.jar" << "-tzl";
    tzproc->start("java", args);
    connect(tzproc, SIGNAL(readyReadStandardOutput()), this, SLOT(gotTZ()));



    locationNameptr = locationName;
    m_ui->locationLine->setText(*locationName);

    latitudeptr = latitude;
    m_ui->latitudeLine->setValue(*latitude);

    longitudeptr = longitude;
    m_ui->longitudeLine->setValue(*longitude);

    timeZoneptr = timeZone;

    elavationeptr = elavation;
    m_ui->elavationLine->setValue(*elavationeptr);

    candleoffsetptr = candleoffset;
    m_ui->offsetLine->setValue(*candleoffset);
}

ChangeLocation::~ChangeLocation()
{
    delete m_ui;
}

//Called when the TimeZone name's are recieved from ZmanimCLI
void ChangeLocation::gotTZ()
{
    QString str = tzproc->readAllStandardOutput();
    if ( str != "")
    {
        QStringList tz = str.split('\n');
        for( int i=0; i<tz.size(); i++)
        {
            if (tz[i] != "List of valid TimeZones:" && tz[i] != "" && tz[i] != "\n" && tz[i] != " ")
            {
                //Add the location to the combo box
                m_ui->comboBox->addItem(tz[i]);
            }
        }
    }

    //Make sure the current location is focused
    m_ui->comboBox->setCurrentIndex(m_ui->comboBox->findText(*timeZoneptr));
}

void ChangeLocation::on_exitBTN_clicked()
{    close();   }

void ChangeLocation::on_okBTN_clicked()
{

    *locationNameptr = m_ui->locationLine->text();
    *timeZoneptr = m_ui->comboBox->currentText();

    *latitudeptr = m_ui->latitudeLine->value();
    *longitudeptr = m_ui->longitudeLine->value();
    *elavationeptr = m_ui->elavationLine->value();
    *candleoffsetptr = m_ui->offsetLine->value();


    //Tell the mainwindow to update times
    emit changed();


    //Tell the mainwindow to save changes:
    if (m_ui->saveCheckBox->isChecked()) emit save();

    close();
}
