
#include "util.h"


bool util_types_ready(NamedTypes types[])
{
    int i = 0;
    while(types[i].name != NULL) {
        if (PyType_Ready(types[i].typeobj) < 0)
            return false;
        i++;
    }
    return true;
}


bool util_types_add(PyObject* m, NamedTypes types[])
{
    int i = 0;
    while(types[i].name != NULL) {
        Py_INCREF(types[i].typeobj);
        if (PyModule_AddObject(m, types[i].name, (PyObject *) types[i].typeobj) < 0) {
            while (i >= 0) {
                Py_DECREF(types[i].typeobj);
                i--;
            }
            return false;
        }
        i++;
    }
    return true;
}


bool util_types_release(NamedTypes types[])
{
    int i = 0;
    while(types[i].name != NULL) {
        Py_DECREF(types[i].typeobj);
        i++;
    }
    return true;
}


bool util_add_constants(PyObject* m, NamedConstants constants[])
{
    int i = 0;
    while(constants[i].name != NULL) {
        switch(constants[i].type) {
        case INT:
            if (PyModule_AddIntConstant(m, constants[i].name, constants[i].i) == -1)
                return false;
            break;
        case STRING:
            if (PyModule_AddStringConstant(m, constants[i].name, constants[i].s) == -1)
                return false;
            break;
        }
        i++;
    }

    return true;
}
