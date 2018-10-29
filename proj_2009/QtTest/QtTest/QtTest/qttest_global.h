#ifndef QTTEST_GLOBAL_H
#define QTTEST_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef QTTEST_LIB
# define QTTEST_EXPORT Q_DECL_EXPORT
#else
# define QTTEST_EXPORT Q_DECL_IMPORT
#endif

#endif // QTTEST_GLOBAL_H
