#define Py_LIMITED_API
#include <Python.h>
#include "libnewmath.h"

PyObject *faster_list_sum(PyObject *obj, PyObject *args)
{
    PyObject *list = NULL;
    if (PyArg_ParseTuple(args, "O", &list) == 0 && PyList_Check(list) != 0)
    {
        return NULL;
    }
    long sum = 0;
    long len = PyObject_Length(list);

    PyObject *item = NULL;

    for (int index = 0; index < len; index++)
    {
        item = PyList_GetItem(list, index);
        if (PyLong_Check(item) == 0)
        {
            sum += 0;
        }
        sum += PyLong_AsLong(item);
    }
    return PyLong_FromLong(sum);
}

PyObject *csum_wrapper(PyObject *obj, PyObject *args)
{
    const long a, b;

    if (!PyArg_ParseTuple(args, "LL", &a, &b))
        return NULL;

    return PyLong_FromLong(csum(a, b));
}

static PyMethodDef NewMathMethods[] = {
    {"sum", sum, METH_VARARGS, "Add two numbers."},
    {"csum", csum_wrapper, METH_VARARGS, "Add two numbers directly in Go."},
    {"listsum", listsum, METH_VARARGS, "Add list of numbers."},
    {"faster_list_sum", faster_list_sum, METH_VARARGS, "Add list of numbers."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef newmathmodule = {
    PyModuleDef_HEAD_INIT, "newmath", NULL, -1, NewMathMethods};

PyMODINIT_FUNC
PyInit_newmath(void)
{
    return PyModule_Create(&newmathmodule);
}
