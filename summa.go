package main

/*

#cgo pkg-config: python3
#define Py_LIMITED_API
#include <Python.h>

static PyObject *
sum(PyObject *self, PyObject *args)
{
    const long long a, b;

    if (!PyArg_ParseTuple(args, "LL", &a, &b))
        return NULL;

    return PyLong_FromLongLong(a + b);
}

static PyMethodDef FooMethods[] = {
    {"sum", sum, METH_VARARGS, "Add two numbers."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef foomodule = {
   PyModuleDef_HEAD_INIT, "summa", NULL, -1, FooMethods
};

PyMODINIT_FUNC
PyInit_summa(void)
{
    return PyModule_Create(&foomodule);
}

*/
import "C"

func main() {}
