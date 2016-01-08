#include <Python.h>
#include <twait.h>

static PyObject *twait_py_start_io_thread(PyObject *self, PyObject *args) {
    /* unsigned int numberToCheck; */

    /* if (!PyArg_ParseTuple(args, "I", &numberToCheck)) */
    /*     return NULL; */

   start_io_thread(); 

    return Py_BuildValue("i", 200);
}


static PyMethodDef TwaitMethods[] = {
    {"start_io_thread",  twait_py_start_io_thread, METH_VARARGS,
     "Starts io thread"},
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC inittwait(void) {
    (void) Py_InitModule("twait", TwaitMethods);
}
