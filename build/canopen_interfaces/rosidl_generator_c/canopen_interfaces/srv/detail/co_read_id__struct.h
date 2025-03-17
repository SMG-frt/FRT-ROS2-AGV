// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from canopen_interfaces:srv/COReadID.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_READ_ID__STRUCT_H_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_READ_ID__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'CANOPEN_DATATYPE_INT8'.
enum
{
  canopen_interfaces__srv__COReadID_Request__CANOPEN_DATATYPE_INT8 = 2
};

/// Constant 'CANOPEN_DATATYPE_INT16'.
enum
{
  canopen_interfaces__srv__COReadID_Request__CANOPEN_DATATYPE_INT16 = 3
};

/// Constant 'CANOPEN_DATATYPE_INT32'.
enum
{
  canopen_interfaces__srv__COReadID_Request__CANOPEN_DATATYPE_INT32 = 4
};

/// Constant 'CANOPEN_DATATYPE_UINT8'.
enum
{
  canopen_interfaces__srv__COReadID_Request__CANOPEN_DATATYPE_UINT8 = 5
};

/// Constant 'CANOPEN_DATATYPE_UINT16'.
enum
{
  canopen_interfaces__srv__COReadID_Request__CANOPEN_DATATYPE_UINT16 = 6
};

/// Constant 'CANOPEN_DATATYPE_UINT32'.
enum
{
  canopen_interfaces__srv__COReadID_Request__CANOPEN_DATATYPE_UINT32 = 7
};

/// Struct defined in srv/COReadID in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__COReadID_Request
{
  uint8_t nodeid;
  uint16_t index;
  uint8_t subindex;
  /// 8 = uint8_t, 16 = uint16_t, 32 = uint32_t
  uint8_t canopen_datatype;
} canopen_interfaces__srv__COReadID_Request;

// Struct for a sequence of canopen_interfaces__srv__COReadID_Request.
typedef struct canopen_interfaces__srv__COReadID_Request__Sequence
{
  canopen_interfaces__srv__COReadID_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__COReadID_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/COReadID in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__COReadID_Response
{
  bool success;
  uint32_t data;
} canopen_interfaces__srv__COReadID_Response;

// Struct for a sequence of canopen_interfaces__srv__COReadID_Response.
typedef struct canopen_interfaces__srv__COReadID_Response__Sequence
{
  canopen_interfaces__srv__COReadID_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__COReadID_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_READ_ID__STRUCT_H_
