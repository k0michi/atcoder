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

i64 bfs(i64 node) {
  std::vector<bool> visited(N);
  std::list<std::pair<i64, i64>> queue;
  queue.push_back({node, 0});
  i64 count = 0;

  while (!queue.empty()) {
    auto [p, d] = queue.front();
    queue.pop_front();

    if (!visited[p]) {
      visited[p] = true;

      if (d == 2) {
        count++;
      } else {
        for (auto n : edges[p]) {
          queue.push_back({n, d + 1});
        }
      }
    }
  }

  return count;
}

int main() {
  std::cin >> N >> M;
  edges.resize(N);

  for (i64 i = 0; i < M; i++) {
    i64 A_i, B_i;
    std::cin >> A_i >> B_i;
    A_i--;
    B_i--;
    edges[A_i].push_back(B_i);
    edges[B_i].push_back(A_i);
  }

  for (i64 i = 0; i < N; i++) {
    std::cout << bfs(i) << std::endl;
  }
exit:
  return 0;
}