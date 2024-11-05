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
  i32 opMin = std::numeric_limits<i32>::max();

  for (i32 i = 0; i < N; i++) {
    i32 A_i;
    std::cin >> A_i;

    i32 op = 0;

    while ((A_i & 1) == 0) {
      A_i >>= 1;
      op++;
    }

    opMin = std::min(op, opMin);
  }

  std::cout << opMin << std::endl;
  return 0;
}