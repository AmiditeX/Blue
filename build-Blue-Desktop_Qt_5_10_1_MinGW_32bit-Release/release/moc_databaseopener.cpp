/****************************************************************************
** Meta object code from reading C++ file 'databaseopener.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/MainwindowWidgets/databaseopener.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databaseopener.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatabaseOpener_t {
    QByteArrayData data[12];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseOpener_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseOpener_t qt_meta_stringdata_DatabaseOpener = {
    {
QT_MOC_LITERAL(0, 0, 14), // "DatabaseOpener"
QT_MOC_LITERAL(1, 15, 11), // "openPressed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "closePressed"
QT_MOC_LITERAL(4, 41, 10), // "switchEcho"
QT_MOC_LITERAL(5, 52, 9), // "isChecked"
QT_MOC_LITERAL(6, 62, 11), // "getFilePath"
QT_MOC_LITERAL(7, 74, 9), // "getMaster"
QT_MOC_LITERAL(8, 84, 6), // "getKey"
QT_MOC_LITERAL(9, 91, 14), // "openDbSelector"
QT_MOC_LITERAL(10, 106, 15), // "openKeySelector"
QT_MOC_LITERAL(11, 122, 5) // "clear"

    },
    "DatabaseOpener\0openPressed\0\0closePressed\0"
    "switchEcho\0isChecked\0getFilePath\0"
    "getMaster\0getKey\0openDbSelector\0"
    "openKeySelector\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseOpener[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   61,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    0,   65,    2, 0x0a /* Public */,
       8,    0,   66,    2, 0x0a /* Public */,
       9,    0,   67,    2, 0x0a /* Public */,
      10,    0,   68,    2, 0x0a /* Public */,
      11,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DatabaseOpener::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatabaseOpener *_t = static_cast<DatabaseOpener *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openPressed(); break;
        case 1: _t->closePressed(); break;
        case 2: _t->switchEcho((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: { QString _r = _t->getFilePath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->getMaster();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getKey();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->openDbSelector(); break;
        case 7: _t->openKeySelector(); break;
        case 8: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DatabaseOpener::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseOpener::openPressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DatabaseOpener::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseOpener::closePressed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatabaseOpener::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DatabaseOpener.data,
      qt_meta_data_DatabaseOpener,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DatabaseOpener::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseOpener::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseOpener.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DatabaseOpener::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void DatabaseOpener::openPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DatabaseOpener::closePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
