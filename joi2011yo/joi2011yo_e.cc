#include <algorithm>
#include <array>
#include <bit>
#include <cassert>
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

struct Mouse {
  Vector2 position;
  i64 time;
};

i64 H, W, N;
std::vector<std::vector<char>> field;
std::vector<std::vector<bool>> visited;

bool canEnter(i64 x, i64 y) {
  return x >= 0 && x < W && y >= 0 && y < H && field[y][x] != 'X';
}

i64 parseInt(char x) { return x - '0'; }

bool isInt(char x) { return x >= '0' && x <= '9'; }

void tryAddNextPoint(std::deque<Mouse> &queue, i64 x, i64 y,
                     const Mouse &current) {
  if (!canEnter(x, y)) {
    return;
  }

  queue.push_back({{x, y}, current.time + 1});
}

i64 distance(Vector2 a, Vector2 b) {
  visited.resize(H);
  for (i64 y = 0; y < H; y++) {
    visited[y].resize(W);
    for (i64 x = 0; x < W; x++) {
      visited[y][x] = false;
    }
  }

  std::deque<Mouse> queue;
  queue.push_back({a, 0});
  i64 completion = -1;

  while (!queue.empty()) {
    auto q = queue.front();
    queue.pop_front();

    if (visited[q.position.y][q.position.x]) {
      continue;
    }

    visited[q.position.y][q.position.x] = true;

    if (q.position == b) {
      completion = q.time;
      break;
    }

    tryAddNextPoint(queue, q.position.x + 1, q.position.y, q);
    tryAddNextPoint(queue, q.position.x - 1, q.position.y, q);
    tryAddNextPoint(queue, q.position.x, q.position.y + 1, q);
    tryAddNextPoint(queue, q.position.x, q.position.y - 1, q);
  }

  return completion;
}

int main() {
  std::cin >> H >> W >> N;
  field.resize(H);
  std::vector<std::pair<Vector2, i64>> points;

  for (i64 y = 0; y < H; y++) {
    field[y].resize(W);

    for (i64 x = 0; x < W; x++) {
      std::cin >> field[y][x];

      if (field[y][x] == 'S') {
        points.push_back(std::make_pair<Vector2, i64>({x, y}, 0));
      }

      if (isInt(field[y][x])) {
        points.push_back(
            std::make_pair<Vector2, i64>({x, y}, parseInt(field[y][x])));
      }
    }
  }

  std::sort(points.begin(), points.end(),
            [](auto &&a, auto &&b) { return a.second < b.second; });

  i64 totalDistance = 0;

  for (i64 i = 0; i < points.size() - 1; i++) {
    totalDistance += distance(points[i].first, points[i + 1].first);
  }

  std::cout << totalDistance << std::endl;
exit:
  return 0;
}