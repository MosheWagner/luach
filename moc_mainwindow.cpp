/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed Sep 30 13:37:00 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      43,   11,   11,   11, 0x08,
      74,   11,   11,   11, 0x08,
      98,   11,   11,   11, 0x08,
     122,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,
     172,   11,   11,   11, 0x08,
     198,   11,   11,   11, 0x08,
     224,   11,   11,   11, 0x08,
     246,  237,   11,   11, 0x08,
     264,   11,   11,   11, 0x08,
     285,  281,   11,   11, 0x08,
     310,  308,   11,   11, 0x08,
     325,   11,   11,   11, 0x08,
     339,  334,   11,   11, 0x08,
     361,   11,   11,   11, 0x08,
     372,   11,   11,   11, 0x08,
     404,  401,  393,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_doublebackYearBTN_clicked()\0"
    "on_doublenextYearBTN_clicked()\0"
    "on_nextDayBTN_clicked()\0on_backDayBTN_clicked()\0"
    "on_nextYearBTN_clicked()\0"
    "on_backYearBTN_clicked()\0"
    "on_nextMonthBTN_clicked()\0"
    "on_backMonthBTN_clicked()\0clearMonth()\0"
    "firstday\0showMonth(Hdate*)\0readFromStdout()\0"
    "day\0dayClicked(dayButton*)\0i\0"
    "changeDay(int)\0redraw()\0date\0"
    "updateLabels(mHdate*)\0gotTimes()\0"
    "changeLocationForm()\0QString\0jd\0"
    "dafYomi(int)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_doublebackYearBTN_clicked(); break;
        case 1: on_doublenextYearBTN_clicked(); break;
        case 2: on_nextDayBTN_clicked(); break;
        case 3: on_backDayBTN_clicked(); break;
        case 4: on_nextYearBTN_clicked(); break;
        case 5: on_backYearBTN_clicked(); break;
        case 6: on_nextMonthBTN_clicked(); break;
        case 7: on_backMonthBTN_clicked(); break;
        case 8: clearMonth(); break;
        case 9: showMonth((*reinterpret_cast< Hdate*(*)>(_a[1]))); break;
        case 10: readFromStdout(); break;
        case 11: dayClicked((*reinterpret_cast< dayButton*(*)>(_a[1]))); break;
        case 12: changeDay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: redraw(); break;
        case 14: updateLabels((*reinterpret_cast< mHdate*(*)>(_a[1]))); break;
        case 15: gotTimes(); break;
        case 16: changeLocationForm(); break;
        case 17: { QString _r = dafYomi((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
