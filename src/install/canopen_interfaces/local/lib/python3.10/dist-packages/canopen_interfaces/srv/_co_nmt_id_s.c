// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from canopen_interfaces:srv/CONmtID.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "canopen_interfaces/srv/detail/co_nmt_id__struct.h"
#include "canopen_interfaces/srv/detail/co_nmt_id__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool canopen_interfaces__srv__co_nmt_id__request__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("canopen_interfaces.srv._co_nmt_id.CONmtID_Request", full_classname_dest, 49) == 0);
  }
  canopen_interfaces__srv__CONmtID_Request * ros_message = _ros_message;
  {  // nmtcommand
    PyObject * field = PyObject_GetAttrString(_pymsg, "nmtcommand");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->nmtcommand = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // nodeid
    PyObject * field = PyObject_GetAttrString(_pymsg, "nodeid");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->nodeid = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * canopen_interfaces__srv__co_nmt_id__request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CONmtID_Request */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("canopen_interfaces.srv._co_nmt_id");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CONmtID_Request");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  canopen_interfaces__srv__CONmtID_Request * ros_message = (canopen_interfaces__srv__CONmtID_Request *)raw_ros_message;
  {  // nmtcommand
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->nmtcommand);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nmtcommand", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // nodeid
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->nodeid);
    {
      int rc = PyObject_SetAttrString(_pymessage, "nodeid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
// already included above
// #include <Python.h>
// already included above
// #include <stdbool.h>
// already included above
// #include "numpy/ndarrayobject.h"
// already included above
// #include "rosidl_runtime_c/visibility_control.h"
// already included above
// #include "canopen_interfaces/srv/detail/co_nmt_id__struct.h"
// already included above
// #include "canopen_interfaces/srv/detail/co_nmt_id__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool canopen_interfaces__srv__co_nmt_id__response__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[51];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("canopen_interfaces.srv._co_nmt_id.CONmtID_Response", full_classname_dest, 50) == 0);
  }
  canopen_interfaces__srv__CONmtID_Response * ros_message = _ros_message;
  {  // success
    PyObject * field = PyObject_GetAttrString(_pymsg, "success");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->success = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * canopen_interfaces__srv__co_nmt_id__response__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CONmtID_Response */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("canopen_interfaces.srv._co_nmt_id");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CONmtID_Response");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  canopen_interfaces__srv__CONmtID_Response * ros_message = (canopen_interfaces__srv__CONmtID_Response *)raw_ros_message;
  {  // success
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->success ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "success", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
