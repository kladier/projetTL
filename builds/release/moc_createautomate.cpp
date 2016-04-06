/****************************************************************************
** Meta object code from reading C++ file 'createautomate.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../automate-project/createautomate.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createautomate.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CreateAutomate_t {
    QByteArrayData data[15];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CreateAutomate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CreateAutomate_t qt_meta_stringdata_CreateAutomate = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CreateAutomate"
QT_MOC_LITERAL(1, 15, 9), // "ajoutEtat"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "ini"
QT_MOC_LITERAL(4, 30, 4), // "fina"
QT_MOC_LITERAL(5, 35, 16), // "afficherAutomate"
QT_MOC_LITERAL(6, 52, 12), // "displayRight"
QT_MOC_LITERAL(7, 65, 9), // "toDisplay"
QT_MOC_LITERAL(8, 75, 12), // "supprimeEtat"
QT_MOC_LITERAL(9, 88, 5), // "cible"
QT_MOC_LITERAL(10, 94, 10), // "refreshAll"
QT_MOC_LITERAL(11, 105, 11), // "sauvegarder"
QT_MOC_LITERAL(12, 117, 11), // "changeState"
QT_MOC_LITERAL(13, 129, 4), // "etat"
QT_MOC_LITERAL(14, 134, 5) // "final"

    },
    "CreateAutomate\0ajoutEtat\0\0ini\0fina\0"
    "afficherAutomate\0displayRight\0toDisplay\0"
    "supprimeEtat\0cible\0refreshAll\0sauvegarder\0"
    "changeState\0etat\0final"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CreateAutomate[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   59,    2, 0x0a /* Public */,
       1,    1,   64,    2, 0x2a /* Public | MethodCloned */,
       1,    0,   67,    2, 0x2a /* Public | MethodCloned */,
       5,    0,   68,    2, 0x0a /* Public */,
       6,    1,   69,    2, 0x0a /* Public */,
       8,    1,   72,    2, 0x0a /* Public */,
      10,    0,   75,    2, 0x0a /* Public */,
      11,    0,   76,    2, 0x0a /* Public */,
      12,    3,   77,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool, QMetaType::Bool,   13,    3,   14,

       0        // eod
};

void CreateAutomate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CreateAutomate *_t = static_cast<CreateAutomate *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ajoutEtat((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: _t->ajoutEtat((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->ajoutEtat(); break;
        case 3: _t->afficherAutomate(); break;
        case 4: _t->displayRight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->supprimeEtat((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->refreshAll(); break;
        case 7: _t->sauvegarder(); break;
        case 8: _t->changeState((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObject CreateAutomate::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_CreateAutomate.data,
      qt_meta_data_CreateAutomate,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CreateAutomate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreateAutomate::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CreateAutomate.stringdata0))
        return static_cast<void*>(const_cast< CreateAutomate*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int CreateAutomate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
