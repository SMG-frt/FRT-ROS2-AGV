// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from canopen_interfaces:srv/COTargetDouble.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_TARGET_DOUBLE__STRUCT_H_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_TARGET_DOUBLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/COTargetDouble in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__COTargetDouble_Request
{
  double target;
} canopen_interfaces__srv__COTargetDouble_Request;

// Struct for a sequence of canopen_interfaces__srv__COTargetDouble_Request.
typedef struct canopen_interfaces__srv__COTargetDouble_Request__Sequence
{
  canopen_interfaces__srv__COTargetDouble_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__COTargetDouble_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/COTargetDouble in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__COTargetDouble_Response
{
  bool success;
} canopen_interfaces__srv__COTargetDouble_Response;

// Struct for a sequence of canopen_interfaces__srv__COTargetDouble_Response.
typedef struct canopen_interfaces__srv__COTargetDouble_Response__Sequence
{
  canopen_interfaces__srv__COTargetDouble_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__COTargetDouble_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_TARGET_DOUBLE__STRUCT_H_
