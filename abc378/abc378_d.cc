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

  bool operator==(const Vector2 &other) const {
    return x == other.x && y == other.y;
  }
};

Vector2 operator+(const Vector2 &a, const Vector2 &b) {
  return {a.x + b.x, a.y + b.y};
}

i64 H, W, K;
std::array<std::array<char, 10>, 10> S;

bool canEnter(const Vector2 &v) {
  return v.x >= 0 && v.x < W && v.y >= 0 && v.y < H && S[v.y][v.x] == '.';
}

i64 dfs(const Vector2 &p, i64 d,
        std::array<std::array<bool, 10>, 10> &visited) {
  if (d == K) {
    return 1;
  }

  i64 count = 0;
  visited[p.y][p.x] = true;

  for (auto &&delta :
       {Vector2{1, 0}, Vector2{-1, 0}, Vector2{0, 1}, Vector2{0, -1}}) {
    auto pNext = p + delta;

    if (canEnter(pNext) && !visited[pNext.y][pNext.x]) {
      count += dfs(pNext, d + 1, visited);
    }
  }

  visited[p.y][p.x] = false;
  return count;
}

int main() {
  std::cin >> H >> W >> K;
  for (i64 i = 0; i < H; i++) {
    for (i64 j = 0; j < W; j++) {
      std::cin >> S[i][j];
    }
  }

  i64 count = 0;

  for (i64 i = 0; i < H; i++) {
    for (i64 j = 0; j < W; j++) {
      if (canEnter({j, i})) {
        std::array<std::array<bool, 10>, 10> visited{};
        count += dfs({j, i}, 0, visited);
      }
    }
  }

  std::cout << count << std::endl;
exit:
  return 0;
}