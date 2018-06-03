/****************************************************************************
** Meta object code from reading C++ file 'passwordcreator.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/MainwindowWidgets/passwordcreator.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'passwordcreator.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PasswordCreator_t {
    QByteArrayData data[14];
    char stringdata0[172];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PasswordCreator_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PasswordCreator_t qt_meta_stringdata_PasswordCreator = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PasswordCreator"
QT_MOC_LITERAL(1, 16, 11), // "sizeChanged"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 8), // "expanded"
QT_MOC_LITERAL(4, 38, 15), // "evaluateSubject"
QT_MOC_LITERAL(5, 54, 7), // "subject"
QT_MOC_LITERAL(6, 62, 10), // "switchEcho"
QT_MOC_LITERAL(7, 73, 9), // "isChecked"
QT_MOC_LITERAL(8, 83, 25), // "switchGeneratorVisibility"
QT_MOC_LITERAL(9, 109, 7), // "visible"
QT_MOC_LITERAL(10, 117, 10), // "uncheckAll"
QT_MOC_LITERAL(11, 128, 7), // "checked"
QT_MOC_LITERAL(12, 136, 16), // "generatePassword"
QT_MOC_LITERAL(13, 153, 18) // "generatePassphrase"

    },
    "PasswordCreator\0sizeChanged\0\0expanded\0"
    "evaluateSubject\0subject\0switchEcho\0"
    "isChecked\0switchGeneratorVisibility\0"
    "visible\0uncheckAll\0checked\0generatePassword\0"
    "generatePassphrase"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PasswordCreator[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   52,    2, 0x0a /* Public */,
       6,    1,   55,    2, 0x0a /* Public */,
       8,    1,   58,    2, 0x0a /* Public */,
      10,    1,   61,    2, 0x0a /* Public */,
      12,    0,   64,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void, QMetaType::Bool,    9,
    QMetaType::Void, QMetaType::Bool,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PasswordCreator::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PasswordCreator *_t = static_cast<PasswordCreator *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sizeChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->evaluateSubject((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->switchEcho((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->switchGeneratorVisibility((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->uncheckAll((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->generatePassword(); break;
        case 6: _t->generatePassphrase(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PasswordCreator::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PasswordCreator::sizeChanged)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PasswordCreator::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PasswordCreator.data,
      qt_meta_data_PasswordCreator,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PasswordCreator::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PasswordCreator::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PasswordCreator.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PasswordCreator::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void PasswordCreator::sizeChanged(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
