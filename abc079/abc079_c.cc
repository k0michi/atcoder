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

i64 calc(i64 op, i64 a, i64 b) { return (op & 1) == 0 ? a + b : a - b; }

char toChar(i64 op) { return (op & 1) == 0 ? '+' : '-'; }

int main() {
  i64 in;
  std::cin >> in;
  i64 A = in / 1000, B = in / 100 % 10, C = in / 10 % 10, D = in % 10;

  for (i64 i = 0; i <= 0b111; i++) {
    i64 value = calc(i >> 2, A, B);
    value = calc(i >> 1, value, C);
    value = calc(i, value, D);

    if (value == 7) {
      std::cout << A << toChar(i >> 2) << B << toChar(i >> 1) << C << toChar(i)
                << D << "=7" << std::endl;
      break;
    }
  }

exit:
  return 0;
}