#ifndef DEFINITIONS3_HPP
#define DEFINITIONS3_HPP

template <typename T>
class List {
 public:
  List() = default;

  template <typename U>
  class Handle;

  template <typename U>
  List(List<U> const &);

  template <typename U>
  static U zero;
};

template <typename T>
template <typename U>
class List<T>::Handle {
  /// ...
};

template <typename T>
template <typename U>
List<T>::List(const List<U> &) {
  /// ...
}

template <typename T>
template <typename U>
U List<T>::zero = 0;

#endif  // DEFINITIONS3_HPP
