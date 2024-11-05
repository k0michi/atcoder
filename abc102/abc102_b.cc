#include <algorithm>
#include <cstdint>
#include <iostream>
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

int main() {
  i32 N;
  std::cin >> N;
  i32 min = std::numeric_limits<i32>::max(),
      max = std::numeric_limits<i32>::min();

  for (i32 i = 0; i < N; i++) {
    i32 A_i;
    std::cin >> A_i;
    max = std::max(A_i, max);
    min = std::min(A_i, min);
  }

  std::cout << (max - min) << std::endl;
  return 0;
}