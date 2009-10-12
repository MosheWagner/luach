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


/*
  Change location form;

  Gets all paramets as pointers, so it just changes them directly.


  Emmits "save()" if the new location should be saved to a file,
    and "changed()" on any change (so the times can be re-calculated).


  Deals with:
    location name,
    latitude,
    longitude,
    candle lighting offset,
    time zone,
    elavation
*/

#ifndef CHANGELOCATION_H
#define CHANGELOCATION_H


#include <QtGui/QDialog>
#include <QProcess>

#include "functions.h"

namespace Ui {
    class ChangeLocation;
}

class ChangeLocation : public QDialog {
    Q_OBJECT
public:
    ChangeLocation(QWidget *parent, QString *locationName, double *latitude, double *longitude, double *candleoffset, QString *timeZone, double *elavation, bool *hool);
    ~ChangeLocation();

private:
    Ui::ChangeLocation *m_ui;

    //Pointers to the given program's parameters:
    QString *locationNameptr;
    double *latitudeptr;
    double *longitudeptr;
    double *elavationeptr;
    double *candleoffsetptr;
    QString *timeZoneptr;
    bool *hoolptr;

signals:
    void changed();
    void save();

private slots:
    void on_okBTN_clicked();
    void on_exitBTN_clicked();
    //Called when the TimeZone name's are recieved from ZmanimCLI
    void gotTZ();
};

#endif // CHANGELOCATION_H
