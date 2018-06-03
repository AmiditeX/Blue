/****************************************************************************
** Meta object code from reading C++ file 'bluemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/bluemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'bluemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BlueManager_t {
    QByteArrayData data[22];
    char stringdata0[294];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BlueManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BlueManager_t qt_meta_stringdata_BlueManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "BlueManager"
QT_MOC_LITERAL(1, 12, 12), // "openDatabase"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "masterKey"
QT_MOC_LITERAL(4, 36, 8), // "filePath"
QT_MOC_LITERAL(5, 45, 7), // "keyPath"
QT_MOC_LITERAL(6, 53, 14), // "createDatabase"
QT_MOC_LITERAL(7, 68, 30), // "DatabaseCreator::DatabaseParam"
QT_MOC_LITERAL(8, 99, 10), // "parameters"
QT_MOC_LITERAL(9, 110, 13), // "closeDatabase"
QT_MOC_LITERAL(10, 124, 11), // "BlueWidget*"
QT_MOC_LITERAL(11, 136, 1), // "w"
QT_MOC_LITERAL(12, 138, 15), // "settingsChanged"
QT_MOC_LITERAL(13, 154, 31), // "DatabaseSettings::DatabaseParam"
QT_MOC_LITERAL(14, 186, 5), // "param"
QT_MOC_LITERAL(15, 192, 13), // "databaseError"
QT_MOC_LITERAL(16, 206, 3), // "err"
QT_MOC_LITERAL(17, 210, 23), // "databaseDecryptionError"
QT_MOC_LITERAL(18, 234, 17), // "terminateDatabase"
QT_MOC_LITERAL(19, 252, 16), // "databaseModified"
QT_MOC_LITERAL(20, 269, 13), // "saveDatabases"
QT_MOC_LITERAL(21, 283, 10) // "endProgram"

    },
    "BlueManager\0openDatabase\0\0masterKey\0"
    "filePath\0keyPath\0createDatabase\0"
    "DatabaseCreator::DatabaseParam\0"
    "parameters\0closeDatabase\0BlueWidget*\0"
    "w\0settingsChanged\0DatabaseSettings::DatabaseParam\0"
    "param\0databaseError\0err\0databaseDecryptionError\0"
    "terminateDatabase\0databaseModified\0"
    "saveDatabases\0endProgram"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BlueManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   64,    2, 0x0a /* Public */,
       6,    1,   71,    2, 0x0a /* Public */,
       9,    1,   74,    2, 0x0a /* Public */,
      12,    2,   77,    2, 0x0a /* Public */,
      15,    1,   82,    2, 0x0a /* Public */,
      17,    1,   85,    2, 0x0a /* Public */,
      18,    0,   88,    2, 0x0a /* Public */,
      19,    1,   89,    2, 0x0a /* Public */,
      20,    0,   92,    2, 0x0a /* Public */,
      21,    0,   93,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 13,   11,   14,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BlueManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BlueManager *_t = static_cast<BlueManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openDatabase((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->createDatabase((*reinterpret_cast< DatabaseCreator::DatabaseParam(*)>(_a[1]))); break;
        case 2: _t->closeDatabase((*reinterpret_cast< BlueWidget*(*)>(_a[1]))); break;
        case 3: _t->settingsChanged((*reinterpret_cast< BlueWidget*(*)>(_a[1])),(*reinterpret_cast< DatabaseSettings::DatabaseParam(*)>(_a[2]))); break;
        case 4: _t->databaseError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->databaseDecryptionError((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->terminateDatabase(); break;
        case 7: _t->databaseModified((*reinterpret_cast< BlueWidget*(*)>(_a[1]))); break;
        case 8: _t->saveDatabases(); break;
        case 9: _t->endProgram(); break;
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
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BlueWidget* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< BlueWidget* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BlueManager::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BlueManager.data,
      qt_meta_data_BlueManager,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BlueManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BlueManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BlueManager.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BlueManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
