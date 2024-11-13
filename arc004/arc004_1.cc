#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
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

using namespace std::literals;

f64 distance(i64 x1, i64 y1, i64 x2, i64 y2) {
  return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> x(N), y(N);

  for (i64 i = 0; i < N; i++) {
    std::cin >> x[i] >> y[i];
  }

  f64 max = 0;

  for (i64 i = 0; i < N; i++) {
    for (i64 j = i + 1; j < N; j++) {
      max = std::max(distance(x[i], y[i], x[j], y[j]), max);
    }
  }

  std::cout << max << std::endl;
exit:
  return 0;
}