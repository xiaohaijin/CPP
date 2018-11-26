#ifndef LESSARRAY_HPP
#define LESSARRAY_HPP

template <typename T, int N, int M>
bool less(T (&a)[N], T (&b)[M]) {
  for (int i = 0; i < N && i < M; ++i) {
    if (a[i] < b[i]) {
      return true;
    }
    if (b[i] < a[i]) {
      return false;
    }
  }
}

#endif  // LESSARRAY_HPP
