package main

// #cgo pkg-config: python3
// #cgo LDFLAGS: -L/Library/Frameworks/Python.framework/Versions/3.8/lib -lpython3.8 -ldl -framework CoreFoundation
// #define PY_SSIZE_T_CLEAN
// #include <Python.h>
// int PyArg_ParseTuple_LL(PyObject *, long long *, long long *);
import "C"

//export sum
func sum(self, args *C.PyObject) *C.PyObject {
    var a, b C.longlong
    if C.PyArg_ParseTuple_LL(args, &a, &b) == 0 {
        return nil
    }
    return C.PyLong_FromLongLong(a + b)
}

func main() {}
