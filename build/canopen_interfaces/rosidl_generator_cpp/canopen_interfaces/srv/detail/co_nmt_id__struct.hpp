// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from canopen_interfaces:srv/CONmtID.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__SRV__DETAIL__CO_NMT_ID__STRUCT_HPP_
#define CANOPEN_INTERFACES__SRV__DETAIL__CO_NMT_ID__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__canopen_interfaces__srv__CONmtID_Request __attribute__((deprecated))
#else
# define DEPRECATED__canopen_interfaces__srv__CONmtID_Request __declspec(deprecated)
#endif

namespace canopen_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CONmtID_Request_
{
  using Type = CONmtID_Request_<ContainerAllocator>;

  explicit CONmtID_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nmtcommand = 0;
      this->nodeid = 0;
    }
  }

  explicit CONmtID_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->nmtcommand = 0;
      this->nodeid = 0;
    }
  }

  // field types and members
  using _nmtcommand_type =
    uint8_t;
  _nmtcommand_type nmtcommand;
  using _nodeid_type =
    uint8_t;
  _nodeid_type nodeid;

  // setters for named parameter idiom
  Type & set__nmtcommand(
    const uint8_t & _arg)
  {
    this->nmtcommand = _arg;
    return *this;
  }
  Type & set__nodeid(
    const uint8_t & _arg)
  {
    this->nodeid = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__canopen_interfaces__srv__CONmtID_Request
    std::shared_ptr<canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__canopen_interfaces__srv__CONmtID_Request
    std::shared_ptr<canopen_interfaces::srv::CONmtID_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CONmtID_Request_ & other) const
  {
    if (this->nmtcommand != other.nmtcommand) {
      return false;
    }
    if (this->nodeid != other.nodeid) {
      return false;
    }
    return true;
  }
  bool operator!=(const CONmtID_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CONmtID_Request_

// alias to use template instance with default allocator
using CONmtID_Request =
  canopen_interfaces::srv::CONmtID_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace canopen_interfaces


#ifndef _WIN32
# define DEPRECATED__canopen_interfaces__srv__CONmtID_Response __attribute__((deprecated))
#else
# define DEPRECATED__canopen_interfaces__srv__CONmtID_Response __declspec(deprecated)
#endif

namespace canopen_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CONmtID_Response_
{
  using Type = CONmtID_Response_<ContainerAllocator>;

  explicit CONmtID_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit CONmtID_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__canopen_interfaces__srv__CONmtID_Response
    std::shared_ptr<canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__canopen_interfaces__srv__CONmtID_Response
    std::shared_ptr<canopen_interfaces::srv::CONmtID_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CONmtID_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const CONmtID_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CONmtID_Response_

// alias to use template instance with default allocator
using CONmtID_Response =
  canopen_interfaces::srv::CONmtID_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace canopen_interfaces

namespace canopen_interfaces
{

namespace srv
{

struct CONmtID
{
  using Request = canopen_interfaces::srv::CONmtID_Request;
  using Response = canopen_interfaces::srv::CONmtID_Response;
};

}  // namespace srv

}  // namespace canopen_interfaces

#endif  // CANOPEN_INTERFACES__SRV__DETAIL__CO_NMT_ID__STRUCT_HPP_
