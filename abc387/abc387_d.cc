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

struct Vector2I {
  i64 x, y;

  i64 lengthSquared() { return x * x + y * y; }

  f64 length() { return std::sqrt(lengthSquared()); }

  bool operator==(const Vector2I &other) const {
    return x == other.x && y == other.y;
  }
};

Vector2I operator+(const Vector2I &a, const Vector2I &b) {
  return {a.x + b.x, a.y + b.y};
}

i64 H, W;
std::vector<std::vector<char>> S;
std::vector<std::vector<i64>> distance;
Vector2I start, goal;

constexpr i64 kInf = std::numeric_limits<i64>::max() / 2;
const std::vector<std::vector<Vector2I>> kMoves = {{{1, 0}, {-1, 0}},
                                                   {{0, 1}, {0, -1}}};

bool canEnter(const Vector2I &v) {
  return v.x >= 0 && v.x < W && v.y >= 0 && v.y < H && S[v.y][v.x] != '#';
}

i64 bfs(i64 initialMove) {
  std::list<std::pair<Vector2I, i64>> queue;
  queue.push_back({start, 0});

  while (!queue.empty()) {
    auto [n, d] = queue.front();
    queue.pop_front();

    if (distance[n.y][n.x] == -1) {
      distance[n.y][n.x] = d;

      for (auto next : kMoves[(initialMove + d) % 2]) {
        if (canEnter(n + next)) {
          queue.push_back({n + next, d + 1});
        }
      }
    }
  }

  return distance[goal.y][goal.x] == -1 ? kInf : distance[goal.y][goal.x];
}

int main() {
  std::cin >> H >> W;
  S.resize(H, std::vector<char>(W));

  for (i64 i = 0; i < H; i++) {
    for (i64 j = 0; j < W; j++) {
      std::cin >> S[i][j];

      if (S[i][j] == 'S') {
        start = {j, i};
      } else if (S[i][j] == 'G') {
        goal = {j, i};
      }
    }
  }

  distance.resize(H, std::vector<i64>(W, -1));
  i64 min = bfs(0);
  distance.clear();
  distance.resize(H, std::vector<i64>(W, -1));
  min = std::min(min, bfs(1));
  std::cout << (min == kInf ? -1 : min) << std::endl;
exit:
  return 0;
}