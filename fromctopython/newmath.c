#define Py_LIMITED_API
#include <Python.h>

static PyObject *
sum(PyObject *self, PyObject *args)
{
    const int a, b;

    if (!PyArg_ParseTuple(args, "ii", &a, &b))
        return NULL;

    return PyLong_FromLong(a + b);
}

static PyMethodDef MathMethods[] = {
    {"sum", sum, METH_VARARGS, "Add two numbers."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef newmathmodule = {
   PyModuleDef_HEAD_INIT, "math", NULL, -1, MathMethods
};

PyMODINIT_FUNC
PyInit_newmath(void)
{
    return PyModule_Create(&newmathmodule);
}
