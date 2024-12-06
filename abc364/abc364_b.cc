#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
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

i64 H, W, S_i, S_j;
std::vector<std::vector<char>> C;
std::string X;

bool canEnter(i64 x, i64 y) {
  return x >= 1 && x <= W && y >= 1 && y <= H && C[y - 1][x - 1] == '.';
}

void tryMove(i64 deltaX, i64 deltaY) {
  if (canEnter(S_j + deltaX, S_i + deltaY)) {
    S_j += deltaX;
    S_i += deltaY;
  }
}

int main() {
  std::cin >> H >> W >> S_i >> S_j;
  C.resize(H, std::vector<char>(W, 0));

  for (i64 i = 0; i < H; i++) {
    for (i64 j = 0; j < W; j++) {
      std::cin >> C[i][j];
    }
  }

  std::cin >> X;

  for (i64 i = 0; i < X.size(); i++) {
    switch (X[i]) {
    case 'L':
      tryMove(-1, 0);
      break;
    case 'R':
      tryMove(1, 0);
      break;
    case 'U':
      tryMove(0, -1);
      break;
    case 'D':
      tryMove(0, 1);
      break;
    }
  }

  std::cout << S_i << ' ' << S_j << std::endl;
exit:
  return 0;
}