#ifndef BLOB_H
#define BLOB_H

#include <iterator>
#include <string>
#include <vector>
#include <cstddef>
#include <stdexcept>
#include <utility>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cstdlib>

template <typename>
class BlobPtr;

template <typename>
class Blob;

template <typename T>
bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob {

  friend class BlobPtr<T>;
  friend bool operator==<T>(const Blob<T>&, const Blob<T>&);

 public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;

  Blob();
  Blob(std::initializer_list<T> il);
  template <typename It>
  Blob(It b, It e);
  Blob(T*, std::size_t);

  BlobPtr<T> begin() { return BlobPtr<T>(*this); }
  BlobPtr<T> end() {
    auto ret = BlobPtr<T>(*this, data->size());
    return ret;
  }

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const T& t) { data->push_back(t); }
  void push_back(T&& t) { data->push_back(std::move(t)); }
  void pop_back();
  T& front();
  T& back();
  T& at(size_type i);
  const T& front() const;
  const T& back() const;
  const T& at(size_type i) const;
  T& operator[](size_type i);
  const T& operator[](size_type i) const;
  void swap(Blob<T>& b) { data.swap(b.data); }

 private:
  std::shared_ptr<std::vector<T>> data;
  void check(size_type i, const std::string& msg) const;
};

template <typename T>
Blob<T>::Blob()
    : data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il)
    : data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e)
    : data(std::make_shared<std::vector<T>>(b, e)) {}

template <typename T>
Blob<T>::Blob(T* p, std::size_t n)
    : data(std::make_shared<std::vector<T>>(p, p + n)) {}

template <typename T>
void Blob<T>::pop_back() {
  check(0, "pop_back on empty Blob");
  data->pop_back();
}

template <typename T>
T& Blob<T>::front() {
  check(0, "front on empty Blob");
  return data->front();
}

template <typename T>
T& Blob<T>::back() {
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T>
T& Blob<T>::at(Blob::size_type i) {
  check(i, "subscript out range");
  return (*data)[i];
}

template <typename T>
const T& Blob<T>::front() const {
  check(0, "front on empty Blob");
  return data->front();
}

template <typename T>
const T& Blob<T>::back() const {
  check(0, "back on empty Blob");
  return data->back();
}

template <typename T>
const T& Blob<T>::at(Blob<T>::size_type i) const {
  check(i, "subscript out of range");
  return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
  check(i, "subscript out of range");
  return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](Blob<T>::size_type i) const {
  check(i, "subscript out of range");
  return (*data)[i];
}

template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const {
  if (i >= data->size()) {
    throw std::out_of_range(msg);
  }
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Blob<T> a) {
  os << "< ";
  for (std::size_t i = 0; i != a.size(); ++i) {
    os << a[i] << " ";
  }
  return os;
}

template <typename T>
bool operator==(const Blob<T> lhs, const Blob<T> rhs) {
  if (rhs.size() != lhs.size()) {
    return false;
  }
  for (std::size_t i = 0; i != lhs.size(); ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

/*!
 *
 */

template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
class BlobPtr : public std::iterator<std::bidirectional_iterator_tag, T> {
  friend bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

 public:
  BlobPtr() : curr(0) {}
  BlobPtr(BlobPtr<T>& a, std::size_t sz = 0) : wptr(a.data), curr(sz) {}
  T& operator[](std::size_t i) {
    auto p = check(i, "subscript out of range");
    return (*p)[i];
  }
  const T& operator[](std::size_t i) const {
    auto p = check(i, "subscript out of range");
    return (*p)[i];
  }
  T& operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }
  T* operator->() const { return &this->operator*(); }
  BlobPtr<T>& operator++();
  BlobPtr<T>& operator--();

  BlobPtr<T>& operator++(int);
  BlobPtr<T>& operator--(int);

 private:
  std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
  std::weak_ptr<std::vector<T>> wptr;
  std::size_t curr;
};

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
  return lhs.wptr.lock().get() == rhs.wptr.lock().get && lhs.curr == rhs.curr;
}

template <typename T>
bool operator!=(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
  return !(lhs == rhs);
}

template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++(int) {
  BlobPtr<T> ret = *this;
  ++(*this);
  return ret;
}

template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i,
                                                  const std::string& msg) const {
  auto ret = wptr.lock();
  if (!ret) {
    throw std::runtime_error("unbound BlotPtre");
  }
  if (i >= ret->size()) {
    throw std::out_of_range(msg);
  }
  return ret;
}

#endif  // BLOB_H
