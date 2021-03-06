#include <Python.h>
#include "../src/API/binary_c_API.h"
#include "binary_c_api.h"

/*
 * binary_c/PYTHON API interface functions
 *
 * Remember: variables must be passed by references
 * (i.e. as pointers).
 *
 * See apitest.py for an expmple of how to use these functions.
 *
 * See also
 * http://www-h.eng.cam.ac.uk/help/tpl/languages/mixinglanguages.html
 */

/* list of variables used in the Py<>C interface */

/************************************************************/
/*
 * function prototypes : these are the functions
 * called by PYTHON code, without the trailing underscore.
 */
/************************************************************/


static char module_docstring[] =
  "This module is a python wrapper around binary_c";
static char create_binary_docstring[] =
  "Allocate memory for a binary";
static char run_binary_docstring[] =
  "Run one binary using binary_c";
static char function_prototype_docstring[] =
  "The prototype for a binary_c python function";

static PyObject* binary_c_create_binary(PyObject *self, PyObject *args){

  double var1, var2;
  char* empty_str = "";
  int i;
  int N = 1;


  /* Parse the input tuple */
  if (!PyArg_ParseTuple(args, "dd", &var1, &var2))
    return NULL;


  /* Binary structures */
  struct libbinary_c_stardata_t *stardata[N];
  struct libbinary_c_store_t *store = NULL;

  /* Allocate memory for binaries */
  for(i=0;i<N;i++){
    stardata[i] = NULL;
    binary_c_new_system(&stardata[i], NULL, NULL, &store, &empty_str, -1);
  }


  /* Return the evolved binary */
  PyObject *ret = Py_BuildValue("");

  return ret;
}

static PyObject* binary_c_run_binary(PyObject *self, PyObject *args){

  int out, ktype_1, ktype_2, comenv_count;
  double m1, m2, orbital_period, eccentricity, metallicity, maxt;
  double m1_out, m2_out, orbital_separation_out, eccentricity_out;

  /* Parse the input tuple */
  // if (!PyArg_ParseTuple(args, "ddddddd", &m1, &m2, &orbital_period, &eccentricity, &metallicity, &maxt, &sn_kick_magnitude_1))
  if (!PyArg_ParseTuple(args, "dddddd", &m1, &m2, &orbital_period, &eccentricity, &metallicity, &maxt))
    return NULL;


  out =  run_binary(m1, m2, orbital_period, eccentricity, metallicity, maxt,
                    &m1_out, &m2_out, &orbital_separation_out, &eccentricity_out,
                    &ktype_1, &ktype_2);

  /* Return variables */
  PyObject *ret = Py_BuildValue("ddddii", m1_out, m2_out, orbital_separation_out, eccentricity_out, ktype_1, ktype_2);

  return ret;
}

static PyObject* binary_c_function_prototype(PyObject *self, PyObject *args){

  double var1, var2;
  char* empty_str = "";

  /* Parse the input tuple */
  if (!PyArg_ParseTuple(args, "dd", &var1, &var2))
    return NULL;



  /* Return the evolved binary */
  PyObject *ret = Py_BuildValue("");

  return ret;
}

static PyMethodDef module_methods[] = {
    {"create_binary", binary_c_create_binary, METH_VARARGS, create_binary_docstring},
    {"run_binary", binary_c_run_binary, METH_VARARGS, run_binary_docstring},
    {"function_prototype", binary_c_function_prototype, METH_VARARGS, function_prototype_docstring},
    {NULL, NULL, 0, NULL} // 'sentinel'??
};

PyMODINIT_FUNC PyInit_binary_c(void){
  (void) PyModule_Create("binary_c", module_methods);
}
