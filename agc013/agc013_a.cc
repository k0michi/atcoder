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
  i64 N;
  std::cin >> N;
  i64 last;
  std::cin >> last;
  bool increasing = false, decreasing = false;
  i64 splits = 0;

  for (i64 i = 1; i < N; i++) {
    i64 A_i;
    std::cin >> A_i;

    if (A_i > last) {
      if (decreasing) {
        splits++;
        decreasing = false;
      } else {
        increasing = true;
      }
    } else if (A_i < last) {
      if (increasing) {
        splits++;
        increasing = false;
      } else {
        decreasing = true;
      }
    }

    last = A_i;
  }

  std::cout << (splits + 1) << std::endl;
  return 0;
}