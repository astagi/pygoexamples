package main

// #cgo pkg-config: python3
// #define Py_LIMITED_API
// #include <Python.h>
// int PyArg_ParseTuple_SII(PyObject *, char**,  long long *,  long long *);
import "C"
import "fmt"

//export resize
func resize(self, args *C.PyObject) *C.PyObject {
    //var path *C.char
    var height, width C.longlong
    var path *C.char

    if C.PyArg_ParseTuple_SII(args, &path, &height, &width) == 0 {
        return nil
    }
    str := C.GoString(path)
    fmt.Println(str)
    return C.PyLong_FromLongLong(height + width)
}

func main() {}
