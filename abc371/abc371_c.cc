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

i64 encode(i64 i, i64 j) {
  if (i > j) {
    std::swap(i, j);
  }

  i64 x = j - i - 1;
  i64 y = 6 - i;
  return y * (y + 1) / 2 + x;
}

constexpr i64 maxEdges = 28;

int main() {
  i64 N, M_G;
  std::cin >> N >> M_G;
  std::bitset<maxEdges> edgesG, edgesH;
  for (i64 i = 0; i < M_G; i++) {
    i64 u_i, v_i;
    std::cin >> u_i >> v_i;
    edgesG[encode(u_i - 1, v_i - 1)] = 1;
  }
  i64 M_H;
  std::cin >> M_H;
  for (i64 i = 0; i < M_H; i++) {
    i64 a_i, b_i;
    std::cin >> a_i >> b_i;
    edgesH[encode(a_i - 1, b_i - 1)] = 1;
  }
  std::vector<i64> costs(maxEdges);
  for (i64 i = 0; i < N; i++) {
    for (i64 j = i + 1; j < N; j++) {
      std::cin >> costs[encode(i, j)];
    }
  }

  std::vector<i64> perm(N);
  std::iota(perm.begin(), perm.end(), 0);
  i64 min = std::numeric_limits<i64>::max();

  do {
    i64 cost = 0;

    for (i64 i = 0; i < N; i++) {
      for (i64 j = i + 1; j < N; j++) {
        i64 encodedG = encode(i, j);
        i64 encodedH = encode(perm[i], perm[j]);
        if (edgesG[encodedG] != edgesH[encodedH]) {
          cost += costs[encodedH];
        }
      }
    }

    min = std::min(cost, min);
  } while (std::next_permutation(perm.begin(), perm.end()));

  std::cout << min << std::endl;
exit:
  return 0;
}