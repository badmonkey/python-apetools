
#include "libgit2api.h"
#include "util.h"


static PyObject *
git2bind_clone(PyObject *self, PyObject *args)
{
    git_repository *cloned_repo = NULL;
	git_clone_options clone_opts = GIT_CLONE_OPTIONS_INIT;

    const char *url = "url";
	const char *path = "path";
	int error;

    error = git_clone(&cloned_repo, url, path, &clone_opts);
    return NULL;
}


static PyMethodDef git2Methods[] = {
    {"clone",  git2bind_clone, METH_VARARGS,
     "Clone a repository."},

    {NULL, NULL, 0, NULL}        /* Sentinel */
};

// Our Module Definition struct
static struct PyModuleDef git2Module = {
    PyModuleDef_HEAD_INIT,
    .m_name = "_libgit",
    .m_doc = PyDoc_STR("Bindings for working with libgit2"),
    .m_size = -1,
    .m_methods = git2Methods,
};


static NamedTypes git2Types[] = {
    {"Repository", &RepositoryType},
    {NULL, NULL}
};


static NamedConstants git2Constants[] = {
    {"VERSION", INT, 1, NULL},
    {"THING", STRING, 0, "This thing"},
    {NULL, INT, 0, NULL}
};


#define MOD_INIT(name) PyMODINIT_FUNC PyInit_##name(void)


// Initializes our module using our above struct
PyMODINIT_FUNC PyInit__libgit(void)
{
    PyObject* m;

    if (!util_types_ready(git2Types))
        return NULL;

    m = PyModule_Create(&git2Module);
    if (m == NULL)
        return NULL;

    if (!util_types_add(m, git2Types)) {
        Py_DECREF(m);

        return NULL;
    }

    if (!util_add_constants(m, git2Constants)) {
        util_types_release(git2Types);
        Py_DECREF(m);

        return NULL;
    }

    return m;
}
