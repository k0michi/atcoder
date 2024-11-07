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
  i64 N, C, K;
  std::cin >> N >> C >> K;
  std::vector<i64> T(N);

  for (auto &&T_i : T) {
    std::cin >> T_i;
  }

  std::sort(T.begin(), T.end());

  i64 earliest;
  i64 passengers = 0;
  i64 buses = 0;

  for (i64 i = 0; i < N; i++) {
    i64 T_i = T[i];

    if (passengers == 0) {
      earliest = T_i;
    }

    passengers++;

    if (T_i > earliest + K || passengers == C + 1) {
      buses++;
      earliest = T_i;
      passengers = 1;
    }
  }

  if (passengers > 0) {
    buses++;
  }

  std::cout << buses << std::endl;
  return 0;
}