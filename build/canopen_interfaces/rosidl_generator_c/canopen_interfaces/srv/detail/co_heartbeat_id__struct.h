// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from canopen_interfaces:srv/COHeartbeatID.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_HEARTBEAT_ID__STRUCT_H_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_HEARTBEAT_ID__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/COHeartbeatID in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__COHeartbeatID_Request
{
  uint8_t nodeid;
  /// ms
  uint16_t heartbeat;
} canopen_interfaces__srv__COHeartbeatID_Request;

// Struct for a sequence of canopen_interfaces__srv__COHeartbeatID_Request.
typedef struct canopen_interfaces__srv__COHeartbeatID_Request__Sequence
{
  canopen_interfaces__srv__COHeartbeatID_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__COHeartbeatID_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/COHeartbeatID in the package canopen_interfaces.
typedef struct canopen_interfaces__srv__COHeartbeatID_Response
{
  bool success;
} canopen_interfaces__srv__COHeartbeatID_Response;

// Struct for a sequence of canopen_interfaces__srv__COHeartbeatID_Response.
typedef struct canopen_interfaces__srv__COHeartbeatID_Response__Sequence
{
  canopen_interfaces__srv__COHeartbeatID_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__srv__COHeartbeatID_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_HEARTBEAT_ID__STRUCT_H_
