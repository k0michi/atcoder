#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
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

constexpr i64 kNMax = 100;
constexpr i64 kVMax = 100000;
std::array<std::array<i64, kVMax + 1>, kNMax + 1> memo;
constexpr i64 kInf = i64(1) << 62;

int main() {
  i64 N, W;
  std::cin >> N >> W;
  std::vector<i64> w(N), v(N);

  for (i64 i = 0; i < N; i++) {
    std::cin >> w[i] >> v[i];
  }

  memo[0].fill(kInf);
  memo[0][0] = 0;

  for (i64 i = 1; i <= N; i++) {
    for (i64 j = 0; j <= kVMax; j++) {
      memo[i][j] =
          j - v[i - 1] >= 0
              ? std::min(memo[i - 1][j], memo[i - 1][j - v[i - 1]] + w[i - 1])
              : memo[i - 1][j];
    }
  }

  for (i64 i = kVMax; i >= 0; i--) {
    if (memo[N][i] <= W) {
      std::cout << i << std::endl;
      break;
    }
  }

exit:
  return 0;
}