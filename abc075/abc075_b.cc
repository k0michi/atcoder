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

struct Cell {
  bool bomb = false;
  i64 adjacents = 0;
};

int main() {
  i64 H, W;
  std::cin >> H >> W;
  std::vector<std::vector<Cell>> grid(H, std::vector<Cell>(W));

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      char c;
      std::cin >> c;

      if (c == '.') {
      } else if (c == '#') {
        grid[y][x].bomb = true;

        for (i64 dy = -1; dy <= 1; dy++) {
          for (i64 dx = -1; dx <= 1; dx++) {
            if (y + dy >= 0 && y + dy < H && x + dx >= 0 && x + dx < W) {
              grid[y + dy][x + dx].adjacents++;
            }
          }
        }
      }
    }
  }

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      if (grid[y][x].bomb) {
        std::cout << '#';
      } else {
        std::cout << grid[y][x].adjacents;
      }
    }
    std::cout << std::endl;
  }
  return 0;
}