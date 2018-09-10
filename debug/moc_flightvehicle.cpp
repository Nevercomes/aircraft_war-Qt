/****************************************************************************
** Meta object code from reading C++ file 'flightvehicle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../flightvehicle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'flightvehicle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FlightVehicle_t {
    QByteArrayData data[9];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FlightVehicle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FlightVehicle_t qt_meta_stringdata_FlightVehicle = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FlightVehicle"
QT_MOC_LITERAL(1, 14, 9), // "sig_score"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "score"
QT_MOC_LITERAL(4, 31, 9), // "sig_blood"
QT_MOC_LITERAL(5, 41, 5), // "blood"
QT_MOC_LITERAL(6, 47, 8), // "sig_bomb"
QT_MOC_LITERAL(7, 56, 4), // "bomb"
QT_MOC_LITERAL(8, 61, 8) // "sig_fall"

    },
    "FlightVehicle\0sig_score\0\0score\0sig_blood\0"
    "blood\0sig_bomb\0bomb\0sig_fall"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FlightVehicle[] = {

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
       1,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,
       6,    1,   40,    2, 0x06 /* Public */,
       8,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,

       0        // eod
};

void FlightVehicle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        FlightVehicle *_t = static_cast<FlightVehicle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_score((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->sig_blood((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sig_bomb((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->sig_fall(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (FlightVehicle::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlightVehicle::sig_score)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (FlightVehicle::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlightVehicle::sig_blood)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (FlightVehicle::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlightVehicle::sig_bomb)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (FlightVehicle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&FlightVehicle::sig_fall)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject FlightVehicle::staticMetaObject = {
    { &Flyer::staticMetaObject, qt_meta_stringdata_FlightVehicle.data,
      qt_meta_data_FlightVehicle,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *FlightVehicle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FlightVehicle::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_FlightVehicle.stringdata0))
        return static_cast<void*>(const_cast< FlightVehicle*>(this));
    return Flyer::qt_metacast(_clname);
}

int FlightVehicle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Flyer::qt_metacall(_c, _id, _a);
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
void FlightVehicle::sig_score(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FlightVehicle::sig_blood(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FlightVehicle::sig_bomb(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FlightVehicle::sig_fall()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
