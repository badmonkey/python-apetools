
#include "pythonapi.h"


typedef struct {
    PyObject_HEAD
    git_repository* _git_repo;

} Repository;


static PyObject *
Repository_new(PyTypeObject* type, PyObject* args, PyObject* kwds)
{
    /* CustomObject *self; */
    /* self = (CustomObject *) type->tp_alloc(type, 0); */
    /* if (self != NULL) { */
    /*     self->first = PyUnicode_FromString(""); */
    /*     if (self->first == NULL) { */
    /*         Py_DECREF(self); */
    /*         return NULL; */
    /*     } */
    /*     self->last = PyUnicode_FromString(""); */
    /*     if (self->last == NULL) { */
    /*         Py_DECREF(self); */
    /*         return NULL; */
    /*     } */
    /*     self->number = 0; */
    /* } */
    /* return (PyObject *) self; */
    return NULL;
}

static void
Repository_dealloc(Repository* self)
{
    /* Py_XDECREF(self->first); */
    /* Py_XDECREF(self->last); */
    /* Py_TYPE(self)->tp_free((PyObject *) self); */
}

static int
Repository_init(Repository* self, PyObject* args, PyObject* kwds)
{
    /* static char *kwlist[] = {"first", "last", "number", NULL}; */
    /* PyObject *first = NULL, *last = NULL, *tmp; */

    /* if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OOi", kwlist, */
    /*                                  &first, &last, */
    /*                                  &self->number)) */
    /*     return -1; */

    /* if (first) { */
    /*     tmp = self->first; */
    /*     Py_INCREF(first); */
    /*     self->first = first; */
    /*     Py_XDECREF(tmp); */
    /* } */
    /* if (last) { */
    /*     tmp = self->last; */
    /*     Py_INCREF(last); */
    /*     self->last = last; */
    /*     Py_XDECREF(tmp); */
    /* } */
    return 0;
}

static PyObject*
Repository_name(Repository* self, PyObject* Py_UNUSED(ignored))
{
    /* if (self->first == NULL) { */
    /*     PyErr_SetString(PyExc_AttributeError, "first"); */
    /*     return NULL; */
    /* } */
    /* if (self->last == NULL) { */
    /*     PyErr_SetString(PyExc_AttributeError, "last"); */
    /*     return NULL; */
    /* } */
    /* return PyUnicode_FromFormat("%S %S", self->first, self->last); */
    return NULL;
}


static PyMemberDef Repository_members[] = {
    /* {"first", T_OBJECT_EX, offsetof(CustomObject, first), 0, */
    /*  "first name"}, */
    /* {"last", T_OBJECT_EX, offsetof(CustomObject, last), 0, */
    /*  "last name"}, */
    /* {"number", T_INT, offsetof(CustomObject, number), 0, */
    /*  "custom number"}, */
    {NULL}  /* Sentinel */
};


static PyMethodDef Repository_methods[] = {
    {"name", (PyCFunction) Repository_name, METH_NOARGS,
     "Return the name, combining the first and last name"
    },
    {NULL}  /* Sentinel */
};


PyTypeObject RepositoryType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "_libgit.Repository",
    .tp_doc = PyDoc_STR("Git Repository"),
    .tp_basicsize = sizeof(Repository),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = Repository_new,
    .tp_init = (initproc) Repository_init,
    .tp_dealloc = (destructor) Repository_dealloc,
    .tp_members = Repository_members,
    .tp_methods = Repository_methods,
};
