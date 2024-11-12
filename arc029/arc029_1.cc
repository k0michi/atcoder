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

i64 N;
std::vector<i64> t;

i64 calculateTime(i64 meats) {
  i64 time1 = 0, time2 = 0;

  for (i64 i = 0; i < N; i++) {
    if ((meats >> i) & 1) {
      time1 += t[i];
    } else {
      time2 += t[i];
    }
  }

  return std::max(time1, time2);
}

int main() {
  std::cin >> N;
  t.resize(N);

  for (auto &&t_i : t) {
    std::cin >> t_i;
  }

  i64 minTime = std::numeric_limits<i64>::max();

  for (i64 i = 0; i < (1 << N); i++) {
    minTime = std::min(calculateTime(i), minTime);
  }

  std::cout << minTime << std::endl;
exit:
  return 0;
}