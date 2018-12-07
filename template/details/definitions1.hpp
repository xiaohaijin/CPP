#ifndef DEFINITIONS1_H
#define DEFINITIONS1_H

template <typename T>
class Data {
 public:
  static constexpr bool copyable = true;
  /// ...
};

template <typename T>
void log(T x) {
  /// ...
}

template <typename T>
T zero = 0;

template <typename T>
bool dataCopyable = Data<T>::copyable;

template <typename T>
using DataList = Data<T*>;

#endif  // DEFINITIONS1_H
