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
  std::array<std::array<i64, 3>, 3> c;

  for (i64 i = 0; i < 3; i++) {
    for (i64 j = 0; j < 3; j++) {
      std::cin >> c[i][j];
    }
  }

  bool result = true;

  for (i64 i = 0; i < 2; i++) {
    for (i64 j = 1; j < 3; j++) {
      result = result && c[i][0] - c[i + 1][0] == c[i][j] - c[i + 1][j];
    }
  }

  for (i64 i = 1; i < 3; i++) {
    for (i64 j = 0; j < 2; j++) {
      result = result && c[0][j] - c[0][j + 1] == c[i][j] - c[i][j + 1];
    }
  }

  std::cout << (result ? "Yes" : "No") << std::endl;
  return 0;
}