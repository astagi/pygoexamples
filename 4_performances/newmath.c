#define Py_LIMITED_API
#include <Python.h>

PyObject * sum(PyObject *, PyObject *);
PyObject * listsum(PyObject *, PyObject **);

int PyArg_ParseTuple_LL(PyObject * args, long long * a, long long * b) {
    return PyArg_ParseTuple(args, "LL", a, b);
}

int PyArg_ParseTuple_O(PyObject * args, PyObject ** o) {
    if (PyLong_CheckExact(args) == 0) {
    
    }
    return PyArg_ParseTuple(args, "O", o);
}

int is_a_list(PyObject * p) {
    return PyList_Check(p);
}

int is_a_long(PyObject * p) {
    return PyLong_Check(p);
}


static PyMethodDef NewMathMethods[] = {
    {"sum", sum, METH_VARARGS, "Add two numbers."},
    {"listsum", listsum, METH_VARARGS, "Add list of numbers."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef newmathmodule = {
   PyModuleDef_HEAD_INIT, "newmath", NULL, -1, NewMathMethods
};

PyMODINIT_FUNC
PyInit_newmath(void)
{
    return PyModule_Create(&newmathmodule);
}
