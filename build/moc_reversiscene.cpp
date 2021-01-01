/****************************************************************************
** Meta object code from reading C++ file 'reversiscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Reversi/reversiscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'reversiscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReversiScene_t {
    QByteArrayData data[12];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReversiScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReversiScene_t qt_meta_stringdata_ReversiScene = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ReversiScene"
QT_MOC_LITERAL(1, 13, 11), // "scoreUpdate"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "black"
QT_MOC_LITERAL(4, 32, 5), // "white"
QT_MOC_LITERAL(5, 38, 10), // "timeUpdate"
QT_MOC_LITERAL(6, 49, 9), // "timeBlack"
QT_MOC_LITERAL(7, 59, 9), // "timeWhite"
QT_MOC_LITERAL(8, 69, 8), // "gameOver"
QT_MOC_LITERAL(9, 78, 11), // "ReversiRun*"
QT_MOC_LITERAL(10, 90, 3), // "run"
QT_MOC_LITERAL(11, 94, 10) // "UpdateTime"

    },
    "ReversiScene\0scoreUpdate\0\0black\0white\0"
    "timeUpdate\0timeBlack\0timeWhite\0gameOver\0"
    "ReversiRun*\0run\0UpdateTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReversiScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,
       8,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ReversiScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ReversiScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->scoreUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->timeUpdate((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->gameOver((*reinterpret_cast< ReversiRun*(*)>(_a[1]))); break;
        case 3: _t->UpdateTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ReversiScene::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReversiScene::scoreUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ReversiScene::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReversiScene::timeUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ReversiScene::*)(ReversiRun * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ReversiScene::gameOver)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ReversiScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_ReversiScene.data,
    qt_meta_data_ReversiScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ReversiScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReversiScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReversiScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int ReversiScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
void ReversiScene::scoreUpdate(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ReversiScene::timeUpdate(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ReversiScene::gameOver(ReversiRun * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
