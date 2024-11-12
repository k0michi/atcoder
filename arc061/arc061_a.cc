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

i64 pow10(i64 x) { return i64(std::pow(10, x)); }

int main() {
  i64 S;
  std::cin >> S;
  i64 total = 0;
  i64 digits = i64(std::floor(std::log10(S)));

  for (i64 i = 0; i < (1 << digits); i++) {
    i64 STemp = S;

    for (i64 j = 0, k = 1; j < digits; j++, k++) {
      if (((i >> j) & 1) == 1) {
        total += STemp % pow10(k);
        STemp /= pow10(k);
        k = 0;
      }
    }

    total += STemp;
  }

  std::cout << total << std::endl;
exit:
  return 0;
}