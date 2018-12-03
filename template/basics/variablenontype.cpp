#include <array>
#include <iostream>

template <int N>
std::array<int, N> arr{};

template <auto N>
constexpr decltype(N) dval = N;

int main(int argc, char **argv) {
  std::cout << dval<'c'> << '\n';
  arr<10>[0] = 42;

  for (std::size_t i = 0; i != arr<10>.size(); ++i) {
    std::cout << arr<10>[i] << '\n';
  }
}
