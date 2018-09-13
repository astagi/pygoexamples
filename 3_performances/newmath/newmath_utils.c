#define Py_LIMITED_API
#include <Python.h>

int PyArg_ParseTuple_LL(PyObject * args, long long * a, long long * b) {
    return PyArg_ParseTuple(args, "LL", a, b);
}

int PyArg_ParseTuple_O(PyObject * args, PyObject ** o) {
    return PyArg_ParseTuple(args, "O", o);
}

int is_a_list(PyObject * p) {
    return PyList_Check(p);
}

int is_a_long(PyObject * p) {
    return PyLong_Check(p);
}