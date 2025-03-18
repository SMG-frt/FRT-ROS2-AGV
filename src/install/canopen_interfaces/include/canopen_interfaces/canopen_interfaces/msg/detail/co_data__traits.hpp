// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from canopen_interfaces:msg/COData.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__TRAITS_HPP_
#define CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "canopen_interfaces/msg/detail/co_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace canopen_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const COData & msg,
  std::ostream & out)
{
  out << "{";
  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << ", ";
  }

  // member: subindex
  {
    out << "subindex: ";
    rosidl_generator_traits::value_to_yaml(msg.subindex, out);
    out << ", ";
  }

  // member: data
  {
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const COData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << "\n";
  }

  // member: subindex
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "subindex: ";
    rosidl_generator_traits::value_to_yaml(msg.subindex, out);
    out << "\n";
  }

  // member: data
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "data: ";
    rosidl_generator_traits::value_to_yaml(msg.data, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const COData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace canopen_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use canopen_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const canopen_interfaces::msg::COData & msg,
  std::ostream & out, size_t indentation = 0)
{
  canopen_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use canopen_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const canopen_interfaces::msg::COData & msg)
{
  return canopen_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<canopen_interfaces::msg::COData>()
{
  return "canopen_interfaces::msg::COData";
}

template<>
inline const char * name<canopen_interfaces::msg::COData>()
{
  return "canopen_interfaces/msg/COData";
}

template<>
struct has_fixed_size<canopen_interfaces::msg::COData>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<canopen_interfaces::msg::COData>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<canopen_interfaces::msg::COData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__TRAITS_HPP_
