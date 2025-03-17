// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from canopen_interfaces:msg/COData.idl
// generated code does not contain a copyright notice

#ifndef CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__STRUCT_HPP_
#define CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__canopen_interfaces__msg__COData __attribute__((deprecated))
#else
# define DEPRECATED__canopen_interfaces__msg__COData __declspec(deprecated)
#endif

namespace canopen_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct COData_
{
  using Type = COData_<ContainerAllocator>;

  explicit COData_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->subindex = 0;
      this->data = 0ul;
    }
  }

  explicit COData_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->index = 0;
      this->subindex = 0;
      this->data = 0ul;
    }
  }

  // field types and members
  using _index_type =
    uint16_t;
  _index_type index;
  using _subindex_type =
    uint8_t;
  _subindex_type subindex;
  using _data_type =
    uint32_t;
  _data_type data;

  // setters for named parameter idiom
  Type & set__index(
    const uint16_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__subindex(
    const uint8_t & _arg)
  {
    this->subindex = _arg;
    return *this;
  }
  Type & set__data(
    const uint32_t & _arg)
  {
    this->data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    canopen_interfaces::msg::COData_<ContainerAllocator> *;
  using ConstRawPtr =
    const canopen_interfaces::msg::COData_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<canopen_interfaces::msg::COData_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<canopen_interfaces::msg::COData_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::msg::COData_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::msg::COData_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      canopen_interfaces::msg::COData_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<canopen_interfaces::msg::COData_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<canopen_interfaces::msg::COData_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<canopen_interfaces::msg::COData_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__canopen_interfaces__msg__COData
    std::shared_ptr<canopen_interfaces::msg::COData_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__canopen_interfaces__msg__COData
    std::shared_ptr<canopen_interfaces::msg::COData_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const COData_ & other) const
  {
    if (this->index != other.index) {
      return false;
    }
    if (this->subindex != other.subindex) {
      return false;
    }
    if (this->data != other.data) {
      return false;
    }
    return true;
  }
  bool operator!=(const COData_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct COData_

// alias to use template instance with default allocator
using COData =
  canopen_interfaces::msg::COData_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace canopen_interfaces

#endif  // CANOPEN_INTERFACES__MSG__DETAIL__CO_DATA__STRUCT_HPP_
