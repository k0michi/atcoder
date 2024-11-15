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

i64 N, M;
std::unordered_map<i64, std::vector<i64>> edges;

i64 dfs(std::unordered_set<i64> visited, i64 i) {
  visited.insert(i);

  if (visited.size() == N) {
    return 1;
  }

  i64 routes = 0;

  for (auto &&e : edges[i]) {
    if (visited.count(e) == 0) {
      routes += dfs(visited, e);
    }
  }

  return routes;
}

int main() {
  std::cin >> N >> M;

  for (i64 i = 0; i < M; i++) {
    i64 a_i, b_i;
    std::cin >> a_i >> b_i;
    edges[a_i - 1].push_back(b_i - 1);
    edges[b_i - 1].push_back(a_i - 1);
  }

  std::cout << dfs({}, 0) << std::endl;
exit:
  return 0;
}