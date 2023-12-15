#ifndef HTSYSTEM_GLOBAL_H
#define HTSYSTEM_GLOBAL_H

#include <QtCore/qglobal.h>
#include<iostream>
#include<fstream>
#include<string>//int d, h, m, s;
#include<time.h>
#include<vector>
#include<sstream>
using namespace std;

#if defined(HTSYSTEM_LIBRARY)
#define HTSYSTEM_EXPORT Q_DECL_EXPORT
#else
#define HTSYSTEM_EXPORT Q_DECL_IMPORT
#endif

#endif // HTSYSTEM_GLOBAL_H
