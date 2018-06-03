/****************************************************************************
** Meta object code from reading C++ file 'databasesettings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/MainwindowWidgets/databasesettings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'databasesettings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DatabaseSettings_t {
    QByteArrayData data[8];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DatabaseSettings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DatabaseSettings_t qt_meta_stringdata_DatabaseSettings = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DatabaseSettings"
QT_MOC_LITERAL(1, 17, 9), // "okPressed"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "closePressed"
QT_MOC_LITERAL(4, 41, 14), // "openDbSelector"
QT_MOC_LITERAL(5, 56, 15), // "openKeySelector"
QT_MOC_LITERAL(6, 72, 10), // "changeSize"
QT_MOC_LITERAL(7, 83, 8) // "expanded"

    },
    "DatabaseSettings\0okPressed\0\0closePressed\0"
    "openDbSelector\0openKeySelector\0"
    "changeSize\0expanded"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DatabaseSettings[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    1,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void DatabaseSettings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DatabaseSettings *_t = static_cast<DatabaseSettings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->okPressed(); break;
        case 1: _t->closePressed(); break;
        case 2: _t->openDbSelector(); break;
        case 3: _t->openKeySelector(); break;
        case 4: _t->changeSize((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DatabaseSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseSettings::okPressed)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DatabaseSettings::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DatabaseSettings::closePressed)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DatabaseSettings::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DatabaseSettings.data,
      qt_meta_data_DatabaseSettings,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DatabaseSettings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DatabaseSettings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DatabaseSettings.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DatabaseSettings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DatabaseSettings::okPressed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void DatabaseSettings::closePressed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
