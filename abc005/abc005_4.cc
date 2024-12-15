#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cctype>
#include <cmath>
#include <compare>
#include <cstdint>
#include <deque>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
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
  std::vector<std::vector<i64>> D(N, std::vector<i64>(N));
  for (auto &&D_i : D) {
    for (auto &&D_ij : D_i) {
      std::cin >> D_ij;
    }
  }

  std::vector<std::vector<i64>> cumulative(N + 1, std::vector<i64>(N + 1));
  for (i64 i = 1; i < N + 1; i++) {
    for (i64 j = 1; j < N + 1; j++) {
      cumulative[i][j] = cumulative[i - 1][j] + cumulative[i][j - 1] -
                         cumulative[i - 1][j - 1] + D[i - 1][j - 1];
    }
  }

  std::vector<i64> maxs(N * N + 1);

  for (i64 y1 = 0; y1 < N + 1; y1++) {
    for (i64 x1 = 0; x1 < N + 1; x1++) {
      for (i64 y2 = y1 + 1; y2 < N + 1; y2++) {
        for (i64 x2 = x1 + 1; x2 < N + 1; x2++) {
          i64 area = (x2 - x1) * (y2 - y1);
          maxs[area] =
              std::max(maxs[area], cumulative[y2][x2] - cumulative[y2][x1] -
                                       cumulative[y1][x2] + cumulative[y1][x1]);
        }
      }
    }
  }

  for (i64 i = 1; i < maxs.size(); i++) {
    maxs[i] = std::max(maxs[i], maxs[i - 1]);
  }

  i64 Q;
  std::cin >> Q;

  for (i64 i = 0; i < Q; i++) {
    i64 P_i;
    std::cin >> P_i;
    std::cout << maxs[P_i] << std::endl;
  }
exit:
  return 0;
}