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

template <class T, class Container = std::vector<T>,
          class Compare = std::greater<typename Container::value_type>>
using ReversePriorityQueue = std::priority_queue<T, Container, Compare>;

struct Vector2 {
  i64 x, y;
};

Vector2 operator+(const Vector2 &a, const Vector2 &b) {
  return {a.x + b.x, a.y + b.y};
}

bool operator<(const Vector2 &a, const Vector2 &b) {
  return a.x != b.x ? a.x < b.x : a.y < b.y;
}

i64 H, W, X, P, Q;

i64 canEnter(const Vector2 &v) {
  return v.x >= 0 && v.x < W && v.y >= 0 && v.y < H;
}

int main() {
  std::cin >> H >> W >> X >> P >> Q;
  std::vector<std::vector<i64>> S(H, std::vector<i64>(W));

  for (i64 i = 0; i < H; i++) {
    for (i64 j = 0; j < W; j++) {
      std::cin >> S[i][j];
    }
  }

  i64 size = S[P - 1][Q - 1];
  ReversePriorityQueue<std::pair<i64, Vector2>> queue;
  std::vector<std::vector<bool>> visited(H, std::vector<bool>(W));
  queue.push({0, {Q - 1, P - 1}});

  while (!queue.empty()) {
    auto [pow, pos] = queue.top();
    queue.pop();

    if (!visited[pos.y][pos.x]) {
      visited[pos.y][pos.x] = true;

      if (pow >= f64(size) / X) {
        break;
      }

      size += pow;

      for (auto &&d :
           std::initializer_list<Vector2>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
        auto next = pos + d;

        if (canEnter(next)) {
          queue.push({S[next.y][next.x], next});
        }
      }
    }
  }

  std::cout << size << std::endl;
exit:
  return 0;
}