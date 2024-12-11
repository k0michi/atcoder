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

i64 H, W, D;
std::vector<std::string> S;

bool canEnter(const Vector2 &p) {
  return p.x >= 0 && p.x < W && p.y >= 0 && p.y < H && S[p.y][p.x] == '.';
}

int main() {
  std::cin >> H >> W >> D;
  S.resize(H);
  for (auto &&S_i : S) {
    std::cin >> S_i;
  }

  std::vector<std::vector<bool>> visited(H, std::vector<bool>(W, false));
  std::list<std::pair<Vector2, i64>> queue;

  for (i64 i = 0; i < H; i++) {
    for (i64 j = 0; j < W; j++) {
      if (S[i][j] == 'H') {
        queue.push_back({{j, i}, 0});
      }
    }
  }

  i64 cells = 0;

  while (!queue.empty()) {
    auto [p, d] = queue.front();
    queue.pop_front();

    if (!visited[p.y][p.x]) {
      if (d <= D) {
        cells++;
      }

      for (auto &&delta :
           {Vector2{1, 0}, Vector2{-1, 0}, Vector2{0, 1}, Vector2{0, -1}}) {
        if (canEnter(p + delta)) {
          queue.push_back({p + delta, d + 1});
        }
      }

      visited[p.y][p.x] = true;
    }
  }

  std::cout << cells << std::endl;
exit:
  return 0;
}