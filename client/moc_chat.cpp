/****************************************************************************
** Meta object code from reading C++ file 'chat.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/gui/chat.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chat.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Chat_t {
    QByteArrayData data[18];
    char stringdata0[267];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Chat_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Chat_t qt_meta_stringdata_Chat = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Chat"
QT_MOC_LITERAL(1, 5, 16), // "contextMenuEvent"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 18), // "QContextMenuEvent*"
QT_MOC_LITERAL(4, 42, 5), // "event"
QT_MOC_LITERAL(5, 48, 10), // "closeEvent"
QT_MOC_LITERAL(6, 59, 12), // "QCloseEvent*"
QT_MOC_LITERAL(7, 72, 19), // "on_btn_file_clicked"
QT_MOC_LITERAL(8, 92, 19), // "on_btn_send_clicked"
QT_MOC_LITERAL(9, 112, 21), // "on_btn_logOut_clicked"
QT_MOC_LITERAL(10, 134, 21), // "on_show_users_clicked"
QT_MOC_LITERAL(11, 156, 14), // "deleteSeedSlot"
QT_MOC_LITERAL(12, 171, 14), // "clearSeedsSlot"
QT_MOC_LITERAL(13, 186, 13), // "editSeedsSlot"
QT_MOC_LITERAL(14, 200, 32), // "on_list_users_currentItemChanged"
QT_MOC_LITERAL(15, 233, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(16, 250, 7), // "current"
QT_MOC_LITERAL(17, 258, 8) // "previous"

    },
    "Chat\0contextMenuEvent\0\0QContextMenuEvent*\0"
    "event\0closeEvent\0QCloseEvent*\0"
    "on_btn_file_clicked\0on_btn_send_clicked\0"
    "on_btn_logOut_clicked\0on_show_users_clicked\0"
    "deleteSeedSlot\0clearSeedsSlot\0"
    "editSeedsSlot\0on_list_users_currentItemChanged\0"
    "QListWidgetItem*\0current\0previous"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Chat[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       5,    1,   67,    2, 0x08 /* Private */,
       7,    0,   70,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,
      13,    0,   76,    2, 0x08 /* Private */,
      14,    2,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 15,   16,   17,

       0        // eod
};

void Chat::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Chat *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->contextMenuEvent((*reinterpret_cast< QContextMenuEvent*(*)>(_a[1]))); break;
        case 1: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 2: _t->on_btn_file_clicked(); break;
        case 3: _t->on_btn_send_clicked(); break;
        case 4: _t->on_btn_logOut_clicked(); break;
        case 5: _t->on_show_users_clicked(); break;
        case 6: _t->deleteSeedSlot(); break;
        case 7: _t->clearSeedsSlot(); break;
        case 8: _t->editSeedsSlot(); break;
        case 9: _t->on_list_users_currentItemChanged((*reinterpret_cast< QListWidgetItem*(*)>(_a[1])),(*reinterpret_cast< QListWidgetItem*(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Chat::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Chat.data,
    qt_meta_data_Chat,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Chat::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Chat::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Chat.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Chat::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
