#define Py_LIMITED_API
#include <Python.h>

PyObject *sum(PyObject *, PyObject *);

// Workaround missing variadic function support
// https://github.com/golang/go/issues/975
int PyArg_ParseTuple_LL(PyObject *args, long long *a, long long *b)
{
    return PyArg_ParseTuple(args, "LL", a, b);
}

static PyMethodDef NewMathMethods[] = {
    {"sum", sum, METH_VARARGS, "Add two numbers."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef newmathmodule = {
    PyModuleDef_HEAD_INIT, "newmath", NULL, -1, NewMathMethods};

PyMODINIT_FUNC PyInit_newmath(void) {
    return PyModule_Create(&newmathmodule);
}
