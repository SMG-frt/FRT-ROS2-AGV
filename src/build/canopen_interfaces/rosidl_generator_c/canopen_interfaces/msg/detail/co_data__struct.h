// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from canopen_interfaces:msg/COData.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__STRUCT_H_
#define CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/COData in the package canopen_interfaces.
typedef struct canopen_interfaces__msg__COData
{
  uint16_t index;
  uint8_t subindex;
  uint32_t data;
} canopen_interfaces__msg__COData;

// Struct for a sequence of canopen_interfaces__msg__COData.
typedef struct canopen_interfaces__msg__COData__Sequence
{
  canopen_interfaces__msg__COData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} canopen_interfaces__msg__COData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__STRUCT_H_
