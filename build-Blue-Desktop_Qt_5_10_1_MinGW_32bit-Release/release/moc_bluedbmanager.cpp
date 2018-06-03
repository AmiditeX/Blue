/****************************************************************************
** Meta object code from reading C++ file 'bluedbmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/DBMainComponents/bluedbmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluedbmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BlueDBManager_t {
    QByteArrayData data[24];
    char stringdata0[278];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlueDBManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlueDBManager_t qt_meta_stringdata_BlueDBManager = {
    {
QT_MOC_LITERAL(0, 0, 13), // "BlueDBManager"
QT_MOC_LITERAL(1, 14, 12), // "startReading"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "filePath"
QT_MOC_LITERAL(4, 37, 12), // "compositeKey"
QT_MOC_LITERAL(5, 50, 12), // "startWriting"
QT_MOC_LITERAL(6, 63, 7), // "jsonDoc"
QT_MOC_LITERAL(7, 71, 10), // "iterations"
QT_MOC_LITERAL(8, 82, 11), // "stretchTime"
QT_MOC_LITERAL(9, 94, 12), // "createSignal"
QT_MOC_LITERAL(10, 107, 11), // "BlueWidget*"
QT_MOC_LITERAL(11, 119, 11), // "newDatabase"
QT_MOC_LITERAL(12, 131, 4), // "path"
QT_MOC_LITERAL(13, 136, 13), // "writtenSignal"
QT_MOC_LITERAL(14, 150, 10), // "readSignal"
QT_MOC_LITERAL(15, 161, 11), // "errorSignal"
QT_MOC_LITERAL(16, 173, 11), // "errorString"
QT_MOC_LITERAL(17, 185, 19), // "decryptionErrSignal"
QT_MOC_LITERAL(18, 205, 12), // "databaseRead"
QT_MOC_LITERAL(19, 218, 12), // "DBParameters"
QT_MOC_LITERAL(20, 231, 7), // "dbParam"
QT_MOC_LITERAL(21, 239, 15), // "databaseWritten"
QT_MOC_LITERAL(22, 255, 5), // "error"
QT_MOC_LITERAL(23, 261, 16) // "failedDecryption"

    },
    "BlueDBManager\0startReading\0\0filePath\0"
    "compositeKey\0startWriting\0jsonDoc\0"
    "iterations\0stretchTime\0createSignal\0"
    "BlueWidget*\0newDatabase\0path\0writtenSignal\0"
    "readSignal\0errorSignal\0errorString\0"
    "decryptionErrSignal\0databaseRead\0"
    "DBParameters\0dbParam\0databaseWritten\0"
    "error\0failedDecryption"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlueDBManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       5,    5,   74,    2, 0x06 /* Public */,
       9,    2,   85,    2, 0x06 /* Public */,
      13,    0,   90,    2, 0x06 /* Public */,
      14,    0,   91,    2, 0x06 /* Public */,
      15,    1,   92,    2, 0x06 /* Public */,
      17,    1,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    1,   98,    2, 0x0a /* Public */,
      21,    0,  101,    2, 0x0a /* Public */,
      22,    1,  102,    2, 0x0a /* Public */,
      23,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QJsonDocument, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    6,    4,    7,    8,
    QMetaType::Void, 0x80000000 | 10, QMetaType::QString,   11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,

       0        // eod
};

void BlueDBManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BlueDBManager *_t = static_cast<BlueDBManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startReading((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->startWriting((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QJsonDocument(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 2: _t->createSignal((*reinterpret_cast< BlueWidget*(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: _t->writtenSignal(); break;
        case 4: _t->readSignal(); break;
        case 5: _t->errorSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->decryptionErrSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->databaseRead((*reinterpret_cast< DBParameters(*)>(_a[1]))); break;
        case 8: _t->databaseWritten(); break;
        case 9: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->failedDecryption((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BlueWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BlueDBManager::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueDBManager::startReading)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (BlueDBManager::*_t)(const QString & , const QJsonDocument , const QString & , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueDBManager::startWriting)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (BlueDBManager::*_t)(BlueWidget * , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueDBManager::createSignal)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (BlueDBManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueDBManager::writtenSignal)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (BlueDBManager::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueDBManager::readSignal)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (BlueDBManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueDBManager::errorSignal)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (BlueDBManager::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BlueDBManager::decryptionErrSignal)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BlueDBManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BlueDBManager.data,
      qt_meta_data_BlueDBManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BlueDBManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlueDBManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlueDBManager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BlueDBManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void BlueDBManager::startReading(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BlueDBManager::startWriting(const QString & _t1, const QJsonDocument _t2, const QString & _t3, int _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BlueDBManager::createSignal(BlueWidget * _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BlueDBManager::writtenSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BlueDBManager::readSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void BlueDBManager::errorSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BlueDBManager::decryptionErrSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
