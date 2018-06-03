/****************************************************************************
** Meta object code from reading C++ file 'blueiointerface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/BlueCrypto/blueiointerface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'blueiointerface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BlueIOInterface_t {
    QByteArrayData data[16];
    char stringdata0[180];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlueIOInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlueIOInterface_t qt_meta_stringdata_BlueIOInterface = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BlueIOInterface"
QT_MOC_LITERAL(1, 16, 14), // "writeCompleted"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 13), // "readCompleted"
QT_MOC_LITERAL(4, 46, 12), // "DBParameters"
QT_MOC_LITERAL(5, 59, 7), // "dbParam"
QT_MOC_LITERAL(6, 67, 11), // "errorSignal"
QT_MOC_LITERAL(7, 79, 11), // "errorString"
QT_MOC_LITERAL(8, 91, 16), // "decryptionFailed"
QT_MOC_LITERAL(9, 108, 9), // "writeFile"
QT_MOC_LITERAL(10, 118, 8), // "filePath"
QT_MOC_LITERAL(11, 127, 7), // "jsonDoc"
QT_MOC_LITERAL(12, 135, 12), // "compositeKey"
QT_MOC_LITERAL(13, 148, 10), // "iterations"
QT_MOC_LITERAL(14, 159, 11), // "stretchTime"
QT_MOC_LITERAL(15, 171, 8) // "readFile"

    },
    "BlueIOInterface\0writeCompleted\0\0"
    "readCompleted\0DBParameters\0dbParam\0"
    "errorSignal\0errorString\0decryptionFailed\0"
    "writeFile\0filePath\0jsonDoc\0compositeKey\0"
    "iterations\0stretchTime\0readFile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlueIOInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    1,   45,    2, 0x06 /* Public */,
       6,    1,   48,    2, 0x06 /* Public */,
       8,    1,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    5,   54,    2, 0x0a /* Public */,
      15,    2,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonDocument, QMetaType::QString, QMetaType::Int, QMetaType::Int,   10,   11,   12,   13,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   12,

       0        // eod
};

void BlueIOInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BlueIOInterface *_t = static_cast<BlueIOInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->writeCompleted(); break;
        case 1: _t->readCompleted((*reinterpret_cast< DBParameters(*)>(_a[1]))); break;
        case 2: _t->errorSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->decryptionFailed((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->writeFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonDocument(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 5: _t->readFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BlueIOInterface::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueIOInterface::writeCompleted)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BlueIOInterface::*_t)(DBParameters );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueIOInterface::readCompleted)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BlueIOInterface::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueIOInterface::errorSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BlueIOInterface::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueIOInterface::decryptionFailed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BlueIOInterface::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BlueIOInterface.data,
      qt_meta_data_BlueIOInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BlueIOInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlueIOInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlueIOInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BlueIOInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void BlueIOInterface::writeCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void BlueIOInterface::readCompleted(DBParameters _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BlueIOInterface::errorSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BlueIOInterface::decryptionFailed(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
