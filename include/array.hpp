#pragma once

#include <memory>
#include <utility>
#include <stdexcept>

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

  void PushBack(const T& value);
  void RemoveAt(size_t index);
  size_t Size() const noexcept;
  size_t Capacity() const noexcept;
  T& operator[](size_t index);
  const T& operator[](size_t index) const;

 private:
  void Grow();

  std::unique_ptr<T[]> data_;
  size_t size_{0};
  size_t capacity_{0};
};

}  // namespace geometry
