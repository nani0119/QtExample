#ifndef BARCHART_GLOBAL_H
#define BARCHART_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BARCHART_LIBRARY)
#  define BARCHART_EXPORT Q_DECL_EXPORT
#else
#  define BARCHART_EXPORT Q_DECL_IMPORT
#endif

#endif // BARCHART_GLOBAL_H
