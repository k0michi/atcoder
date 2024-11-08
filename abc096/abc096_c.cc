#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <string>
#include <string_view>
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

i64 distance(i64 x, i64 y, i64 x2, i64 y2) {
  return std::abs(x - x2) + std::abs(y - y2);
}

int main() {
  i64 H, W;
  std::cin >> H >> W;
  std::vector<std::string> grid(H);

  for (auto &&r : grid) {
    std::cin >> r;
  }

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      if (grid[y][x] == '#') {
        for (i64 dy = -1; dy <= 1; dy++) {
          for (i64 dx = -1; dx <= 1; dx++) {
            if (y + dy >= 0 && y + dy < H && x + dx >= 0 && x + dx < W &&
                distance(x, y, x + dx, y + dy) == 1) {
              if (grid[y + dy][x + dx] == '#') {
                goto next;
              }
            }
          }
        }

        std::cout << "No" << std::endl;
        goto end;
      }

    next:;
    }
  }

  std::cout << "Yes" << std::endl;
end:;
  return 0;
}