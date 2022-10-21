/****************************************************************************
** Meta object code from reading C++ file 'registration.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "src/gui/registration.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registration.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Registration_t {
    QByteArrayData data[19];
    char stringdata0[237];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Registration_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Registration_t qt_meta_stringdata_Registration = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Registration"
QT_MOC_LITERAL(1, 13, 18), // "on_btn_reg_clicked"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 21), // "on_btn_cancel_clicked"
QT_MOC_LITERAL(4, 55, 24), // "on_input_name_textEdited"
QT_MOC_LITERAL(5, 80, 4), // "arg1"
QT_MOC_LITERAL(6, 85, 24), // "on_input_conf_textEdited"
QT_MOC_LITERAL(7, 110, 10), // "closeEvent"
QT_MOC_LITERAL(8, 121, 12), // "QCloseEvent*"
QT_MOC_LITERAL(9, 134, 5), // "event"
QT_MOC_LITERAL(10, 140, 24), // "on_input_pass_textEdited"
QT_MOC_LITERAL(11, 165, 13), // "analysis_pass"
QT_MOC_LITERAL(12, 179, 5), // "bool&"
QT_MOC_LITERAL(13, 185, 9), // "uppercase"
QT_MOC_LITERAL(14, 195, 9), // "lowercase"
QT_MOC_LITERAL(15, 205, 6), // "number"
QT_MOC_LITERAL(16, 212, 7), // "symbols"
QT_MOC_LITERAL(17, 220, 11), // "std::string"
QT_MOC_LITERAL(18, 232, 4) // "pass"

    },
    "Registration\0on_btn_reg_clicked\0\0"
    "on_btn_cancel_clicked\0on_input_name_textEdited\0"
    "arg1\0on_input_conf_textEdited\0closeEvent\0"
    "QCloseEvent*\0event\0on_input_pass_textEdited\0"
    "analysis_pass\0bool&\0uppercase\0lowercase\0"
    "number\0symbols\0std::string\0pass"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Registration[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    1,   51,    2, 0x08 /* Private */,
       6,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      11,    5,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 12, 0x80000000 | 12, 0x80000000 | 12, 0x80000000 | 17,   13,   14,   15,   16,   18,

       0        // eod
};

void Registration::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Registration *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_reg_clicked(); break;
        case 1: _t->on_btn_cancel_clicked(); break;
        case 2: _t->on_input_name_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_input_conf_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 5: _t->on_input_pass_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->analysis_pass((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< std::string(*)>(_a[5]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Registration::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Registration.data,
    qt_meta_data_Registration,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Registration::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Registration::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Registration.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Registration::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
