package main

// #cgo pkg-config: python3
// #define Py_LIMITED_API
// #include <Python.h>
// int PyArg_ParseTuple_LL(PyObject *, long long *, long long *);
// int PyArg_ParseTuple_O(PyObject *, PyObject **);
// int is_a_list(PyObject *);
// int is_a_long(PyObject *);
import "C"

//export sum
func sum(self, args *C.PyObject) *C.PyObject {
    var a, b C.longlong
    if C.PyArg_ParseTuple_LL(args, &a, &b) == 0 {
        return nil
    }
    return C.PyLong_FromLongLong(a + b)
}

//export listsum
func listsum(self, args *C.PyObject) *C.PyObject {
    var list *C.PyObject
    if (C.PyArg_ParseTuple_O(args, &list) == 0 && C.is_a_list(list) != 0){
        return nil
    }
    var sum C.long = 0
    var len C.long = C.PyObject_Length(list)
    var index C.long = 0

    for index = 0 ; index < len ; index++ {
        var item *C.PyObject = C.PyList_GetItem(list, index);
        if (C.is_a_long(item) == 0) {
            sum += 0;
        }
        sum += C.PyLong_AsLong(item);
    }
    return C.PyLong_FromLong(sum)
}

func main() {}
