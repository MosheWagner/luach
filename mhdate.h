#ifndef MHDATE_H
#define MHDATE_H

#include <hdatepp.h>
#include <QtGui/QMainWindow>
#include <QtCore/QObject>

#include "functions.h"

using namespace hdate;

class mHdate : public QObject, public Hdate
{
   Q_OBJECT

public:
    mHdate();
    mHdate(int hd, int hm, int hy);

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
