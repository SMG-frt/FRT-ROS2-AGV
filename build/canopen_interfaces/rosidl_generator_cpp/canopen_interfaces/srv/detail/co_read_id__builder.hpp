// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from canopen_interfaces:srv/COReadID.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_READ_ID__BUILDER_HPP_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_READ_ID__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "canopen_interfaces/srv/detail/co_read_id__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_COReadID_Request_canopen_datatype
{
public:
  explicit Init_COReadID_Request_canopen_datatype(::canopen_interfaces::srv::COReadID_Request & msg)
  : msg_(msg)
  {}
  ::canopen_interfaces::srv::COReadID_Request canopen_datatype(::canopen_interfaces::srv::COReadID_Request::_canopen_datatype_type arg)
  {
    msg_.canopen_datatype = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::COReadID_Request msg_;
};

class Init_COReadID_Request_subindex
{
public:
  explicit Init_COReadID_Request_subindex(::canopen_interfaces::srv::COReadID_Request & msg)
  : msg_(msg)
  {}
  Init_COReadID_Request_canopen_datatype subindex(::canopen_interfaces::srv::COReadID_Request::_subindex_type arg)
  {
    msg_.subindex = std::move(arg);
    return Init_COReadID_Request_canopen_datatype(msg_);
  }

private:
  ::canopen_interfaces::srv::COReadID_Request msg_;
};

class Init_COReadID_Request_index
{
public:
  explicit Init_COReadID_Request_index(::canopen_interfaces::srv::COReadID_Request & msg)
  : msg_(msg)
  {}
  Init_COReadID_Request_subindex index(::canopen_interfaces::srv::COReadID_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_COReadID_Request_subindex(msg_);
  }

private:
  ::canopen_interfaces::srv::COReadID_Request msg_;
};

class Init_COReadID_Request_nodeid
{
public:
  Init_COReadID_Request_nodeid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_COReadID_Request_index nodeid(::canopen_interfaces::srv::COReadID_Request::_nodeid_type arg)
  {
    msg_.nodeid = std::move(arg);
    return Init_COReadID_Request_index(msg_);
  }

private:
  ::canopen_interfaces::srv::COReadID_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::COReadID_Request>()
{
  return canopen_interfaces::srv::builder::Init_COReadID_Request_nodeid();
}

}  // namespace canopen_interfaces


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_COReadID_Response_data
{
public:
  explicit Init_COReadID_Response_data(::canopen_interfaces::srv::COReadID_Response & msg)
  : msg_(msg)
  {}
  ::canopen_interfaces::srv::COReadID_Response data(::canopen_interfaces::srv::COReadID_Response::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::COReadID_Response msg_;
};

class Init_COReadID_Response_success
{
public:
  Init_COReadID_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_COReadID_Response_data success(::canopen_interfaces::srv::COReadID_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_COReadID_Response_data(msg_);
  }

private:
  ::canopen_interfaces::srv::COReadID_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::COReadID_Response>()
{
  return canopen_interfaces::srv::builder::Init_COReadID_Response_success();
}

}  // namespace canopen_interfaces

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_READ_ID__BUILDER_HPP_
