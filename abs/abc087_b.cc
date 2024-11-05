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

i32 process50(i32 yen, i32 coins500, i32 coins100, i32 coins50) {
  if (yen < 0 || coins50 == -1) {
    return 0;
  } else if (yen == 0) {
    return 1;
  }

  return process50(yen - 50, coins500, coins100, coins50 - 1);
}

i32 process100(i32 yen, i32 coins500, i32 coins100, i32 coins50) {
  if (yen < 0 || coins100 == -1) {
    return 0;
  } else if (yen == 0) {
    return 1;
  }

  return process100(yen - 100, coins500, coins100 - 1, coins50) +
         process50(yen, coins500, coins100, coins50);
}

i32 process500(i32 yen, i32 coins500, i32 coins100, i32 coins50) {
  if (yen < 0 || coins500 == -1) {
    return 0;
  } else if (yen == 0) {
    return 1;
  }

  return process500(yen - 500, coins500 - 1, coins100, coins50) +
         process100(yen, coins500, coins100, coins50);
}

int main() {
  i32 A, B, C, X;
  std::cin >> A >> B >> C >> X;
  std::cout << process500(X, A, B, C) << std::endl;
  return 0;
}