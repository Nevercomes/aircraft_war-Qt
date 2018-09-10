/****************************************************************************
** Meta object code from reading C++ file 'space.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../space.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'space.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Space_t {
    QByteArrayData data[18];
    char stringdata0[191];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Space_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Space_t qt_meta_stringdata_Space = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Space"
QT_MOC_LITERAL(1, 6, 8), // "sig_menu"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 13), // "sig_showStart"
QT_MOC_LITERAL(4, 30, 15), // "sig_updateScore"
QT_MOC_LITERAL(5, 46, 5), // "score"
QT_MOC_LITERAL(6, 52, 11), // "slt_newGame"
QT_MOC_LITERAL(7, 64, 14), // "slt_playerDead"
QT_MOC_LITERAL(8, 79, 13), // "slt_startGame"
QT_MOC_LITERAL(9, 93, 13), // "slt_pauseGame"
QT_MOC_LITERAL(10, 107, 10), // "slt_updata"
QT_MOC_LITERAL(11, 118, 12), // "slt_addscore"
QT_MOC_LITERAL(12, 131, 8), // "slt_menu"
QT_MOC_LITERAL(13, 140, 8), // "slt_back"
QT_MOC_LITERAL(14, 149, 15), // "slt_updateBlood"
QT_MOC_LITERAL(15, 165, 5), // "blood"
QT_MOC_LITERAL(16, 171, 14), // "slt_updateBomb"
QT_MOC_LITERAL(17, 186, 4) // "bomb"

    },
    "Space\0sig_menu\0\0sig_showStart\0"
    "sig_updateScore\0score\0slt_newGame\0"
    "slt_playerDead\0slt_startGame\0slt_pauseGame\0"
    "slt_updata\0slt_addscore\0slt_menu\0"
    "slt_back\0slt_updateBlood\0blood\0"
    "slt_updateBomb\0bomb"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Space[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   84,    2, 0x09 /* Protected */,
       7,    0,   85,    2, 0x09 /* Protected */,
       8,    0,   86,    2, 0x09 /* Protected */,
       9,    0,   87,    2, 0x09 /* Protected */,
      10,    0,   88,    2, 0x09 /* Protected */,
      11,    1,   89,    2, 0x09 /* Protected */,
      12,    0,   92,    2, 0x09 /* Protected */,
      13,    0,   93,    2, 0x09 /* Protected */,
      14,    1,   94,    2, 0x09 /* Protected */,
      16,    1,   97,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void Space::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Space *_t = static_cast<Space *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_menu(); break;
        case 1: _t->sig_showStart(); break;
        case 2: _t->sig_updateScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->slt_newGame(); break;
        case 4: _t->slt_playerDead(); break;
        case 5: _t->slt_startGame(); break;
        case 6: _t->slt_pauseGame(); break;
        case 7: _t->slt_updata(); break;
        case 8: _t->slt_addscore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->slt_menu(); break;
        case 10: _t->slt_back(); break;
        case 11: _t->slt_updateBlood((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->slt_updateBomb((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Space::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Space::sig_menu)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Space::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Space::sig_showStart)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Space::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Space::sig_updateScore)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Space::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_Space.data,
      qt_meta_data_Space,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Space::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Space::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Space.stringdata0))
        return static_cast<void*>(const_cast< Space*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int Space::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void Space::sig_menu()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Space::sig_showStart()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Space::sig_updateScore(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
