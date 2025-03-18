// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from canopen_interfaces:msg/COData.idl
// generated code does not contain a copyright notice
#include "canopen_interfaces/msg/detail/co_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
canopen_interfaces__msg__COData__init(canopen_interfaces__msg__COData * msg)
{
  if (!msg) {
    return false;
  }
  // index
  // subindex
  // data
  return true;
}

void
canopen_interfaces__msg__COData__fini(canopen_interfaces__msg__COData * msg)
{
  if (!msg) {
    return;
  }
  // index
  // subindex
  // data
}

bool
canopen_interfaces__msg__COData__are_equal(const canopen_interfaces__msg__COData * lhs, const canopen_interfaces__msg__COData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // index
  if (lhs->index != rhs->index) {
    return false;
  }
  // subindex
  if (lhs->subindex != rhs->subindex) {
    return false;
  }
  // data
  if (lhs->data != rhs->data) {
    return false;
  }
  return true;
}

bool
canopen_interfaces__msg__COData__copy(
  const canopen_interfaces__msg__COData * input,
  canopen_interfaces__msg__COData * output)
{
  if (!input || !output) {
    return false;
  }
  // index
  output->index = input->index;
  // subindex
  output->subindex = input->subindex;
  // data
  output->data = input->data;
  return true;
}

canopen_interfaces__msg__COData *
canopen_interfaces__msg__COData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  canopen_interfaces__msg__COData * msg = (canopen_interfaces__msg__COData *)allocator.allocate(sizeof(canopen_interfaces__msg__COData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(canopen_interfaces__msg__COData));
  bool success = canopen_interfaces__msg__COData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
canopen_interfaces__msg__COData__destroy(canopen_interfaces__msg__COData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    canopen_interfaces__msg__COData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
canopen_interfaces__msg__COData__Sequence__init(canopen_interfaces__msg__COData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  canopen_interfaces__msg__COData * data = NULL;

  if (size) {
    data = (canopen_interfaces__msg__COData *)allocator.zero_allocate(size, sizeof(canopen_interfaces__msg__COData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = canopen_interfaces__msg__COData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        canopen_interfaces__msg__COData__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
canopen_interfaces__msg__COData__Sequence__fini(canopen_interfaces__msg__COData__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      canopen_interfaces__msg__COData__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

canopen_interfaces__msg__COData__Sequence *
canopen_interfaces__msg__COData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  canopen_interfaces__msg__COData__Sequence * array = (canopen_interfaces__msg__COData__Sequence *)allocator.allocate(sizeof(canopen_interfaces__msg__COData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = canopen_interfaces__msg__COData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
canopen_interfaces__msg__COData__Sequence__destroy(canopen_interfaces__msg__COData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    canopen_interfaces__msg__COData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
canopen_interfaces__msg__COData__Sequence__are_equal(const canopen_interfaces__msg__COData__Sequence * lhs, const canopen_interfaces__msg__COData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!canopen_interfaces__msg__COData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
canopen_interfaces__msg__COData__Sequence__copy(
  const canopen_interfaces__msg__COData__Sequence * input,
  canopen_interfaces__msg__COData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(canopen_interfaces__msg__COData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    canopen_interfaces__msg__COData * data =
      (canopen_interfaces__msg__COData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!canopen_interfaces__msg__COData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          canopen_interfaces__msg__COData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!canopen_interfaces__msg__COData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
