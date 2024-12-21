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
  std::vector<std::vector<i64>> edges(N);

  for (i64 i = 0; i < N - 1; i++) {
    i64 u_i, v_i;
    std::cin >> u_i >> v_i;
    u_i--;
    v_i--;
    edges[u_i].push_back(v_i);
    edges[v_i].push_back(u_i);
  }

  i64 min = std::numeric_limits<i64>::max();

  for (i64 i = 0; i < N; i++) {
    std::sort(edges[i].begin(), edges[i].end(), [&](auto &&a, auto &&b) {
      return edges[a].size() > edges[b].size();
    });

    i64 x = 1;

    for (auto &&j : edges[i]) {
      i64 y = edges[j].size() - 1;
      min = std::min(min, N - (1 + x + x * y));
      x++;
    }
  }

  std::cout << min << std::endl;
exit:
  return 0;
}