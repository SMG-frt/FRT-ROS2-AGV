// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from canopen_interfaces:srv/COTargetDouble.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_TARGET_DOUBLE__TRAITS_HPP_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_TARGET_DOUBLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "canopen_interfaces/srv/detail/co_target_double__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace canopen_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const COTargetDouble_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: target
  {
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const COTargetDouble_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: target
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "target: ";
    rosidl_generator_traits::value_to_yaml(msg.target, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const COTargetDouble_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace canopen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use canopen_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const canopen_interfaces::srv::COTargetDouble_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  canopen_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use canopen_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const canopen_interfaces::srv::COTargetDouble_Request & msg)
{
  return canopen_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<canopen_interfaces::srv::COTargetDouble_Request>()
{
  return "canopen_interfaces::srv::COTargetDouble_Request";
}

template<>
inline const char * name<canopen_interfaces::srv::COTargetDouble_Request>()
{
  return "canopen_interfaces/srv/COTargetDouble_Request";
}

template<>
struct has_fixed_size<canopen_interfaces::srv::COTargetDouble_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<canopen_interfaces::srv::COTargetDouble_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<canopen_interfaces::srv::COTargetDouble_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace canopen_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const COTargetDouble_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const COTargetDouble_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const COTargetDouble_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace canopen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use canopen_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const canopen_interfaces::srv::COTargetDouble_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  canopen_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use canopen_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const canopen_interfaces::srv::COTargetDouble_Response & msg)
{
  return canopen_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<canopen_interfaces::srv::COTargetDouble_Response>()
{
  return "canopen_interfaces::srv::COTargetDouble_Response";
}

template<>
inline const char * name<canopen_interfaces::srv::COTargetDouble_Response>()
{
  return "canopen_interfaces/srv/COTargetDouble_Response";
}

template<>
struct has_fixed_size<canopen_interfaces::srv::COTargetDouble_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<canopen_interfaces::srv::COTargetDouble_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<canopen_interfaces::srv::COTargetDouble_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<canopen_interfaces::srv::COTargetDouble>()
{
  return "canopen_interfaces::srv::COTargetDouble";
}

template<>
inline const char * name<canopen_interfaces::srv::COTargetDouble>()
{
  return "canopen_interfaces/srv/COTargetDouble";
}

template<>
struct has_fixed_size<canopen_interfaces::srv::COTargetDouble>
  : std::integral_constant<
    bool,
    has_fixed_size<canopen_interfaces::srv::COTargetDouble_Request>::value &&
    has_fixed_size<canopen_interfaces::srv::COTargetDouble_Response>::value
  >
{
};

template<>
struct has_bounded_size<canopen_interfaces::srv::COTargetDouble>
  : std::integral_constant<
    bool,
    has_bounded_size<canopen_interfaces::srv::COTargetDouble_Request>::value &&
    has_bounded_size<canopen_interfaces::srv::COTargetDouble_Response>::value
  >
{
};

template<>
struct is_service<canopen_interfaces::srv::COTargetDouble>
  : std::true_type
{
};

template<>
struct is_service_request<canopen_interfaces::srv::COTargetDouble_Request>
  : std::true_type
{
};

template<>
struct is_service_response<canopen_interfaces::srv::COTargetDouble_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_TARGET_DOUBLE__TRAITS_HPP_
