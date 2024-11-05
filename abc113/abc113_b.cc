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
  i32 N, T, A;
  std::cin >> N >> T >> A;

  i32 index = 0;
  f64 tempDiffMin = std::numeric_limits<f64>::max();

  for (i32 i = 0; i < N; i++) {
    i32 H_i;
    std::cin >> H_i;
    f64 tempDiff = std::abs(A - (T - H_i * 0.006));

    if (tempDiff < tempDiffMin) {
      index = i;
      tempDiffMin = tempDiff;
    }
  }

  std::cout << index + 1 << std::endl;
  return 0;
}