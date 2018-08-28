#define Py_LIMITED_API
#include <Python.h>
#include "newmath.h"

PyObject * sum(PyObject *, PyObject *);
PyObject * listsum(PyObject *, PyObject *);

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

PyObject * _say_hello_faster(PyObject *obj, PyObject *args)
{
    PyObject *py_retval;
    char *path;
    long long count;

    if (!PyArg_ParseTuple(args, (char *) "sL", &path, &count)) {
        return NULL;
    }

    sayHelloFaster(path, count);
    Py_RETURN_NONE;
}

PyObject * _say_hello_slowly(PyObject *obj, PyObject *args)
{
    PyObject *py_retval;
    char *path;

    if (!PyArg_ParseTuple(args, (char *) "s", &path)) {
        return NULL;
    }

    char *retval = sayHelloSlowly(path);
    py_retval = Py_BuildValue((char *) "s", retval);
    return py_retval;
}

PyObject * _say_hello(PyObject *obj, PyObject *args)
{
    PyObject *py_retval;
    char *path;

    if (!PyArg_ParseTuple(args, (char *) "s", &path)) {
        return NULL;
    }
    GoString gostr = {p: path, strlen(path)};
    GoString retval = sayHello(gostr);
    py_retval = Py_BuildValue((char *) "s", retval.p);
    return py_retval;
}

PyObject * faster_list_sum(PyObject *obj, PyObject *args)
{
    PyObject *list = NULL;
    if (PyArg_ParseTuple(args, "O", &list) == 0 && PyList_Check(list) != 0){
        return NULL;
    }
    long sum = 0;
    long len = PyObject_Length(list);

    PyObject * item = NULL;

    for (int index = 0 ; index < len ; index++) {
        item = PyList_GetItem(list, index);
        if (PyLong_Check(item) == 0) {
            sum += 0;
        }
        sum += PyLong_AsLong(item);
    }
    return PyLong_FromLong(sum);
}

static PyMethodDef NewMathMethods[] = {
    {"sum", sum, METH_VARARGS, "Add two numbers."},
    {"listsum", listsum, METH_VARARGS, "Add list of numbers."},
    {"faster_list_sum", faster_list_sum, METH_VARARGS, "Add list of numbers."},
    {"say_hello", _say_hello, METH_VARARGS, "Say Hello to someone!"},
    {"say_hello_slowly", _say_hello_slowly, METH_VARARGS, "Say Hello to someone, slowly!"},
    {"say_hello_faster", _say_hello_faster, METH_VARARGS, "Say Hello to someone, faster!"},
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
