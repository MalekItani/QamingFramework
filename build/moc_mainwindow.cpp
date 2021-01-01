/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../main/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainWindow_t {
    QByteArrayData data[18];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainWindow_t qt_meta_stringdata_mainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "mainWindow"
QT_MOC_LITERAL(1, 11, 10), // "swapLayout"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 19), // "updateUsernameLabel"
QT_MOC_LITERAL(4, 43, 8), // "username"
QT_MOC_LITERAL(5, 52, 24), // "updateUserProfilePicture"
QT_MOC_LITERAL(6, 77, 6), // "pixmap"
QT_MOC_LITERAL(7, 84, 23), // "openRegisterAccountForm"
QT_MOC_LITERAL(8, 108, 13), // "openLoginForm"
QT_MOC_LITERAL(9, 122, 24), // "updateLayoutWithUserInfo"
QT_MOC_LITERAL(10, 147, 5), // "User*"
QT_MOC_LITERAL(11, 153, 4), // "user"
QT_MOC_LITERAL(12, 158, 13), // "executeLogout"
QT_MOC_LITERAL(13, 172, 12), // "loginAsGuest"
QT_MOC_LITERAL(14, 185, 18), // "StartKillCovidGame"
QT_MOC_LITERAL(15, 204, 16), // "StartReversiGame"
QT_MOC_LITERAL(16, 221, 19), // "onKillCovid19Finish"
QT_MOC_LITERAL(17, 241, 15) // "onReversiFinish"

    },
    "mainWindow\0swapLayout\0\0updateUsernameLabel\0"
    "username\0updateUserProfilePicture\0"
    "pixmap\0openRegisterAccountForm\0"
    "openLoginForm\0updateLayoutWithUserInfo\0"
    "User*\0user\0executeLogout\0loginAsGuest\0"
    "StartKillCovidGame\0StartReversiGame\0"
    "onKillCovid19Finish\0onReversiFinish"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       3,    1,   77,    2, 0x06 /* Public */,
       5,    1,   80,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   83,    2, 0x0a /* Public */,
       8,    0,   84,    2, 0x0a /* Public */,
       9,    1,   85,    2, 0x0a /* Public */,
      12,    0,   88,    2, 0x0a /* Public */,
      13,    0,   89,    2, 0x0a /* Public */,
      14,    0,   90,    2, 0x0a /* Public */,
      15,    0,   91,    2, 0x0a /* Public */,
      16,    0,   92,    2, 0x0a /* Public */,
      17,    0,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QPixmap,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->swapLayout((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->updateUsernameLabel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->updateUserProfilePicture((*reinterpret_cast< const QPixmap(*)>(_a[1]))); break;
        case 3: _t->openRegisterAccountForm(); break;
        case 4: _t->openLoginForm(); break;
        case 5: _t->updateLayoutWithUserInfo((*reinterpret_cast< User*(*)>(_a[1]))); break;
        case 6: _t->executeLogout(); break;
        case 7: _t->loginAsGuest(); break;
        case 8: _t->StartKillCovidGame(); break;
        case 9: _t->StartReversiGame(); break;
        case 10: _t->onKillCovid19Finish(); break;
        case 11: _t->onReversiFinish(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainWindow::swapLayout)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainWindow::updateUsernameLabel)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (mainWindow::*)(const QPixmap & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainWindow::updateUserProfilePicture)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_mainWindow.data,
    qt_meta_data_mainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int mainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void mainWindow::swapLayout(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mainWindow::updateUsernameLabel(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mainWindow::updateUserProfilePicture(const QPixmap & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
