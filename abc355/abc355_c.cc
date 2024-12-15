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
  i64 N, T;
  std::cin >> N >> T;
  std::vector<std::unordered_set<i64>> vertical(N), horizontal(N), diagonal(2);

  for (i64 i = 0; i < T; i++) {
    i64 A_i;
    std::cin >> A_i;
    A_i--;
    i64 x = A_i % N;
    i64 y = A_i / N;

    vertical[x].insert(A_i);
    horizontal[y].insert(A_i);

    if (x == y) {
      diagonal[0].insert(A_i);
    }

    if (x == N - 1 - y) {
      diagonal[1].insert(A_i);
    }

    if (vertical[x].size() == N || horizontal[y].size() == N ||
        diagonal[0].size() == N || diagonal[1].size() == N) {
      std::cout << (i + 1) << std::endl;
      goto exit;
    }
  }

  std::cout << -1 << std::endl;
exit:
  return 0;
}