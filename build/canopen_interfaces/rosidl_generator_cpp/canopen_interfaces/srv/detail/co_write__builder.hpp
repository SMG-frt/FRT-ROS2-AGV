// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from canopen_interfaces:srv/COWrite.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_WRITE__BUILDER_HPP_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_WRITE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "canopen_interfaces/srv/detail/co_write__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_COWrite_Request_data
{
public:
  explicit Init_COWrite_Request_data(::canopen_interfaces::srv::COWrite_Request & msg)
  : msg_(msg)
  {}
  ::canopen_interfaces::srv::COWrite_Request data(::canopen_interfaces::srv::COWrite_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::COWrite_Request msg_;
};

class Init_COWrite_Request_subindex
{
public:
  explicit Init_COWrite_Request_subindex(::canopen_interfaces::srv::COWrite_Request & msg)
  : msg_(msg)
  {}
  Init_COWrite_Request_data subindex(::canopen_interfaces::srv::COWrite_Request::_subindex_type arg)
  {
    msg_.subindex = std::move(arg);
    return Init_COWrite_Request_data(msg_);
  }

private:
  ::canopen_interfaces::srv::COWrite_Request msg_;
};

class Init_COWrite_Request_index
{
public:
  Init_COWrite_Request_index()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_COWrite_Request_subindex index(::canopen_interfaces::srv::COWrite_Request::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_COWrite_Request_subindex(msg_);
  }

private:
  ::canopen_interfaces::srv::COWrite_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::COWrite_Request>()
{
  return canopen_interfaces::srv::builder::Init_COWrite_Request_index();
}

}  // namespace canopen_interfaces


namespace canopen_interfaces
{

namespace srv
{

namespace builder
{

class Init_COWrite_Response_success
{
public:
  Init_COWrite_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::canopen_interfaces::srv::COWrite_Response success(::canopen_interfaces::srv::COWrite_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::canopen_interfaces::srv::COWrite_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::canopen_interfaces::srv::COWrite_Response>()
{
  return canopen_interfaces::srv::builder::Init_COWrite_Response_success();
}

}  // namespace canopen_interfaces

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_WRITE__BUILDER_HPP_
