#define Py_LIMITED_API
#include <Python.h>

PyObject * resize(PyObject *, PyObject *);

// Workaround missing variadic function support
// https://github.com/golang/go/issues/975
// int PyArg_ParseTuple_LL(PyObject * args, long long * a, long long * b) {
//     return PyArg_ParseTuple(args, "LL", a, b);
// }

int PyArg_ParseTuple_SII(PyObject * args, char **a, long long *b,  long long *c) {
    return PyArg_ParseTuple(args, "sLL", a, b, c);
}

static PyMethodDef PiumaMethods[] = {
    {"resize", resize, METH_VARARGS, "Resize image given a path."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef piumamodule = {
   PyModuleDef_HEAD_INIT, "piuma", NULL, -1, PiumaMethods
};

PyMODINIT_FUNC
PyInit_piuma(void)
{
    return PyModule_Create(&piumamodule);
}

