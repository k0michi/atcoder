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

template <typename T, typename U, typename V, typename W>
inline U getOrDefault(const std::map<T, U, V, W> &map, T index, U orDefault) {
  if (map.contains(index)) {
    return map.at(index);
  }

  return orDefault;
}

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::vector<std::pair<i64, i64>> blacks;
  std::map<i64, i64, std::greater<i64>> whitesX, whitesY;
  whitesX[0] = N + 1;
  whitesY[0] = N + 1;

  for (i64 i = 0; i < M; i++) {
    i64 X_i, Y_i;
    char C_i;
    std::cin >> X_i >> Y_i >> C_i;

    if (C_i == 'B') {
      blacks.push_back({X_i, Y_i});
    } else {
      whitesX[Y_i] = std::min(getOrDefault(whitesX, Y_i, N + 1), X_i);
      whitesY[X_i] = std::min(getOrDefault(whitesY, X_i, N + 1), Y_i);
    }
  }

  auto last = whitesX.rbegin()->second;

  for (auto it = whitesX.rbegin(); it != whitesX.rend(); it++) {
    it->second = std::min(it->second, last);
    last = it->second;
  }

  last = whitesY.rbegin()->second;

  for (auto it = whitesY.rbegin(); it != whitesY.rend(); it++) {
    it->second = std::min(it->second, last);
    last = it->second;
  }

  bool can = true;

  for (auto &&black : blacks) {
    auto x = whitesX.lower_bound(black.second)->second;
    auto y = whitesY.lower_bound(black.first)->second;
    if (black.first >= x || black.second >= y) {
      can = false;
    }
  }

  std::cout << (can ? "Yes" : "No") << std::endl;
exit:
  return 0;
}