#include "array.hpp"
#include "figure.hpp"

namespace geometry {

template <typename T>
Array<T>::Array(size_t capacity)
    : data_(std::make_unique<T[]>(capacity)), capacity_(capacity) {}

template <typename T>
Array<T>::Array(const Array& other)
    : data_(std::make_unique<T[]>(other.capacity_)),
      size_(other.size_),
      capacity_(other.capacity_) {
  for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
}

template <typename T>
Array<T>::Array(Array&& other) noexcept = default;

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
  if (this != &other) {
    data_ = std::make_unique<T[]>(other.capacity_);
    size_ = other.size_;
    capacity_ = other.capacity_;
    for (size_t i = 0; i < size_; ++i) data_[i] = other.data_[i];
  }
  return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept = default;

template <typename T>
void Array<T>::PushBack(const T& value) {
  if (size_ == capacity_) Grow();
  data_[size_++] = value;
}

template <typename T>
void Array<T>::RemoveAt(size_t index) {
  if (index >= size_) throw std::out_of_range("Index out of range");
  for (size_t i = index; i + 1 < size_; ++i) data_[i] = std::move(data_[i + 1]);
  --size_;
}

template <typename T>
void Array<T>::Grow() {
  size_t new_capacity = capacity_ == 0 ? 1 : capacity_ * 2;
  auto new_data = std::make_unique<T[]>(new_capacity);
  for (size_t i = 0; i < size_; ++i) new_data[i] = std::move(data_[i]);
  data_ = std::move(new_data);
  capacity_ = new_capacity;
}

template <typename T>
size_t Array<T>::Size() const noexcept { return size_; }

template <typename T>
size_t Array<T>::Capacity() const noexcept { return capacity_; }

template <typename T>
T& Array<T>::operator[](size_t index) { return data_[index]; }

template <typename T>
const T& Array<T>::operator[](size_t index) const { return data_[index]; }

template class Array<int>;
template class Array<float>;
template class Array<double>;
template class Array<std::shared_ptr<geometry::Figure<double>>>;

}  // namespace geometry
