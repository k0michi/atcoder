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

struct Vector2 {
  i64 x, y;
};

Vector2 operator+(const Vector2 &a, const Vector2 &b) {
  return {a.x + b.x, a.y + b.y};
}

std::ostream &operator<<(std::ostream &s, const Vector2 &v) {
  s << v.x << ' ' << v.y;
  return s;
}

Vector2 getDelta(char direction) {
  switch (direction) {
  case 'R':
    return {1, 0};
  case 'L':
    return {-1, 0};
  case 'U':
    return {0, 1};
  case 'D':
    return {0, -1};
  }
}

int main() {
  i64 N, Q;
  std::cin >> N >> Q;
  std::deque<Vector2> parts;

  for (i64 i = 1; i <= N; i++) {
    parts.push_back({i, 0});
  }

  for (i64 i = 0; i < Q; i++) {
    i64 op;
    std::cin >> op;

    if (op == 1) {
      char C;
      std::cin >> C;
      auto head = parts.front();
      parts.pop_back();
      parts.push_front(head + getDelta(C));
    } else {
      i64 p;
      std::cin >> p;
      std::cout << parts[p - 1] << std::endl;
    }
  }
exit:
  return 0;
}