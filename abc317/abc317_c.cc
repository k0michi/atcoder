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
  i64 N, M;
  std::cin >> N >> M;
  std::vector<std::vector<i64>> edges(N, std::vector<i64>(N, -1));

  for (i64 i = 0; i < M; i++) {
    i64 A_i, B_i, C_i;
    std::cin >> A_i >> B_i >> C_i;
    A_i--;
    B_i--;
    edges[A_i][B_i] = C_i;
    edges[B_i][A_i] = C_i;
  }

  std::vector<i64> path(N);
  std::iota(path.begin(), path.end(), 0);
  i64 max = 0;

  do {
    i64 length = 0;

    for (i64 i = 1; i < N; i++) {
      if (edges[path[i - 1]][path[i]] != -1) {
        length += edges[path[i - 1]][path[i]];
      } else {
        break;
      }
    }

    max = std::max(max, length);
  } while (std::next_permutation(path.begin(), path.end()));

  std::cout << max << std::endl;
exit:
  return 0;
}