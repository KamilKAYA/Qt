/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.12.10
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // /Users/kamilkaya/Documents/GitHub/Qt/QML/01_introduction/QML_intro/main.qml
  0x0,0x0,0x0,0x98,
  0x69,
  0x6d,0x70,0x6f,0x72,0x74,0x20,0x51,0x74,0x51,0x75,0x69,0x63,0x6b,0x20,0x32,0x2e,
  0x39,0xa,0x69,0x6d,0x70,0x6f,0x72,0x74,0x20,0x51,0x74,0x51,0x75,0x69,0x63,0x6b,
  0x2e,0x57,0x69,0x6e,0x64,0x6f,0x77,0x20,0x32,0x2e,0x32,0xa,0xa,0x57,0x69,0x6e,
  0x64,0x6f,0x77,0x20,0x7b,0xa,0x20,0x20,0x20,0x20,0x69,0x64,0x3a,0x20,0x77,0x69,
  0x6e,0x64,0x6f,0x77,0xa,0x20,0x20,0x20,0x20,0x77,0x69,0x64,0x74,0x68,0x3a,0x20,
  0x36,0x34,0x30,0xa,0x20,0x20,0x20,0x20,0x68,0x65,0x69,0x67,0x68,0x74,0x3a,0x20,
  0x34,0x38,0x30,0xa,0x20,0x20,0x20,0x20,0x76,0x69,0x73,0x69,0x62,0x6c,0x65,0x3a,
  0x20,0x74,0x72,0x75,0x65,0xa,0x20,0x20,0x20,0x20,0x74,0x69,0x74,0x6c,0x65,0x3a,
  0x20,0x71,0x73,0x54,0x72,0x28,0x22,0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,
  0x6c,0x64,0x22,0x29,0xa,0x7d,0xa,
  
};

static const unsigned char qt_resource_name[] = {
  // main.qml
  0x0,0x8,
  0x8,0x1,0x5a,0x5c,
  0x0,0x6d,
  0x0,0x61,0x0,0x69,0x0,0x6e,0x0,0x2e,0x0,0x71,0x0,0x6d,0x0,0x6c,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/main.qml
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x77,0xf4,0x85,0x2d,0x3d,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_main)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_main)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_main)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_main)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_main)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_main)(); }
   } dummy;
}
