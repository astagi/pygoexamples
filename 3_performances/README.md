#define PyList_CheckExact(op) (Py_TYPE(op) == &PyList_Type)



cat /Library/Frameworks/Python.framework/Versions/3.6/include/python3.6m/listobject.h | grep Check
In the directory containing the package, .go, .c, .h, and .s files are considered part of the package except for:


- .go files in package documentation
- files starting with _ or . (likely editor temporary files)
- files with build constraints not satisfied by the context