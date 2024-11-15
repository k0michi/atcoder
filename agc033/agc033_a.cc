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

i64 H, W;
std::vector<std::string> A;

bool canEnter(i64 x, i64 y) {
  return x >= 0 && x < W && y >= 0 && y < H && A[y][x] != '#';
}

void tryAddPoint(std::deque<std::pair<Vector2, i64>> &queue, i64 x, i64 y,
                 i64 currentSteps) {
  if (!canEnter(x, y)) {
    return;
  }

  queue.push_back({{x, y}, currentSteps + 1});
}

i64 bfs() {
  std::deque<std::pair<Vector2, i64>> queue;

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      if (A[y][x] == '#') {
        queue.push_back(std::make_pair<Vector2, i64>({x, y}, 0));
        A[y][x] = '.';
      }
    }
  }

  i64 steps = 0;

  while (!queue.empty()) {
    auto q = queue.front();
    queue.pop_front();

    if (A[q.first.y][q.first.x] == '.') {
      steps = q.second;

      A[q.first.y][q.first.x] = '#';
      tryAddPoint(queue, q.first.x + 1, q.first.y, q.second);
      tryAddPoint(queue, q.first.x - 1, q.first.y, q.second);
      tryAddPoint(queue, q.first.x, q.first.y + 1, q.second);
      tryAddPoint(queue, q.first.x, q.first.y - 1, q.second);
    }
  }

  return steps;
}

int main() {
  std::cin >> H >> W;
  A.resize(H);
  for (i64 i = 0; i < H; i++) {
    std::cin >> A[i];
  }

  std::cout << bfs() << std::endl;
exit:
  return 0;
}