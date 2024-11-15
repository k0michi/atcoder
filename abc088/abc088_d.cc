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

i64 H, W;
std::vector<std::vector<char>> field;
std::vector<std::vector<bool>> visited;

struct Vector2 {
  i64 x, y;

  bool operator==(const Vector2 &other) const {
    return x == other.x && y == other.y;
  }
};

bool canEnter(i64 x, i64 y) {
  return x >= 0 && x < W && y >= 0 && y < H && field[y][x] != '#';
}

void tryAddNextPoint(std::deque<std::pair<Vector2, i64>> &queue, i64 x, i64 y,
                     i64 currentDistance) {
  if (!canEnter(x, y)) {
    return;
  }

  queue.push_back({{x, y}, currentDistance + 1});
}

i64 bfs() {
  visited.resize(H);
  for (i64 y = 0; y < H; y++) {
    visited[y].resize(W);
    std::fill(visited[y].begin(), visited[y].end(), false);
  }

  std::deque<std::pair<Vector2, i64>> queue;
  queue.push_back(std::make_pair<Vector2, i64>({0, 0}, 0));
  i64 distance = -1;

  while (!queue.empty()) {
    auto q = queue.front();
    queue.pop_front();

    if (!visited[q.first.y][q.first.x]) {
      visited[q.first.y][q.first.x] = true;

      if (q.first == Vector2{W - 1, H - 1}) {
        distance = q.second;
        break;
      }

      tryAddNextPoint(queue, q.first.x + 1, q.first.y, q.second);
      tryAddNextPoint(queue, q.first.x - 1, q.first.y, q.second);
      tryAddNextPoint(queue, q.first.x, q.first.y + 1, q.second);
      tryAddNextPoint(queue, q.first.x, q.first.y - 1, q.second);
    }
  }

  return distance;
}

int main() {
  std::cin >> H >> W;
  field.resize(H);
  i64 whites = 0;

  for (i64 y = 0; y < H; y++) {
    field[y].resize(W);
    for (i64 x = 0; x < W; x++) {
      std::cin >> field[y][x];

      if (field[y][x] == '.') {
        whites++;
      }
    }
  }

  i64 way = bfs() + 1;
  i64 fillable = whites - way;
  std::cout << (way == 0 ? -1 : fillable) << std::endl;
exit:
  return 0;
}