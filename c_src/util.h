#ifndef __LIBGIT_UTIL_H__
#define __LIBGIT_UTIL_H__

#include "pythonapi.h"


typedef struct {
    const char* name;
    PyTypeObject* typeobj;
} NamedTypes;

bool util_types_ready(NamedTypes types[]);
bool util_types_add(PyObject* m, NamedTypes types[]);
bool util_types_release(NamedTypes types[]);


typedef enum { INT, STRING } KType;
typedef struct {
    const char* name;
    KType type;
    int i;
    const char* s;
} NamedConstants;

bool util_add_constants(PyObject* m, NamedConstants constants[]);


#endif //__LIBGIT_UTIL_H__
