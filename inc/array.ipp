#pragma once
#include "array.hpp"

namespace geometry {

template <typename T>
Array<T>::Array(size_t capacity)
    : size_(0), capacity_(capacity),
      data_(capacity ? new T[capacity] : nullptr) {}

template <typename T>
Array<T>::Array(const Array& other)
    : size_(other.size_),
      capacity_(other.capacity_),
      data_(other.capacity_ ? new T[other.capacity_] : nullptr)
{
  for (size_t i = 0; i < size_; ++i) {
    data_[i] = other.data_[i];
  }
}

template <typename T>
Array<T>::Array(Array&& other) noexcept
    : data_(other.data_), size_(other.size_), capacity_(other.capacity_) 
{
  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this == &other) return *this;

  T* new_data = (other.capacity_ ? new T[other.capacity_] : nullptr);
  for (size_t i = 0; i < other.size_; ++i) {
    new_data[i] = other.data_[i];
  }

  delete[] data_;

  data_ = new_data;
  size_ = other.size_;
  capacity_ = other.capacity_;

  return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
  if (this == &other) return *this;

  delete[] data_;

  data_ = other.data_;
  size_ = other.size_;
  capacity_ = other.capacity_;

  other.data_ = nullptr;
  other.size_ = 0;
  other.capacity_ = 0;

  return *this;
}

template <typename T>
Array<T>::~Array() {
  delete[] data_;
}

template <typename T>
void Array<T>::PushBack(const T& value) {
  if (size_ == capacity_) {
    Grow();
  }
  data_[size_++] = value;
}

template <typename T>
void Array<T>::RemoveAt(size_t index) {
  if (index >= size_) {
    throw std::out_of_range("Index out of range");
  }
  for (size_t i = index; i < size_ - 1; ++i) {
    data_[i] = data_[i + 1];
  }
  --size_;
}

template <typename T>
void Array<T>::Grow() {
  size_t new_capacity = (capacity_ == 0 ? 1 : capacity_ * 2);
  T* new_data = new T[new_capacity];

  for (size_t i = 0; i < size_; ++i) {
    new_data[i] = data_[i];
  }

  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
  if (index >= size_) throw std::out_of_range("Index out of range");
  return data_[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
  if (index >= size_) throw std::out_of_range("Index out of range");
  return data_[index];
}

} // namespace geometry
