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

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::list<T> &l) {
  i64 i = 0;

  for (auto &&l_i : l) {
    if (i > 0) {
      s << ' ';
    }

    s << l_i;
    i++;
  }

  return s;
}

i64 N;
std::vector<i64> edges;
std::vector<bool> visited;

std::list<i64> dfs(i64 v) {
  if (!visited[v]) {
    visited[v] = true;
    auto path = dfs(edges[v]);

    if (path.front() != path.back() || path.size() == 1) {
      path.push_front(v);
    }

    return path;
  } else {
    return {v};
  }
}

int main() {
  std::cin >> N;
  edges.resize(N);

  for (i64 i = 0; i < N; i++) {
    std::cin >> edges[i];
    edges[i]--;
  }

  visited.resize(N);

  auto path = dfs(0);
  path.pop_back();
  std::transform(path.begin(), path.end(), path.begin(),
                 [](auto &&v) { return v + 1; });

  std::cout << path.size() << std::endl;
  std::cout << path << std::endl;
exit:
  return 0;
}