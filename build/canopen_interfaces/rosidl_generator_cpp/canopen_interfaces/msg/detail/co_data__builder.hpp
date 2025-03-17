// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from canopen_interfaces:msg/COData.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__BUILDER_HPP_
#define CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "canopen_interfaces/msg/detail/co_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace canopen_interfaces
{

namespace msg
{

namespace builder
{

class Init_COData_data
{
public:
  explicit Init_COData_data(::canopen_interfaces::msg::COData & msg)
  : msg_(msg)
  {}
  ::canopen_interfaces::msg::COData data(::canopen_interfaces::msg::COData::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::msg::COData msg_;
};

class Init_COData_subindex
{
public:
  explicit Init_COData_subindex(::canopen_interfaces::msg::COData & msg)
  : msg_(msg)
  {}
  Init_COData_data subindex(::canopen_interfaces::msg::COData::_subindex_type arg)
  {
    msg_.subindex = std::move(arg);
    return Init_COData_data(msg_);
  }

private:
  ::canopen_interfaces::msg::COData msg_;
};

class Init_COData_index
{
public:
  Init_COData_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_COData_subindex index(::canopen_interfaces::msg::COData::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_COData_subindex(msg_);
  }

private:
  ::canopen_interfaces::msg::COData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::msg::COData>()
{
  return canopen_interfaces::msg::builder::Init_COData_index();
}

}  // namespace canopen_interfaces

#endif  // CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__BUILDER_HPP_
