#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
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

struct Point {
  i64 x, y, h;
};

int main() {
  i64 N;
  std::cin >> N;
  std::vector<Point> points(N);
  Point nonZero;

  for (auto &&p : points) {
    std::cin >> p.x >> p.y >> p.h;

    if (p.h != 0) {
      nonZero = p;
    }
  }

  for (i64 y = 0; y <= 100; y++) {
    for (i64 x = 0; x <= 100; x++) {
      i64 h = nonZero.h + std::abs(x - nonZero.x) + std::abs(y - nonZero.y);

      for (auto &&p : points) {
        i64 expectedH =
            std::max(h - std::abs(x - p.x) - std::abs(y - p.y), i64(0));

        if (p.h != expectedH) {
          goto next;
        }
      }

      std::cout << x << ' ' << y << ' ' << h << std::endl;
      goto end;

    next:;
    }
  }

end:;
  return 0;
}