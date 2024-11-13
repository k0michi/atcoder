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

i64 H, W;
std::vector<std::vector<char>> c;
std::vector<std::vector<bool>> visited;

bool isInside(i64 x, i64 y) { return x >= 0 && x < W && y >= 0 && y < H; }

bool search(i64 x, i64 y) {
  if (!isInside(x, y) || visited[y][x] || c[y][x] == '#') {
    return false;
  }

  visited[y][x] = true;

  if (c[y][x] == 'g') {
    return true;
  }

  bool result = false;
  result = result || search(x - 1, y);
  result = result || search(x + 1, y);
  result = result || search(x, y - 1);
  result = result || search(x, y + 1);
  return result;
}

int main() {
  std::cin >> H >> W;
  c.resize(H);
  visited.resize(H);
  i64 startX, startY;

  for (i64 y = 0; y < H; y++) {
    c[y].resize(W);
    visited[y].resize(W, false);

    for (i64 x = 0; x < W; x++) {
      std::cin >> c[y][x];

      if (c[y][x] == 's') {
        startX = x;
        startY = y;
      }
    }
  }

  std::cout << (search(startX, startY) ? "Yes" : "No") << std::endl;
exit:
  return 0;
}