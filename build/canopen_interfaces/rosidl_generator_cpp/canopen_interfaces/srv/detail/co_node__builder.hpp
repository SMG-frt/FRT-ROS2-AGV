// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from canopen_interfaces:srv/CONode.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_NODE__BUILDER_HPP_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_NODE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "canopen_interfaces/srv/detail/co_node__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_CONode_Request_nodeid
{
public:
  Init_CONode_Request_nodeid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::canopen_interfaces::srv::CONode_Request nodeid(::canopen_interfaces::srv::CONode_Request::_nodeid_type arg)
  {
    msg_.nodeid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::CONode_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::CONode_Request>()
{
  return canopen_interfaces::srv::builder::Init_CONode_Request_nodeid();
}

}  // namespace canopen_interfaces


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_CONode_Response_success
{
public:
  Init_CONode_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::canopen_interfaces::srv::CONode_Response success(::canopen_interfaces::srv::CONode_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::CONode_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::CONode_Response>()
{
  return canopen_interfaces::srv::builder::Init_CONode_Response_success();
}

}  // namespace canopen_interfaces

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_NODE__BUILDER_HPP_
