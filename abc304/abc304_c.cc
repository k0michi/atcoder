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

struct Vector2 {
  i64 x, y;

  i64 lengthSquared() { return x * x + y * y; }

  f64 length() { return std::sqrt(lengthSquared()); }
};

Vector2 operator-(const Vector2 &a, const Vector2 &b) {
  return {a.x - b.x, a.y - b.y};
}

std::istream &operator>>(std::istream &s, Vector2 &v) {
  std::cin >> v.x >> v.y;
  return s;
}

i64 N, D;
std::vector<Vector2> points;
std::vector<bool> visited;

void dfs(i64 v) {
  if (!visited[v]) {
    visited[v] = true;

    for (i64 i = 0; i < N; i++) {
      if ((points[v] - points[i]).lengthSquared() <= D * D) {
        dfs(i);
      }
    }
  }
}

int main() {
  std::cin >> N >> D;
  points.resize(N);
  visited.resize(N);

  for (i64 i = 0; i < N; i++) {
    std::cin >> points[i];
  }

  dfs(0);

  for (i64 i = 0; i < N; i++) {
    std::cout << (visited[i] ? "Yes" : "No") << std::endl;
  }
exit:
  return 0;
}