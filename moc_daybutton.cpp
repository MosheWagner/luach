/****************************************************************************
** Meta object code from reading C++ file 'daybutton.h'
**
** Created: Thu Sep 24 20:48:31 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "daybutton.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'daybutton.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_dayButton[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      31,   10,   10,   10, 0x0a,
      40,   10,   10,   10, 0x0a,
      51,   10,   10,   10, 0x0a,
      69,   10,   62,   10, 0x0a,
      86,   80,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_dayButton[] = {
    "dayButton\0\0clicked(dayButton*)\0Select()\0"
    "Unselect()\0setToday()\0Hdate*\0getHDate()\0"
    "event\0mousePressEvent(QMouseEvent*)\0"
};

const QMetaObject dayButton::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_dayButton,
      qt_meta_data_dayButton, 0 }
};

const QMetaObject *dayButton::metaObject() const
{
    return &staticMetaObject;
}

void *dayButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_dayButton))
        return static_cast<void*>(const_cast< dayButton*>(this));
    return QFrame::qt_metacast(_clname);
}

int dayButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: clicked((*reinterpret_cast< dayButton*(*)>(_a[1]))); break;
        case 1: Select(); break;
        case 2: Unselect(); break;
        case 3: setToday(); break;
        case 4: { Hdate* _r = getHDate();
            if (_a[0]) *reinterpret_cast< Hdate**>(_a[0]) = _r; }  break;
        case 5: mousePressEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void dayButton::clicked(dayButton * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
