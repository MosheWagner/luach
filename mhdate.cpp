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

#include "mhdate.h"

mHdate::mHdate()
{
    //Find month length:
    month_length = 0;

    Hdate tmpday;
    tmpday.set_hdate(1, get_hmonth(), get_hyear());
    int jd = tmpday.get_julian();

    while( tmpday.get_hmonth() == get_hmonth() )
    {
        month_length++;

        jd++;
        tmpday.set_jd(jd);
    }
}

/*
mHdate::mHdate(Hdate *d)
{
    set_jd(d->get_julian());
}
*/

void mHdate::set_hd(int hd, int hm, int hy)
{
    //Actually set the date
    set_hdate(hd, hm, hy);


    //Find month length:
    month_length = 0;

    Hdate tmpday;
    tmpday.set_hdate(1, hm, hy);
    int jd = tmpday.get_julian();

    while( tmpday.get_hmonth() == get_hmonth() )
    {
        month_length++;

        jd++;
        tmpday.set_jd(jd);
    }


    if ( get_hday() > month_length) set_hdate(month_length, hm, hy);
}

void mHdate::removeMonth()
{
    //Leap year:
    // Go to adar a of meoberet
    if (get_hmonth() == 7 && get_size_of_year() > 365)
    {
        set_hd(get_hday(), 14 , get_hyear());
    }
    // Go to adar b of meoberet
    else if (get_hmonth() == 14)
    {
        set_hd(get_hday(), 13 , get_hyear());
    }
    // Go back to nissan
    else if (get_hmonth() == 13)
    {
        set_hd(get_hday(), 5 , get_hyear());
    }

    //Normall year
    else
    {
        if (get_hmonth() > 1) set_hd(get_hday(), get_hmonth()-1 , get_hyear());
        else
        {
            set_hd(get_hday(), 12 , get_hyear() - 1);
        }
    }

    emit month_changed();
}

void mHdate::addMonth()
{
    //Leap year:
    // Go to adar a of meoberet
    if (get_hmonth() == 5 && get_size_of_year() > 365)
    {
        set_hd(get_hday(), 13, get_hyear());
    }
    // Go to adar b of meoberet
    else if (get_hmonth() == 13)
    {
        set_hd(get_hday(), 14, get_hyear());
    }
    // Go back to nissan
    else if (get_hmonth() == 14)
    {
        set_hd(get_hday(), 7, get_hyear());
    }

    //Normall year
    else
    {
        if (get_hmonth() < 12)
        {
            set_hd(get_hday(), get_hmonth() + 1, get_hyear());
        }
        else
        {
            set_hd(get_hday(), 1 , get_hyear() + 1);
        }
    }

    emit month_changed();
}

void mHdate::removeYear(int i)
{
    set_hd(get_hday(), get_hmonth() , get_hyear() - i);

    if (get_size_of_year() > 365)
    {
        if (get_hmonth() == 6)  set_hd(get_hday(), 13, get_hyear());
    }
    else
        if (get_hmonth() == 14 || get_hmonth() == 13) set_hd(get_hday(), 6, get_hyear());

    emit month_changed();
}

void mHdate::addYear(int i)
{
    set_hd(get_hday(), get_hmonth() , get_hyear() + i);

    //Fix leap year months
    if (get_size_of_year() > 365)
    {
        if (get_hmonth() == 6)  set_hd(get_hday(), 13, get_hyear());
    }
    else
        if (get_hmonth() == 14 || get_hmonth() == 13) set_hd(get_hday(), 6, get_hyear());

    emit month_changed();
}

void mHdate::removeDay()
{
    if (get_hday() > 1) set_hd(get_hday() - 1, get_hmonth(), get_hyear());
    else
    {
        removeMonth();
        set_hd(month_length, get_hmonth(), get_hyear());
    }
}

void mHdate::addDay()
{
    if (get_hday() < month_length) set_hd(get_hday() + 1, get_hmonth(), get_hyear());
    else
    {
        set_hd(1, get_hmonth(), get_hyear());
        addMonth();

    }
}

//Return The day in the omer, starting from 1
int mHdate::getOmerDay()
{
   hdate::Hdate sixteen_nissan;
   sixteen_nissan.set_hdate(16, 7, get_hyear());

   int d = get_julian() - sixteen_nissan.get_julian() + 1;

   if ((d > 49) || (d<0))  d=0;

   return d;
}


//TODO: Remove hool parameter?

bool mHdate::isYomTov(bool hool)
{
    mHdate todayclone;
    todayclone.set_jd(get_julian());

    if (hool) todayclone.set_diaspora();

    if (todayclone.holidayType() == 1) return true;
    return false;
}

bool mHdate::isErevYomTov(bool hool)
{

    mHdate tomorrow;
    tomorrow.set_jd(get_julian() + 1);
    if (hool) tomorrow.set_diaspora();

    if (tomorrow.holidayType() == 1) return true;

    return false;
}

int mHdate::getMonthLength() { return month_length; }


/*
  This function is a copy of 'hdate_get_holyday_type' function
   (from the 'hdate_holyday.c' file) - as it is in version 1.4.14 of libhdate.
  The reason I did this, is because all linux distributions still use
    older versions of libhdate, and I need the updated function.
*/
int mHdate::holidayType()
{
    int holyday = get_holyday();


    int holyday_type = 0;

    switch (holyday)
    {
    case 0: /* regular day */
            holyday_type = 0;
            break;

    case 1:
    case 2:
    case 4:
    case 5:
    case 8:
    case 15:
    case 20:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
    case 32: /* Yom tov, To find erev yom tov, check if tomorrow returns 1 */
            holyday_type = 1;
            break;

    case 37: /* Erev yom kippur */
            holyday_type = 2;
            break;

    case 6:
    case 7:
    case 16: /* Hol hamoed */
            holyday_type = 3;
            break;

    case 9:
    case 13:
    case 14: /* Hanuka and purim */
            holyday_type = 4;
            break;

    case 3:
    case 10:
    case 12:
    case 21:
    case 22: /* tzom */
            holyday_type = 5;
            break;

    case 17:
    case 26: /* Independance day and Yom yerushalaim */
            holyday_type = 6;
            break;

    case 18:
    case 23:
    case 11: /* Lag baomer ,Tu beav, Tu beshvat */
            holyday_type = 7;
            break;

    case 24:
    case 25: /* Tzahal and Holocaust memorial days */
            holyday_type = 8;
            break;


    default: /* National days */
            holyday_type = 9;
            break;
    }

    return holyday_type;
}
