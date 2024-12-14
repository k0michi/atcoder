#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cctype>
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

i64 N, M;
std::vector<std::vector<i64>> edges;

i64 bfs(i64 start) {
  std::vector<bool> visited(N);
  std::list<std::pair<i64, i64>> queue;
  queue.push_back({start, 0});
  i64 count = 0;

  while (!queue.empty()) {
    auto [n, d] = queue.front();
    queue.pop_front();

    if (n == start && d > 0) {
      return d;
    }

    if (!visited[n]) {
      visited[n] = true;

      for (auto next : edges[n]) {
        queue.push_back({next, d + 1});
      }
    }
  }

  return -1;
}

int main() {
  std::cin >> N >> M;
  edges.resize(N);
  for (i64 i = 0; i < M; i++) {
    i64 a_i, b_i;
    std::cin >> a_i >> b_i;
    a_i--;
    b_i--;
    edges[a_i].push_back(b_i);
  }

  std::cout << bfs(0) << std::endl;
exit:
  return 0;
}