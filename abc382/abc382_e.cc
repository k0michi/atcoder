#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
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

constexpr i64 kNMax = 5000;
constexpr i64 kXMax = 5000;
std::array<std::array<f64, kNMax + 1>, kNMax + 1> memo{};
std::array<f64, kXMax + 1> memo2{};

int main() {
  i64 N, X;
  std::cin >> N >> X;
  std::vector<i64> P(N);

  for (auto &&P_i : P) {
    std::cin >> P_i;
  }

  memo[0][0] = 1;
  for (i64 i = 1; i < N; i++) {
    memo[0][i] = 0;
  }

  for (i64 i = 1; i <= N; i++) {
    for (i64 j = 0; j <= N; j++) {
      memo[i][j] = memo[i - 1][j] * (1 - P[i - 1] / 100.);

      if (j - 1 >= 0) {
        memo[i][j] += memo[i - 1][j - 1] * P[i - 1] / 100.;
      }
    }
  }

  memo2[0] = 0;

  for (i64 i = 1; i <= X; i++) {
    memo2[i] += 1;

    for (i64 j = 1; j <= N; j++) {
      if (i - j >= 0) {
        memo2[i] += memo2[i - j] * memo[N][j];
      }
    }

    memo2[i] /= 1 - memo[N][0];
  }

  std::cout << std::fixed << std::setprecision(7) << memo2[X] << std::endl;
exit:
  return 0;
}