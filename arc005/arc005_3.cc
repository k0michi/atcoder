#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
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

  Vector2 operator+(const Vector2 &other) const {
    return {x + other.x, y + other.y};
  }
};

i64 H, W;
std::vector<std::vector<char>> c;
std::vector<std::vector<i64>> distance;
Vector2 start, goal;

bool canEnter(i64 x, i64 y) { return x >= 0 && x < W && y >= 0 && y < H; }

void tryAddVertex(std::deque<Vector2> &queue, Vector2 prev, Vector2 next) {
  if (!canEnter(next.x, next.y)) {
    return;
  }

  if (c[next.y][next.x] == '#') {
    if (distance[next.y][next.x] > distance[prev.y][prev.x] + 1) {
      distance[next.y][next.x] = distance[prev.y][prev.x] + 1;
      queue.push_back(next);
    }
  } else {
    if (distance[next.y][next.x] > distance[prev.y][prev.x]) {
      distance[next.y][next.x] = distance[prev.y][prev.x];
      queue.push_front(next);
    }
  }
}

bool zeroOneBFS() {
  std::deque<Vector2> queue;
  queue.push_back(start);
  distance[start.y][start.x] = 0;

  while (!queue.empty()) {
    auto q = queue.front();
    queue.pop_front();

    if (q == goal && distance[q.y][q.x] <= 2) {
      return true;
    }

    tryAddVertex(queue, q, q + Vector2{+1, 0});
    tryAddVertex(queue, q, q + Vector2{-1, 0});
    tryAddVertex(queue, q, q + Vector2{0, +1});
    tryAddVertex(queue, q, q + Vector2{0, -1});
  }

  return false;
}

int main() {
  std::cin >> H >> W;

  c.resize(H);
  distance.resize(H);
  for (i64 y = 0; y < H; y++) {
    c[y].resize(W);
    distance[y].resize(W, std::numeric_limits<i64>::max());
    for (i64 x = 0; x < W; x++) {
      std::cin >> c[y][x];

      if (c[y][x] == 's') {
        start = {x, y};
      }

      if (c[y][x] == 'g') {
        goal = {x, y};
      }
    }
  }

  std::cout << (zeroOneBFS() ? "YES" : "NO") << std::endl;
exit:
  return 0;
}