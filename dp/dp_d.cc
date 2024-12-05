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
constexpr i64 kWMax = 100000;
std::array<std::array<i64, kWMax + 1>, kNMax + 1> memo;

int main() {
  i64 N, W;
  std::cin >> N >> W;
  std::vector<i64> w(N), v(N);

  for (i64 i = 0; i < N; i++) {
    std::cin >> w[i] >> v[i];
  }

  for (i64 i = 1; i <= N; i++) {
    for (i64 j = 1; j <= W; j++) {
      memo[i][j] =
          j - w[i - 1] >= 0
              ? std::max(memo[i - 1][j], memo[i - 1][j - w[i - 1]] + v[i - 1])
              : memo[i - 1][j];
    }
  }

  std::cout << memo[N][W] << std::endl;

exit:
  return 0;
}