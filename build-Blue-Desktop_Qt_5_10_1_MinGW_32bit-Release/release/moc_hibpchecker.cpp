/****************************************************************************
** Meta object code from reading C++ file 'hibpchecker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/Tools/HIBPChecker/hibpchecker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hibpchecker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HIBPChecker_t {
    QByteArrayData data[15];
    char stringdata0[203];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HIBPChecker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HIBPChecker_t qt_meta_stringdata_HIBPChecker = {
    {
QT_MOC_LITERAL(0, 0, 11), // "HIBPChecker"
QT_MOC_LITERAL(1, 12, 16), // "requestProcessed"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 28), // "std::pair<QString,CheckType>"
QT_MOC_LITERAL(4, 59, 8), // "metadata"
QT_MOC_LITERAL(5, 68, 12), // "returnedData"
QT_MOC_LITERAL(6, 81, 13), // "replyFinished"
QT_MOC_LITERAL(7, 95, 14), // "QNetworkReply*"
QT_MOC_LITERAL(8, 110, 5), // "reply"
QT_MOC_LITERAL(9, 116, 9), // "slotError"
QT_MOC_LITERAL(10, 126, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(11, 154, 3), // "err"
QT_MOC_LITERAL(12, 158, 13), // "slotSslErrors"
QT_MOC_LITERAL(13, 172, 16), // "QList<QSslError>"
QT_MOC_LITERAL(14, 189, 13) // "processBuffer"

    },
    "HIBPChecker\0requestProcessed\0\0"
    "std::pair<QString,CheckType>\0metadata\0"
    "returnedData\0replyFinished\0QNetworkReply*\0"
    "reply\0slotError\0QNetworkReply::NetworkError\0"
    "err\0slotSslErrors\0QList<QSslError>\0"
    "processBuffer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HIBPChecker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   44,    2, 0x0a /* Public */,
       9,    1,   47,    2, 0x0a /* Public */,
      12,    1,   50,    2, 0x0a /* Public */,
      14,    0,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 13,   11,
    QMetaType::Void,

       0        // eod
};

void HIBPChecker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HIBPChecker *_t = static_cast<HIBPChecker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestProcessed((*reinterpret_cast< std::pair<QString,CheckType>(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->replyFinished((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 2: _t->slotError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 3: _t->slotSslErrors((*reinterpret_cast< QList<QSslError>(*)>(_a[1]))); break;
        case 4: _t->processBuffer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QSslError> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (HIBPChecker::*_t)(std::pair<QString,CheckType> , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HIBPChecker::requestProcessed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HIBPChecker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HIBPChecker.data,
      qt_meta_data_HIBPChecker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HIBPChecker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HIBPChecker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HIBPChecker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HIBPChecker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void HIBPChecker::requestProcessed(std::pair<QString,CheckType> _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
