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
};

i64 R, C, sy, sx, gy, gx;
std::vector<std::vector<char>> c;
std::vector<std::vector<bool>> visited;

bool canEnter(const Vector2 &p) {
  return p.x >= 0 && p.x < C && p.y >= 0 && p.y < R && c[p.y][p.x] == '.';
}

void addNextPoints(std::deque<std::pair<Vector2, i64>> &queue, const Vector2 &p,
                   i64 distance) {
  queue.push_back(std::make_pair<Vector2, i64>({p.x + 1, p.y}, distance + 1));
  queue.push_back(std::make_pair<Vector2, i64>({p.x - 1, p.y}, distance + 1));
  queue.push_back(std::make_pair<Vector2, i64>({p.x, p.y + 1}, distance + 1));
  queue.push_back(std::make_pair<Vector2, i64>({p.x, p.y - 1}, distance + 1));
}

i64 bfs() {
  std::deque<std::pair<Vector2, i64>> queue;
  queue.push_back(std::make_pair<Vector2, i64>({sx - 1, sy - 1}, 0));
  i64 distance = -1;

  while (!queue.empty()) {
    auto p = queue.front();
    queue.pop_front();

    if (canEnter(p.first) && !visited[p.first.y][p.first.x]) {
      visited[p.first.y][p.first.x] = true;

      if (p.first == Vector2{gx - 1, gy - 1}) {
        distance = p.second;
        break;
      }

      addNextPoints(queue, p.first, p.second);
    }
  }

  return distance;
}

int main() {
  std::cin >> R >> C >> sy >> sx >> gy >> gx;
  c.resize(R);
  visited.resize(R);

  for (i64 y = 0; y < R; y++) {
    c[y].resize(C);
    visited[y].resize(C);
    for (i64 x = 0; x < C; x++) {
      std::cin >> c[y][x];
    }
  }

  std::cout << bfs() << std::endl;
exit:
  return 0;
}