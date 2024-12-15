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

i64 normalize(i64 x) {
  if (x == 0) {
    return 0;
  }

  return x / std::abs(x);
}

int main() {
  i64 S_x, S_y, T_x, T_y;
  std::cin >> S_x >> S_y >> T_x >> T_y;
  S_x -= (S_x + S_y) % 2;
  T_x -= (T_x + T_y) % 2;
  i64 diagonal = std::min(std::abs(T_x - S_x), std::abs(T_y - S_y));
  S_x += diagonal * normalize(T_x - S_x);
  S_y += diagonal * normalize(T_y - S_y);
  S_x -= (S_x + S_y) % 2;
  i64 cost = diagonal + std::abs(T_y - S_y) + std::abs(T_x - S_x) / 2;
  std::cout << cost << std::endl;
exit:
  return 0;
}