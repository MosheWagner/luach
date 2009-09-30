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


#ifndef CHANGELOCATION_H
#define CHANGELOCATION_H

#include <QtGui/QDialog>

#include "functions.h"

namespace Ui {
    class ChangeLocation;
}

class ChangeLocation : public QDialog {
    Q_OBJECT
public:
    ChangeLocation(QWidget *parent, QString *locationName, double *latitude, double *longitude, QString *timeZone, double *elavation);
    ~ChangeLocation();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::ChangeLocation *m_ui;

    QString *locationNameptr;
    double *latitudeptr;
    double *longitudeptr;
    double *elavationeptr;
    QString *timeZoneptr;

signals:
    void changed();
    void save();

private slots:
    void on_checkBox_clicked(bool checked);
    void on_okBTN_clicked();
    void on_exitBTN_clicked();
    void gotTZ();
};

#endif // CHANGELOCATION_H
