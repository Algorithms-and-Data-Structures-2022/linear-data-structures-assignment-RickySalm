#include "assignment/linked_queue.hpp"

namespace assignment {

  LinkedQueue::~LinkedQueue() {

    // эквивалентно очистке очереди
    LinkedQueue::Clear();
  }

  void LinkedQueue::Enqueue(int value) {
    Node* new_node = new Node(value);
    if (size_ == 0) {
      front_ = new_node;
      back_ = new_node;
    }
    else {
      back_->next = new_node;
      back_ = new_node;

    }
    size_++;
  }

  bool LinkedQueue::Dequeue() {
    if (size_ != 0) {
      Node* new_node = front_;
      front_ = front_->next;
      size_--;
      delete new_node;
      return true;
    }
    return false;
  }

  void LinkedQueue::Clear() {
    for (int i = 0; i < size_; ++i) {
      Node* new_node = front_;
      front_ = front_->next;
      delete new_node;
    }
    size_ = 0;
    front_ = nullptr;
    back_ = nullptr;
  }

  std::optional<int> LinkedQueue::front() const {
    if (size_ != 0) {
      return front_->value;
    }
    return std::nullopt;
  }

  std::optional<int> LinkedQueue::back() const {
    if (size_ != 0) {
      return back_->value;
    }
    return std::nullopt;
  }

  bool LinkedQueue::IsEmpty() const {
    return size_ == 0;
  }

  int LinkedQueue::size() const {
    return size_;
  }

  // ДЛЯ ТЕСТИРОВАНИЯ
  LinkedQueue::LinkedQueue(const std::vector<int>& values) {

    if (values.empty()) {
      return;
    }

    auto* curr_node = new Node(values.front());
    front_ = curr_node;

    for (int index = 1; index < values.size() - 1; ++index) {
      curr_node->next = new Node(values[index]);
      curr_node = curr_node->next;
    }

    if (values.size() == 1) {
      back_ = front_;
    } else {
      curr_node->next = new Node(values.back());
      back_ = curr_node->next;
    }

    size_ = static_cast<int>(values.size());
  }

  std::vector<int> LinkedQueue::toVector() const {
    if (front_ == nullptr || size_ == 0) {
      return {};
    }

    std::vector<int> array;
    array.reserve(size_);

    for (auto* node = front_; node != nullptr; node = node->next) {
      array.push_back(node->value);
    }

    return array;
  }

}  // namespace assignment