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
#include <tuple>
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
  i64 N, M, H, K;
  std::string S;
  std::cin >> N >> M >> H >> K >> S;
  std::unordered_set<std::pair<i64, i64>, PairHash> items;

  for (i64 i = 0; i < M; i++) {
    i64 x_i, y_i;
    std::cin >> x_i >> y_i;
    items.insert({x_i, y_i});
  }

  i64 x = 0, y = 0;
  bool can = true;

  for (i64 i = 0; i < N; i++) {
    H--;

    switch (S[i]) {
    case 'R':
      x++;
      break;
    case 'L':
      x--;
      break;
    case 'U':
      y++;
      break;
    case 'D':
      y--;
      break;
    }

    if (H < 0) {
      can = false;
      break;
    } else if (H < K) {
      auto coord = std::pair<i64, i64>{x, y};

      if (items.contains(coord)) {
        items.erase(coord);
        H = K;
      }
    }
  }

  std::cout << (can ? "Yes" : "No") << std::endl;
exit:
  return 0;
}