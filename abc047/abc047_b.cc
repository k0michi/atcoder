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
#include <type_traits>
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

int main() {
  i64 W, H, N;
  std::cin >> W >> H >> N;
  std::vector<std::vector<bool>> plane(H, std::vector<bool>(W, false));

  for (i64 i = 0; i < N; i++) {
    i64 x_i, y_i, a_i;
    std::cin >> x_i >> y_i >> a_i;

    switch (a_i) {
    case 1:
      for (i64 y = 0; y < H; y++) {
        for (i64 x = 0; x < x_i; x++) {
          plane[y][x] = true;
        }
      }
      break;
    case 2:
      for (i64 y = 0; y < H; y++) {
        for (i64 x = x_i; x < W; x++) {
          plane[y][x] = true;
        }
      }
      break;
    case 3:
      for (i64 y = 0; y < y_i; y++) {
        for (i64 x = 0; x < W; x++) {
          plane[y][x] = true;
        }
      }
      break;
    case 4:
      for (i64 y = y_i; y < H; y++) {
        for (i64 x = 0; x < W; x++) {
          plane[y][x] = true;
        }
      }
      break;
    }
  }

  i64 area = 0;

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      if (plane[y][x] == false) {
        area++;
      }
    }
  }

  std::cout << area << std::endl;
  return 0;
}