/****************************************************************************
** Meta object code from reading C++ file 'dbwcontainers.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/DBWidgets/dbwcontainers.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dbwcontainers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DBWContainers_t {
    QByteArrayData data[13];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DBWContainers_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DBWContainers_t qt_meta_stringdata_DBWContainers = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DBWContainers"
QT_MOC_LITERAL(1, 14, 13), // "widgetClicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "drop"
QT_MOC_LITERAL(4, 34, 13), // "pendingDelete"
QT_MOC_LITERAL(5, 48, 29), // "std::shared_ptr<DBContainers>"
QT_MOC_LITERAL(6, 78, 9), // "container"
QT_MOC_LITERAL(7, 88, 8), // "modified"
QT_MOC_LITERAL(8, 97, 12), // "sizedChanged"
QT_MOC_LITERAL(9, 110, 15), // "removeContainer"
QT_MOC_LITERAL(10, 126, 13), // "editContainer"
QT_MOC_LITERAL(11, 140, 9), // "addWidget"
QT_MOC_LITERAL(12, 150, 10) // "widgetName"

    },
    "DBWContainers\0widgetClicked\0\0drop\0"
    "pendingDelete\0std::shared_ptr<DBContainers>\0"
    "container\0modified\0sizedChanged\0"
    "removeContainer\0editContainer\0addWidget\0"
    "widgetName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DBWContainers[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       7,    0,   55,    2, 0x06 /* Public */,
       8,    0,   56,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   57,    2, 0x0a /* Public */,
      10,    0,   58,    2, 0x0a /* Public */,
      11,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

       0        // eod
};

void DBWContainers::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DBWContainers *_t = static_cast<DBWContainers *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->widgetClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->pendingDelete((*reinterpret_cast< std::shared_ptr<DBContainers>(*)>(_a[1]))); break;
        case 2: _t->modified(); break;
        case 3: _t->sizedChanged(); break;
        case 4: _t->removeContainer(); break;
        case 5: _t->editContainer(); break;
        case 6: _t->addWidget((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (DBWContainers::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBWContainers::widgetClicked)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (DBWContainers::*_t)(std::shared_ptr<DBContainers> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBWContainers::pendingDelete)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (DBWContainers::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBWContainers::modified)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (DBWContainers::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DBWContainers::sizedChanged)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DBWContainers::staticMetaObject = {
    { &AbstractDBWidget::staticMetaObject, qt_meta_stringdata_DBWContainers.data,
      qt_meta_data_DBWContainers,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DBWContainers::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DBWContainers::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DBWContainers.stringdata0))
        return static_cast<void*>(this);
    return AbstractDBWidget::qt_metacast(_clname);
}

int DBWContainers::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AbstractDBWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void DBWContainers::widgetClicked(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DBWContainers::pendingDelete(std::shared_ptr<DBContainers> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void DBWContainers::modified()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void DBWContainers::sizedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
