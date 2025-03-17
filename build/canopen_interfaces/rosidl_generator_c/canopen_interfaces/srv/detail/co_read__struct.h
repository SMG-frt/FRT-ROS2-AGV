// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from canopen_interfaces:srv/CORead.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_READ__STRUCT_H_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_READ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/CORead in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__CORead_Request
{
  uint16_t index;
  uint8_t subindex;
} canopen_interfaces__srv__CORead_Request;

// Struct for a sequence of canopen_interfaces__srv__CORead_Request.
typedef struct canopen_interfaces__srv__CORead_Request__Sequence
{
  canopen_interfaces__srv__CORead_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__CORead_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/CORead in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__CORead_Response
{
  bool success;
  uint32_t data;
} canopen_interfaces__srv__CORead_Response;

// Struct for a sequence of canopen_interfaces__srv__CORead_Response.
typedef struct canopen_interfaces__srv__CORead_Response__Sequence
{
  canopen_interfaces__srv__CORead_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__CORead_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_READ__STRUCT_H_
