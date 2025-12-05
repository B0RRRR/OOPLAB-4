#pragma once

#include <cstddef>
#include <stdexcept>
#include <utility>

namespace geometry {

template <typename T>
class Array {
 public:
  Array() = default;
  explicit Array(size_t capacity);
  Array(const Array& other);
  Array(Array&& other) noexcept;

  Array& operator=(const Array& other);
  Array& operator=(Array&& other) noexcept;

  ~Array();

  void PushBack(const T& value);
  void RemoveAt(size_t index);

  size_t Size() const noexcept { return size_; }
  size_t Capacity() const noexcept { return capacity_; }

  T& operator[](size_t index);
  const T& operator[](size_t index) const;

 private:
  void Grow();

  T* data_ = nullptr;
  size_t size_ = 0;
  size_t capacity_ = 0;
};

} // namespace geometry

#include "array.ipp"
