/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../mainwindow.h"
#include <QtNetwork/QSslError>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[50];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "sigYourName"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 4), // "name"
QT_MOC_LITERAL(29, 17), // "on_user_triggered"
QT_MOC_LITERAL(47, 20), // "on_manager_triggered"
QT_MOC_LITERAL(68, 11), // "getYourName"
QT_MOC_LITERAL(80, 10), // "selectPoit"
QT_MOC_LITERAL(91, 5), // "index"
QT_MOC_LITERAL(97, 9), // "storeInfo"
QT_MOC_LITERAL(107, 4), // "mode"
QT_MOC_LITERAL(112, 3), // "lon"
QT_MOC_LITERAL(116, 3), // "lat"
QT_MOC_LITERAL(120, 8), // "showInfo"
QT_MOC_LITERAL(129, 10), // "createMode"
QT_MOC_LITERAL(140, 8), // "editMode"
QT_MOC_LITERAL(149, 12), // "navigateMode"
QT_MOC_LITERAL(162, 11), // "continueAdd"
QT_MOC_LITERAL(174, 7), // "confirm"
QT_MOC_LITERAL(182, 6), // "cancel"
QT_MOC_LITERAL(189, 13), // "selectPicture"
QT_MOC_LITERAL(203, 8), // "filePath"
QT_MOC_LITERAL(212, 10), // "clearImage"
QT_MOC_LITERAL(223, 9), // "showImage"
QT_MOC_LITERAL(233, 6) // "submit"

    },
    "MainWindow\0sigYourName\0\0name\0"
    "on_user_triggered\0on_manager_triggered\0"
    "getYourName\0selectPoit\0index\0storeInfo\0"
    "mode\0lon\0lat\0showInfo\0createMode\0"
    "editMode\0navigateMode\0continueAdd\0"
    "confirm\0cancel\0selectPicture\0filePath\0"
    "clearImage\0showImage\0submit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  122,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,  125,    2, 0x0a,    3 /* Public */,
       5,    0,  126,    2, 0x0a,    4 /* Public */,
       6,    0,  127,    2, 0x0a,    5 /* Public */,
       7,    1,  128,    2, 0x0a,    6 /* Public */,
       9,    3,  131,    2, 0x0a,    8 /* Public */,
      13,    1,  138,    2, 0x0a,   12 /* Public */,
      14,    0,  141,    2, 0x08,   14 /* Private */,
      15,    0,  142,    2, 0x08,   15 /* Private */,
      16,    0,  143,    2, 0x08,   16 /* Private */,
      17,    0,  144,    2, 0x08,   17 /* Private */,
      18,    0,  145,    2, 0x08,   18 /* Private */,
      19,    0,  146,    2, 0x08,   19 /* Private */,
      20,    1,  147,    2, 0x08,   20 /* Private */,
      20,    0,  150,    2, 0x28,   22 /* Private | MethodCloned */,
      22,    0,  151,    2, 0x08,   23 /* Private */,
      23,    1,  152,    2, 0x08,   24 /* Private */,
      24,    0,  155,    2, 0x08,   26 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   11,   12,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sigYourName((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->on_user_triggered(); break;
        case 2: _t->on_manager_triggered(); break;
        case 3: _t->getYourName(); break;
        case 4: _t->selectPoit((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->storeInfo((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 6: _t->showInfo((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->createMode(); break;
        case 8: _t->editMode(); break;
        case 9: _t->navigateMode(); break;
        case 10: _t->continueAdd(); break;
        case 11: _t->confirm(); break;
        case 12: _t->cancel(); break;
        case 13: _t->selectPicture((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 14: _t->selectPicture(); break;
        case 15: _t->clearImage(); break;
        case 16: _t->showImage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->submit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sigYourName)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sigYourName(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
