/****************************************************************************
** Meta object code from reading C++ file 'abstractdbwidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Blue/DBWidgets/abstractdbwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'abstractdbwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AbstractDBWidget_t {
    QByteArrayData data[8];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AbstractDBWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AbstractDBWidget_t qt_meta_stringdata_AbstractDBWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "AbstractDBWidget"
QT_MOC_LITERAL(1, 17, 11), // "sizeChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "expand"
QT_MOC_LITERAL(4, 37, 6), // "remove"
QT_MOC_LITERAL(5, 44, 37), // "std::shared_ptr<AbstractDataB..."
QT_MOC_LITERAL(6, 82, 4), // "item"
QT_MOC_LITERAL(7, 87, 8) // "modified"

    },
    "AbstractDBWidget\0sizeChanged\0\0expand\0"
    "remove\0std::shared_ptr<AbstractDataBaseItem>\0"
    "item\0modified"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AbstractDBWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    1,   35,    2, 0x06 /* Public */,
       4,    1,   38,    2, 0x06 /* Public */,
       7,    0,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

       0        // eod
};

void AbstractDBWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AbstractDBWidget *_t = static_cast<AbstractDBWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sizeChanged(); break;
        case 1: _t->expand((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->remove((*reinterpret_cast< std::shared_ptr<AbstractDataBaseItem>(*)>(_a[1]))); break;
        case 3: _t->modified(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AbstractDBWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractDBWidget::sizeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AbstractDBWidget::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractDBWidget::expand)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (AbstractDBWidget::*_t)(std::shared_ptr<AbstractDataBaseItem> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractDBWidget::remove)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (AbstractDBWidget::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AbstractDBWidget::modified)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AbstractDBWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_AbstractDBWidget.data,
      qt_meta_data_AbstractDBWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AbstractDBWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AbstractDBWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AbstractDBWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AbstractDBWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void AbstractDBWidget::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AbstractDBWidget::expand(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AbstractDBWidget::remove(std::shared_ptr<AbstractDataBaseItem> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void AbstractDBWidget::modified()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
