#ifndef LESSSTRING_HPP
#define LESSSTRING_HPP

template <int N, int M>
bool less(const char (&a)[N], const char (&b)[M]) {
  for (int i = 0; i < N && i < M; ++i) {
    if (a[i] < b[i]) {
      return true;
    }
    if (b[i] < a[i]) {
      return false;
    }
  }
}

#endif  // LESSSTRING_HPP
