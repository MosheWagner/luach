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

class mHdate : public QObject, public Hdate
{
   Q_OBJECT

public:
    mHdate();
    mHdate(Hdate *d);

    void removeMonth();
    void addMonth();

    void removeYear(int i=1);
    void addYear(int i=1);

    void removeDay();
    void addDay();


    void set_hd(int hd, int hm, int hy);

    int getMonthLength();

signals:
    void month_changed();

private:
    int month_length;
};

#endif // MHDATE_H
