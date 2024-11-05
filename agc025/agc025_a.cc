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

i32 sumDigits(i32 x) {
  i32 sum = 0;

  while (x > 0) {
    sum += x % 10;
    x /= 10;
  }

  return sum;
}

int main() {
  i32 N;
  std::cin >> N;

  i32 min = std::numeric_limits<i32>::max();

  for (i32 a = 1; a < N; a++) {
    i32 b = N - a;
    min = std::min(sumDigits(a) + sumDigits(b), min);
  }

  std::cout << min << std::endl;
  return 0;
}