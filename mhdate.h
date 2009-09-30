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

#ifndef MHDATE_H
#define MHDATE_H

#include <QtGui/QMainWindow>
#include <QtCore/QObject>

#include <hdatepp.h>

#include "functions.h"

using namespace hdate;


/*
    Simple class I wrote that improves the basic Hdate class.

    It adds safe date movments, taking leap months and years into account.

    It also emmits a "month_changed()" Signall every time a month was changed, directly or indirectly.

*/



class mHdate : public QObject, public Hdate
{
   Q_OBJECT

public:
    mHdate();

    //mHdate(Hdate *d);

    void removeDay();
    void addDay();

    void removeMonth();
    void addMonth();

    //Goes back the given number of years (default 1)
    void removeYear(int i=1);
    //Goes forward the given number of years (default 1)
    void addYear(int i=1);


    //Sets the hebrew date
    void set_hd(int hd, int hm, int hy);

    //Returns the Hebrew date's month length (29 or 30)
    int getMonthLength();

signals:
    //Emmited every time a month was changed, directly or indirectly.
    void month_changed();

private:
    int month_length;
};

#endif // MHDATE_H
