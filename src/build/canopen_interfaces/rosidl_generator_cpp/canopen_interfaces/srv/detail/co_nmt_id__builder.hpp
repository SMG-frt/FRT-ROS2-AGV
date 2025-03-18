// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from canopen_interfaces:srv/CONmtID.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_NMT_ID__BUILDER_HPP_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_NMT_ID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "canopen_interfaces/srv/detail/co_nmt_id__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_CONmtID_Request_nodeid
{
public:
  explicit Init_CONmtID_Request_nodeid(::canopen_interfaces::srv::CONmtID_Request & msg)
  : msg_(msg)
  {}
  ::canopen_interfaces::srv::CONmtID_Request nodeid(::canopen_interfaces::srv::CONmtID_Request::_nodeid_type arg)
  {
    msg_.nodeid = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::CONmtID_Request msg_;
};

class Init_CONmtID_Request_nmtcommand
{
public:
  Init_CONmtID_Request_nmtcommand()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CONmtID_Request_nodeid nmtcommand(::canopen_interfaces::srv::CONmtID_Request::_nmtcommand_type arg)
  {
    msg_.nmtcommand = std::move(arg);
    return Init_CONmtID_Request_nodeid(msg_);
  }

private:
  ::canopen_interfaces::srv::CONmtID_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::CONmtID_Request>()
{
  return canopen_interfaces::srv::builder::Init_CONmtID_Request_nmtcommand();
}

}  // namespace canopen_interfaces


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_CONmtID_Response_success
{
public:
  Init_CONmtID_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::canopen_interfaces::srv::CONmtID_Response success(::canopen_interfaces::srv::CONmtID_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::CONmtID_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::CONmtID_Response>()
{
  return canopen_interfaces::srv::builder::Init_CONmtID_Response_success();
}

}  // namespace canopen_interfaces

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_NMT_ID__BUILDER_HPP_
