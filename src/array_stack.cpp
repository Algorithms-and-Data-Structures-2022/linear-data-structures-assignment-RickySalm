#include "assignment/array_stack.hpp"

#include <algorithm>  // copy, fill
#include <stdexcept>  // invalid_argument (НЕЛЬЗЯ ИСПОЛЬЗОВАТЬ)

namespace assignment {

  ArrayStack::ArrayStack(int capacity) {

    // выбрасываем ошибку, если указана неположительная емкость стека
    if (capacity <= 0) {
      throw std::invalid_argument("capacity is not positive");
    }


    capacity_ = capacity;
    data_ = new int[capacity];
    for (int i = 0; i < capacity; ++i) {
      data_[i] = 0;
    }
  }

  ArrayStack::~ArrayStack() {
    // Write your code here ...
  }

  void ArrayStack::Push(int value) {
    if (size_ != capacity_) {
      data_[size_] = value;
      size_++;
    }
    else {
      Resize(capacity_+kCapacityGrowthCoefficient);
      data_[size_] = value;
      size_++;
    }
  }

  bool ArrayStack::Pop() {
    if (size_ != 0) {
      data_[size_ - 1] = 0;
      size_--;
      return true;
    }
    return false;
  }

  void ArrayStack::Clear() {
    size_ = 0;
  }

  std::optional<int> ArrayStack::Peek() const {
    if (size_ > 0) {
      return data_[size_ - 1];
    }
    return std::nullopt;
  }

  bool ArrayStack::IsEmpty() const {
    if (size_ == 0) {
      return true;
    }
    return false;
  }

  int ArrayStack::size() const {
    return size_;
  }

  int ArrayStack::capacity() const {
    return capacity_;
  }

  bool ArrayStack::Resize(int new_capacity) {
    if (new_capacity > capacity_) {
      int* new_data = new int[new_capacity];
      std::copy(data_, data_ + size_, new_data);
      capacity_ = new_capacity;
      delete[] data_;
      data_ = new_data;
      return true;
    }
    return false;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  ArrayStack::ArrayStack(const std::vector<int>& values, int capacity) {

    size_ = static_cast<int>(values.size());
    capacity_ = capacity;

    data_ = new int[capacity]{};

    std::copy(values.data(), values.data() + size_, data_);
  }

  std::vector<int> ArrayStack::toVector(std::optional<int> size) const {

    if (capacity_ == 0 || data_ == nullptr) {
      return {};
    }

    if (size.has_value()) {
      return {data_, data_ + size.value()};
    }

    return {data_, data_ + capacity_};
  }

}  // namespace assignment
