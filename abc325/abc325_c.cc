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

i64 H, W;
std::vector<std::string> S;
std::vector<std::vector<bool>> visited;

bool canEnter(i64 x, i64 y) {
  return x >= 0 && x < W && y >= 0 && y < H && S[y][x] == '#';
}

bool bfs(i64 x, i64 y) {
  if (!visited[y][x]) {
    visited[y][x] = true;

    for (i64 dx = -1; dx <= 1; dx++) {
      for (i64 dy = -1; dy <= 1; dy++) {
        if (canEnter(x + dx, y + dy)) {
          bfs(x + dx, y + dy);
        }
      }
    }
    return true;
  } else {
    return false;
  }
}

int main() {
  std::cin >> H >> W;
  S.resize(H);

  for (auto &&S_i : S) {
    std::cin >> S_i;
  }

  visited.resize(H);

  for (auto &&v : visited) {
    v.resize(W);
  }

  i64 count = 0;

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      if (canEnter(x, y)) {
        count += i64(bfs(x, y));
      }
    }
  }

  std::cout << count << std::endl;
exit:
  return 0;
}