#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
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

int main() {
  i64 n;
  std::cin >> n;
  i64 subtotalNeg = 0, countNeg = 0;
  i64 subtotalPos = 0, countPos = 0;

  for (i64 i = 0; i < n; i++) {
    i64 a_i;
    std::cin >> a_i;
    subtotalNeg += a_i;
    subtotalPos += a_i;

    if (subtotalNeg >= 0 && i % 2 == 0 || subtotalNeg <= 0 && i % 2 == 1) {
      countNeg += std::abs(subtotalNeg) + 1;
      subtotalNeg = i % 2 == 0 ? -1 : 1;
    }

    if (subtotalPos <= 0 && i % 2 == 0 || subtotalPos >= 0 && i % 2 == 1) {
      countPos += std::abs(subtotalPos) + 1;
      subtotalPos = i % 2 == 0 ? 1 : -1;
    }
  }

  std::cout << std::min(countNeg, countPos) << std::endl;
  return 0;
}