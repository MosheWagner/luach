/****************************************************************************
** Meta object code from reading C++ file 'mhdate.h'
**
** Created: Wed Sep 30 15:41:52 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mhdate.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mhdate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mHdate[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_mHdate[] = {
    "mHdate\0\0month_changed()\0"
};

const QMetaObject mHdate::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_mHdate,
      qt_meta_data_mHdate, 0 }
};

const QMetaObject *mHdate::metaObject() const
{
    return &staticMetaObject;
}

void *mHdate::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mHdate))
        return static_cast<void*>(const_cast< mHdate*>(this));
    if (!strcmp(_clname, "Hdate"))
        return static_cast< Hdate*>(const_cast< mHdate*>(this));
    return QObject::qt_metacast(_clname);
}

int mHdate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: month_changed(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void mHdate::month_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
