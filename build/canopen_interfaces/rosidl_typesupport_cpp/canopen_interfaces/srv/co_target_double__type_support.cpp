// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from canopen_interfaces:srv/COTargetDouble.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "canopen_interfaces/srv/detail/co_target_double__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace canopen_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _COTargetDouble_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _COTargetDouble_Request_type_support_ids_t;

static const _COTargetDouble_Request_type_support_ids_t _COTargetDouble_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _COTargetDouble_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _COTargetDouble_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _COTargetDouble_Request_type_support_symbol_names_t _COTargetDouble_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, canopen_interfaces, srv, COTargetDouble_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, canopen_interfaces, srv, COTargetDouble_Request)),
  }
};

typedef struct _COTargetDouble_Request_type_support_data_t
{
  void * data[2];
} _COTargetDouble_Request_type_support_data_t;

static _COTargetDouble_Request_type_support_data_t _COTargetDouble_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _COTargetDouble_Request_message_typesupport_map = {
  2,
  "canopen_interfaces",
  &_COTargetDouble_Request_message_typesupport_ids.typesupport_identifier[0],
  &_COTargetDouble_Request_message_typesupport_symbol_names.symbol_name[0],
  &_COTargetDouble_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t COTargetDouble_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_COTargetDouble_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace canopen_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<canopen_interfaces::srv::COTargetDouble_Request>()
{
  return &::canopen_interfaces::srv::rosidl_typesupport_cpp::COTargetDouble_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, canopen_interfaces, srv, COTargetDouble_Request)() {
  return get_message_type_support_handle<canopen_interfaces::srv::COTargetDouble_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "canopen_interfaces/srv/detail/co_target_double__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace canopen_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _COTargetDouble_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _COTargetDouble_Response_type_support_ids_t;

static const _COTargetDouble_Response_type_support_ids_t _COTargetDouble_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _COTargetDouble_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _COTargetDouble_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _COTargetDouble_Response_type_support_symbol_names_t _COTargetDouble_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, canopen_interfaces, srv, COTargetDouble_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, canopen_interfaces, srv, COTargetDouble_Response)),
  }
};

typedef struct _COTargetDouble_Response_type_support_data_t
{
  void * data[2];
} _COTargetDouble_Response_type_support_data_t;

static _COTargetDouble_Response_type_support_data_t _COTargetDouble_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _COTargetDouble_Response_message_typesupport_map = {
  2,
  "canopen_interfaces",
  &_COTargetDouble_Response_message_typesupport_ids.typesupport_identifier[0],
  &_COTargetDouble_Response_message_typesupport_symbol_names.symbol_name[0],
  &_COTargetDouble_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t COTargetDouble_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_COTargetDouble_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace canopen_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<canopen_interfaces::srv::COTargetDouble_Response>()
{
  return &::canopen_interfaces::srv::rosidl_typesupport_cpp::COTargetDouble_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, canopen_interfaces, srv, COTargetDouble_Response)() {
  return get_message_type_support_handle<canopen_interfaces::srv::COTargetDouble_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "canopen_interfaces/srv/detail/co_target_double__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace canopen_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _COTargetDouble_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _COTargetDouble_type_support_ids_t;

static const _COTargetDouble_type_support_ids_t _COTargetDouble_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _COTargetDouble_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _COTargetDouble_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _COTargetDouble_type_support_symbol_names_t _COTargetDouble_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, canopen_interfaces, srv, COTargetDouble)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, canopen_interfaces, srv, COTargetDouble)),
  }
};

typedef struct _COTargetDouble_type_support_data_t
{
  void * data[2];
} _COTargetDouble_type_support_data_t;

static _COTargetDouble_type_support_data_t _COTargetDouble_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _COTargetDouble_service_typesupport_map = {
  2,
  "canopen_interfaces",
  &_COTargetDouble_service_typesupport_ids.typesupport_identifier[0],
  &_COTargetDouble_service_typesupport_symbol_names.symbol_name[0],
  &_COTargetDouble_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t COTargetDouble_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_COTargetDouble_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace canopen_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<canopen_interfaces::srv::COTargetDouble>()
{
  return &::canopen_interfaces::srv::rosidl_typesupport_cpp::COTargetDouble_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_cpp, canopen_interfaces, srv, COTargetDouble)() {
  return ::rosidl_typesupport_cpp::get_service_type_support_handle<canopen_interfaces::srv::COTargetDouble>();
}

#ifdef __cplusplus
}
#endif
