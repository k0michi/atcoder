#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <type_traits>
#include <vector>

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = std::make_signed<size_t>::type;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using f32 = float;
using f64 = double;

int main() {
  i32 N;
  std::cin >> N;
  std::vector<i32> a(N);

  for (usize i = 0; i < N; i++) {
    std::cin >> a[i];
  }

  std::sort(a.begin(), a.end(), std::greater<i32>{});

  i32 scoreDiff = 0;

  for (usize i = 0; i < N; i++) {
    if (i % 2 == 0) {
      scoreDiff += a[i];
    } else {
      scoreDiff -= a[i];
    }
  }

  std::cout << scoreDiff << std::endl;
  return 0;
}