// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from canopen_interfaces:srv/COWriteID.idl
// generated code does not contain a copyright notice
#include "canopen_interfaces/srv/detail/co_write_id__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "canopen_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "canopen_interfaces/srv/detail/co_write_id__struct.h"
#include "canopen_interfaces/srv/detail/co_write_id__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _COWriteID_Request__ros_msg_type = canopen_interfaces__srv__COWriteID_Request;

static bool _COWriteID_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _COWriteID_Request__ros_msg_type * ros_message = static_cast<const _COWriteID_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: nodeid
  {
    cdr << ros_message->nodeid;
  }

  // Field name: index
  {
    cdr << ros_message->index;
  }

  // Field name: subindex
  {
    cdr << ros_message->subindex;
  }

  // Field name: data
  {
    cdr << ros_message->data;
  }

  // Field name: canopen_datatype
  {
    cdr << ros_message->canopen_datatype;
  }

  return true;
}

static bool _COWriteID_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _COWriteID_Request__ros_msg_type * ros_message = static_cast<_COWriteID_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: nodeid
  {
    cdr >> ros_message->nodeid;
  }

  // Field name: index
  {
    cdr >> ros_message->index;
  }

  // Field name: subindex
  {
    cdr >> ros_message->subindex;
  }

  // Field name: data
  {
    cdr >> ros_message->data;
  }

  // Field name: canopen_datatype
  {
    cdr >> ros_message->canopen_datatype;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_canopen_interfaces
size_t get_serialized_size_canopen_interfaces__srv__COWriteID_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _COWriteID_Request__ros_msg_type * ros_message = static_cast<const _COWriteID_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name nodeid
  {
    size_t item_size = sizeof(ros_message->nodeid);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name index
  {
    size_t item_size = sizeof(ros_message->index);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name subindex
  {
    size_t item_size = sizeof(ros_message->subindex);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name data
  {
    size_t item_size = sizeof(ros_message->data);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name canopen_datatype
  {
    size_t item_size = sizeof(ros_message->canopen_datatype);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _COWriteID_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_canopen_interfaces__srv__COWriteID_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_canopen_interfaces
size_t max_serialized_size_canopen_interfaces__srv__COWriteID_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: nodeid
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: index
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint16_t);
    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: subindex
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: data
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: canopen_datatype
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = canopen_interfaces__srv__COWriteID_Request;
    is_plain =
      (
      offsetof(DataType, canopen_datatype) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _COWriteID_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_canopen_interfaces__srv__COWriteID_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_COWriteID_Request = {
  "canopen_interfaces::srv",
  "COWriteID_Request",
  _COWriteID_Request__cdr_serialize,
  _COWriteID_Request__cdr_deserialize,
  _COWriteID_Request__get_serialized_size,
  _COWriteID_Request__max_serialized_size
};

static rosidl_message_type_support_t _COWriteID_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_COWriteID_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, canopen_interfaces, srv, COWriteID_Request)() {
  return &_COWriteID_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "canopen_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "canopen_interfaces/srv/detail/co_write_id__struct.h"
// already included above
// #include "canopen_interfaces/srv/detail/co_write_id__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _COWriteID_Response__ros_msg_type = canopen_interfaces__srv__COWriteID_Response;

static bool _COWriteID_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _COWriteID_Response__ros_msg_type * ros_message = static_cast<const _COWriteID_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _COWriteID_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _COWriteID_Response__ros_msg_type * ros_message = static_cast<_COWriteID_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_canopen_interfaces
size_t get_serialized_size_canopen_interfaces__srv__COWriteID_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _COWriteID_Response__ros_msg_type * ros_message = static_cast<const _COWriteID_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _COWriteID_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_canopen_interfaces__srv__COWriteID_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_canopen_interfaces
size_t max_serialized_size_canopen_interfaces__srv__COWriteID_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: success
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = canopen_interfaces__srv__COWriteID_Response;
    is_plain =
      (
      offsetof(DataType, success) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _COWriteID_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_canopen_interfaces__srv__COWriteID_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_COWriteID_Response = {
  "canopen_interfaces::srv",
  "COWriteID_Response",
  _COWriteID_Response__cdr_serialize,
  _COWriteID_Response__cdr_deserialize,
  _COWriteID_Response__get_serialized_size,
  _COWriteID_Response__max_serialized_size
};

static rosidl_message_type_support_t _COWriteID_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_COWriteID_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, canopen_interfaces, srv, COWriteID_Response)() {
  return &_COWriteID_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "canopen_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "canopen_interfaces/srv/co_write_id.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t COWriteID__callbacks = {
  "canopen_interfaces::srv",
  "COWriteID",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, canopen_interfaces, srv, COWriteID_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, canopen_interfaces, srv, COWriteID_Response)(),
};

static rosidl_service_type_support_t COWriteID__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &COWriteID__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, canopen_interfaces, srv, COWriteID)() {
  return &COWriteID__handle;
}

#if defined(__cplusplus)
}
#endif
