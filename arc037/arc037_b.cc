#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
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

std::unordered_map<i64, std::vector<i64>> edges;
std::vector<bool> visited;

bool visit(i64 i, i64 prev = -1) {
  if (visited[i]) {
    return true;
  }

  visited[i] = true;
  bool cyclic = false;

  for (auto &&c : edges[i]) {
    if (c != prev) {
      cyclic = cyclic || visit(c, i);
    }
  }

  return cyclic;
}

int main() {
  i64 N, M;
  std::cin >> N >> M;

  for (i64 i = 0; i < M; i++) {
    i64 u_i, v_i;
    std::cin >> u_i >> v_i;
    edges[u_i - 1].push_back(v_i - 1);
    edges[v_i - 1].push_back(u_i - 1);
  }

  visited.resize(N);
  i64 count = 0;

  for (i64 i = 0; i < N; i++) {
    if (!visit(i)) {
      count++;
    }
  }

  std::cout << count << std::endl;
exit:
  return 0;
}