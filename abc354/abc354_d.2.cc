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

i64 cell(i64 x, i64 y) {
  if (x == 0 && y == 0 || x == 1 && y == 1) {
    return 2;
  } else if (x == 1 && y == 0 || x == 0 && y == 1) {
    return 1;
  }

  return 2 - cell(x - 2, y);
}

i64 area(i64 x, i64 y) {
  if (x >= 0 && x <= 4 && y >= 0 && y <= 2) {
    i64 a = 0;

    for (i64 i = 0; i < y; i++) {
      for (i64 j = 0; j < x; j++) {
        a += cell(j, i);
      }
    }

    return a;
  }

  if (y >= 0 && y <= 2) {
    return area(4, y) * (x / 4) + area(x % 4, y);
  }

  return area(x, 2) * (y / 2) + area(x, y % 2);
}

constexpr i64 kMax = 1000000000;

int main() {
  i64 A, B, C, D;
  std::cin >> A >> B >> C >> D;
  A += kMax;
  B += kMax;
  C += kMax;
  D += kMax;
  i64 a = area(C, D) - area(A, D) - area(C, B) + area(A, B);
  std::cout << a << std::endl;
exit:
  return 0;
}