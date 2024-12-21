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

struct PairHash {
  inline usize operator()(const std::pair<i64, i64> &p) const {
    return p.first * 31 + p.second;
  }
};

int main() {
  i64 N, M, S_x, S_y;
  std::cin >> N >> M >> S_x >> S_y;
  std::unordered_map<i64, std::set<i64>> rows, columns;

  for (i64 i = 0; i < N; i++) {
    i64 X_i, Y_i;
    std::cin >> X_i >> Y_i;
    rows[Y_i].insert(X_i);
    columns[X_i].insert(Y_i);
  }

  std::unordered_set<std::pair<i64, i64>, PairHash> visited;

  for (i64 i = 0; i < M; i++) {
    char D_i;
    i64 C_i;
    std::cin >> D_i >> C_i;

    switch (D_i) {
    case 'U': {
      auto lb = columns[S_x].lower_bound(S_y);

      while (*lb <= S_y + C_i && lb != columns[S_x].end()) {
        visited.insert({S_x, *lb});
        lb++;
      }

      S_y += C_i;
      break;
    }
    case 'D': {
      auto lb = columns[S_x].lower_bound(S_y - C_i);

      while (*lb <= S_y && lb != columns[S_x].end()) {
        visited.insert({S_x, *lb});
        lb++;
      }

      S_y -= C_i;
      break;
    }
    case 'L': {
      auto lb = rows[S_y].lower_bound(S_x - C_i);

      while (*lb <= S_x && lb != rows[S_y].end()) {
        visited.insert({*lb, S_y});
        lb++;
      }

      S_x -= C_i;
      break;
    }
    case 'R': {
      auto lb = rows[S_y].lower_bound(S_x);

      while (*lb <= S_x + C_i && lb != rows[S_y].end()) {
        visited.insert({*lb, S_y});
        lb++;
      }

      S_x += C_i;
      break;
    }
    }
  }

  std::cout << S_x << ' ' << S_y << ' ' << visited.size() << std::endl;
exit:
  return 0;
}