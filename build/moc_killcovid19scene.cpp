/****************************************************************************
** Meta object code from reading C++ file 'killcovid19scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../KillCovid-19/killcovid19scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'killcovid19scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KillCovid_19Scene_t {
    QByteArrayData data[8];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KillCovid_19Scene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KillCovid_19Scene_t qt_meta_stringdata_KillCovid_19Scene = {
    {
QT_MOC_LITERAL(0, 0, 17), // "KillCovid_19Scene"
QT_MOC_LITERAL(1, 18, 8), // "gameOver"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "KillCovidRun*"
QT_MOC_LITERAL(4, 42, 3), // "run"
QT_MOC_LITERAL(5, 46, 12), // "CreateCursor"
QT_MOC_LITERAL(6, 59, 11), // "CreateVirus"
QT_MOC_LITERAL(7, 71, 14) // "DeleteHitVirus"

    },
    "KillCovid_19Scene\0gameOver\0\0KillCovidRun*\0"
    "run\0CreateCursor\0CreateVirus\0"
    "DeleteHitVirus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KillCovid_19Scene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   37,    2, 0x0a /* Public */,
       6,    0,   38,    2, 0x0a /* Public */,
       7,    0,   39,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KillCovid_19Scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KillCovid_19Scene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->gameOver((*reinterpret_cast< KillCovidRun*(*)>(_a[1]))); break;
        case 1: _t->CreateCursor(); break;
        case 2: _t->CreateVirus(); break;
        case 3: _t->DeleteHitVirus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KillCovid_19Scene::*)(KillCovidRun * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KillCovid_19Scene::gameOver)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KillCovid_19Scene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_KillCovid_19Scene.data,
    qt_meta_data_KillCovid_19Scene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KillCovid_19Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KillCovid_19Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KillCovid_19Scene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int KillCovid_19Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void KillCovid_19Scene::gameOver(KillCovidRun * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
