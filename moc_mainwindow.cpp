/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Oct 1 09:46:16 2009
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
      31,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      44,   11,   11,   11, 0x08,
      76,   11,   11,   11, 0x08,
     102,   11,   11,   11, 0x08,
     128,   11,   11,   11, 0x08,
     155,   11,   11,   11, 0x08,
     182,   11,   11,   11, 0x08,
     207,   11,   11,   11, 0x08,
     240,  232,   11,   11, 0x08,
     278,   11,   11,   11, 0x08,
     309,   11,   11,   11, 0x08,
     340,   11,   11,   11, 0x08,
     364,   11,   11,   11, 0x08,
     388,   11,   11,   11, 0x08,
     413,   11,   11,   11, 0x08,
     438,   11,   11,   11, 0x08,
     464,   11,   11,   11, 0x08,
     490,   11,   11,   11, 0x08,
     514,  503,   11,   11, 0x08,
     543,  539,   11,   11, 0x08,
     568,  566,   11,   11, 0x08,
     583,   11,   11,   11, 0x08,
     592,   11,   11,   11, 0x08,
     604,   11,   11,   11, 0x08,
     620,   11,   11,   11, 0x08,
     637,  632,   11,   11, 0x08,
     655,  632,   11,   11, 0x08,
     684,  679,   11,   11, 0x08,
     706,   11,   11,   11, 0x08,
     717,   11,   11,   11, 0x08,
     738,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_doublenextgYearBTN_clicked()\0"
    "on_doublebackgYearBTN_clicked()\0"
    "on_nextgYearBTN_clicked()\0"
    "on_backgYearBTN_clicked()\0"
    "on_nextgmonthBTN_clicked()\0"
    "on_backgmonthBTN_clicked()\0"
    "on_nextgdayBTN_clicked()\0"
    "on_backgdayBTN_clicked()\0visible\0"
    "on_dockWidget_visibilityChanged(bool)\0"
    "on_doublebackYearBTN_clicked()\0"
    "on_doublenextYearBTN_clicked()\0"
    "on_nextDayBTN_clicked()\0on_backDayBTN_clicked()\0"
    "on_nextYearBTN_clicked()\0"
    "on_backYearBTN_clicked()\0"
    "on_nextMonthBTN_clicked()\0"
    "on_backMonthBTN_clicked()\0clearMonth()\0"
    "dayinmonth\0showMonth(hdate::Hdate*)\0"
    "day\0dayClicked(dayButton*)\0i\0"
    "changeDay(int)\0redraw()\0saveConfs()\0"
    "saveDispConfs()\0loadConfs()\0show\0"
    "toggleGDate(bool)\0toggleZmanimPanel(bool)\0"
    "date\0updateLabels(mHdate*)\0gotTimes()\0"
    "changeLocationForm()\0aboutForm()\0"
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
        case 0: on_doublenextgYearBTN_clicked(); break;
        case 1: on_doublebackgYearBTN_clicked(); break;
        case 2: on_nextgYearBTN_clicked(); break;
        case 3: on_backgYearBTN_clicked(); break;
        case 4: on_nextgmonthBTN_clicked(); break;
        case 5: on_backgmonthBTN_clicked(); break;
        case 6: on_nextgdayBTN_clicked(); break;
        case 7: on_backgdayBTN_clicked(); break;
        case 8: on_dockWidget_visibilityChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: on_doublebackYearBTN_clicked(); break;
        case 10: on_doublenextYearBTN_clicked(); break;
        case 11: on_nextDayBTN_clicked(); break;
        case 12: on_backDayBTN_clicked(); break;
        case 13: on_nextYearBTN_clicked(); break;
        case 14: on_backYearBTN_clicked(); break;
        case 15: on_nextMonthBTN_clicked(); break;
        case 16: on_backMonthBTN_clicked(); break;
        case 17: clearMonth(); break;
        case 18: showMonth((*reinterpret_cast< hdate::Hdate*(*)>(_a[1]))); break;
        case 19: dayClicked((*reinterpret_cast< dayButton*(*)>(_a[1]))); break;
        case 20: changeDay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: redraw(); break;
        case 22: saveConfs(); break;
        case 23: saveDispConfs(); break;
        case 24: loadConfs(); break;
        case 25: toggleGDate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: toggleZmanimPanel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: updateLabels((*reinterpret_cast< mHdate*(*)>(_a[1]))); break;
        case 28: gotTimes(); break;
        case 29: changeLocationForm(); break;
        case 30: aboutForm(); break;
        default: ;
        }
        _id -= 31;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
