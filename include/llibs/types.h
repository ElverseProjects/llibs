#ifndef LTYPES_H_
#define LTYPES_H_

#include <stdbool.h>
#include <stddef.h>

// Basic types

typedef signed char         li8;
typedef unsigned char       lu8;
typedef signed short        li16;
typedef unsigned short      lu16;
typedef signed int          li32;
typedef unsigned int        lu32;
typedef signed long long    li64;
typedef unsigned long long  lu64;
typedef float               lf32;
typedef double              lf64;
typedef long double         lflong;

typedef bool                lbool;

typedef const char*         lcstr;

typedef unsigned long long  llen;
typedef unsigned long long  lsize;
typedef signed long long    lssize;

#endif // LTYPES_H_