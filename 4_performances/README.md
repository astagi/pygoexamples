#define PyList_CheckExact(op) (Py_TYPE(op) == &PyList_Type)



cat /Library/Frameworks/Python.framework/Versions/3.6/include/python3.6m/listobject.h | grep Check
