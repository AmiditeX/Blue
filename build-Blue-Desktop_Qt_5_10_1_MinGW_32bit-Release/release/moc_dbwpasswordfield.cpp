/****************************************************************************
** Meta object code from reading C++ file 'dbwpasswordfield.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/DBWidgets/dbwpasswordfield.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbwpasswordfield.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBWPasswordField_t {
    QByteArrayData data[5];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBWPasswordField_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBWPasswordField_t qt_meta_stringdata_DBWPasswordField = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DBWPasswordField"
QT_MOC_LITERAL(1, 17, 12), // "removeWidget"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 11), // "expiredDate"
QT_MOC_LITERAL(4, 43, 21) // "changeExpirationState"

    },
    "DBWPasswordField\0removeWidget\0\0"
    "expiredDate\0changeExpirationState"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBWPasswordField[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x0a /* Public */,
       4,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DBWPasswordField::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBWPasswordField *_t = static_cast<DBWPasswordField *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->removeWidget(); break;
        case 1: _t->expiredDate(); break;
        case 2: _t->changeExpirationState(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject DBWPasswordField::staticMetaObject = {
    { &AbstractDBWidget::staticMetaObject, qt_meta_stringdata_DBWPasswordField.data,
      qt_meta_data_DBWPasswordField,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DBWPasswordField::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBWPasswordField::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBWPasswordField.stringdata0))
        return static_cast<void*>(this);
    return AbstractDBWidget::qt_metacast(_clname);
}

int DBWPasswordField::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractDBWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
