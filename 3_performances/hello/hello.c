#define Py_LIMITED_API
#include <Python.h>
#include "libhello.h"

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

static PyMethodDef HelloMethods[] = {
    {"say_hello", _say_hello, METH_VARARGS, "Say Hello to someone!"},
    {"say_hello_slowly", _say_hello_slowly, METH_VARARGS, "Say Hello to someone, slowly!"},
    {"say_hello_faster", _say_hello_faster, METH_VARARGS, "Say Hello to someone, faster!"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef hellomodule = {
   PyModuleDef_HEAD_INIT, "hello", NULL, -1, HelloMethods
};

PyMODINIT_FUNC
PyInit_hello(void)
{
    return PyModule_Create(&hellomodule);
}
