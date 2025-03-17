// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from canopen_interfaces:srv/COTargetDouble.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_TARGET_DOUBLE__BUILDER_HPP_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_TARGET_DOUBLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "canopen_interfaces/srv/detail/co_target_double__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_COTargetDouble_Request_target
{
public:
  Init_COTargetDouble_Request_target()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::canopen_interfaces::srv::COTargetDouble_Request target(::canopen_interfaces::srv::COTargetDouble_Request::_target_type arg)
  {
    msg_.target = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::COTargetDouble_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::COTargetDouble_Request>()
{
  return canopen_interfaces::srv::builder::Init_COTargetDouble_Request_target();
}

}  // namespace canopen_interfaces


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_COTargetDouble_Response_success
{
public:
  Init_COTargetDouble_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::canopen_interfaces::srv::COTargetDouble_Response success(::canopen_interfaces::srv::COTargetDouble_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::COTargetDouble_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::COTargetDouble_Response>()
{
  return canopen_interfaces::srv::builder::Init_COTargetDouble_Response_success();
}

}  // namespace canopen_interfaces

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_TARGET_DOUBLE__BUILDER_HPP_
