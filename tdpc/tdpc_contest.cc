#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <set>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
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
  std::vector<i64> p(N);
  for (auto &&p_i : p) {
    std::cin >> p_i;
  }

  i64 sumMax = 100 * 100;
  std::vector<std::vector<bool>> memo(N + 1,
                                      std::vector<bool>(sumMax + 1, false));

  for (i64 i = 0; i < N; i++) {
    memo[i][0] = true;
  }

  for (i64 i = 0; i < N; i++) {
    for (i64 j = 0; j < sumMax + 1; j++) {
      if (j - p[i] >= 0) {
        memo[i + 1][j] = memo[i + 1][j] || memo[i][j - p[i]];
      }
      memo[i + 1][j] = memo[i + 1][j] || memo[i][j];
    }
  }

  i64 count = 0;
  for (i64 i = 0; i < sumMax + 1; i++) {
    if (memo[N][i]) {
      count++;
    }
  }
  std::cout << count << std::endl;
exit:
  return 0;
}