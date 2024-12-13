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

struct Vector2 {
  i64 x, y;

  i64 lengthSquared() { return x * x + y * y; }

  f64 length() { return std::sqrt(lengthSquared()); }
};

Vector2 operator-(const Vector2 &a, const Vector2 &b) {
  return {a.x - b.x, a.y - b.y};
}

int main() {
  i64 tx_a, ty_a, tx_b, ty_b, T, V, n;
  std::cin >> tx_a >> ty_a >> tx_b >> ty_b >> T >> V >> n;
  std::vector<i64> x(n), y(n);
  for (i64 i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }

  bool can = false;
  i64 longestMove = T * V;

  for (i64 i = 0; i < n; i++) {
    f64 distance = (Vector2{x[i], y[i]} - Vector2{tx_a, ty_a}).length() +
                   (Vector2{x[i], y[i]} - Vector2{tx_b, ty_b}).length();
    can = can || (longestMove >= distance);
  }

  std::cout << (can ? "YES" : "NO") << std::endl;
exit:
  return 0;
}