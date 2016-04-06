/****************************************************************************
** Meta object code from reading C++ file 'etatright.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../automate-project/etatright.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'etatright.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_etatRight_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_etatRight_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_etatRight_t qt_meta_stringdata_etatRight = {
    {
QT_MOC_LITERAL(0, 0, 9), // "etatRight"
QT_MOC_LITERAL(1, 10, 13), // "refreshNeeded"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "etatChanges"
QT_MOC_LITERAL(4, 37, 13), // "addTransition"
QT_MOC_LITERAL(5, 51, 2), // "to"
QT_MOC_LITERAL(6, 54, 5), // "vocab"
QT_MOC_LITERAL(7, 60, 15), // "eraseTransition"
QT_MOC_LITERAL(8, 76, 10) // "etatChange"

    },
    "etatRight\0refreshNeeded\0\0etatChanges\0"
    "addTransition\0to\0vocab\0eraseTransition\0"
    "etatChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_etatRight[] = {

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
       1,    1,   39,    2, 0x06 /* Public */,
       3,    3,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    2,   49,    2, 0x0a /* Public */,
       7,    2,   54,    2, 0x0a /* Public */,
       8,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Bool,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,

       0        // eod
};

void etatRight::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        etatRight *_t = static_cast<etatRight *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refreshNeeded((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->etatChanges((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 2: _t->addTransition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->eraseTransition((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->etatChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (etatRight::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&etatRight::refreshNeeded)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (etatRight::*_t)(int , bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&etatRight::etatChanges)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject etatRight::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_etatRight.data,
      qt_meta_data_etatRight,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *etatRight::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *etatRight::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_etatRight.stringdata0))
        return static_cast<void*>(const_cast< etatRight*>(this));
    return QWidget::qt_metacast(_clname);
}

int etatRight::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void etatRight::refreshNeeded(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void etatRight::etatChanges(int _t1, bool _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
