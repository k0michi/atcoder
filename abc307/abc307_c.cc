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

template <typename T>
std::istream &operator>>(std::istream &s, std::vector<T> &v) {
  for (auto &&v_i : v) {
    s >> v_i;
  }
  return s;
}

struct Vector2I {
  i64 x, y;
};

struct Sheet {
  i64 h, w;
  std::vector<std::string> cells;

  bool compare(i64 x, i64 y, const Sheet &a, i64 xA, i64 yA, const Sheet &b,
               i64 xB, i64 yB) {
    for (i64 i = 0; i < std::max({h - y, a.h - yA, b.h - yB}); i++) {
      for (i64 j = 0; j < std::max({w - x, a.w - xA, b.w - xB}); j++) {
        if (at(j + x, i + y) != (a.at(j + xA, i + yA) | b.at(j + xB, i + yB))) {
          return false;
        }
      }
    }

    return true;
  }

  bool at(i64 x, i64 y) const {
    if (x < 0 || x >= w || y < 0 || y >= h) {
      return false;
    }

    return cells[y][x] == '#';
  }

  Vector2I topLeft() {
    i64 minX = w, minY = h;

    for (i64 y = 0; y < h; y++) {
      for (i64 x = 0; x < w; x++) {
        if (cells[y][x] == '#') {
          minX = std::min(minX, x);
          minY = std::min(minY, y);
        }
      }
    }

    return {minX, minY};
  }
};

std::istream &operator>>(std::istream &s, Sheet &sheet) {
  std::cin >> sheet.h >> sheet.w;
  sheet.cells.resize(sheet.h);
  std::cin >> sheet.cells;
  return s;
}

int main() {
  Sheet A, B, X;
  std::cin >> A >> B >> X;
  auto ATL = A.topLeft(), BTL = B.topLeft(), XTL = X.topLeft();

  for (i64 y = ATL.y - 9; y <= ATL.y; y++) {
    for (i64 x = ATL.x - 9; x <= ATL.x; x++) {
      for (i64 y2 = BTL.y - 9; y2 <= BTL.y; y2++) {
        for (i64 x2 = BTL.x - 9; x2 <= BTL.x; x2++) {
          if (X.compare(XTL.x, XTL.y, A, x, y, B, x2, y2)) {
            std::cout << "Yes" << std::endl;
            goto exit;
          }
        }
      }
    }
  }

  std::cout << "No" << std::endl;
exit:
  return 0;
}