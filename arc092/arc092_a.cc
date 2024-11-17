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
#include <map>
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
};

bool canMakePair(Vector2 red, Vector2 blue) {
  return red.x < blue.x && red.y < blue.y;
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<Vector2> reds(N), blues(N);
  for (i64 i = 0; i < N; i++) {
    std::cin >> reds[i].x >> reds[i].y;
  }
  for (i64 i = 0; i < N; i++) {
    std::cin >> blues[i].x >> blues[i].y;
  }

  std::sort(reds.begin(), reds.end(),
            [](auto &&a, auto &&b) { return a.y < b.y; });
  std::sort(blues.begin(), blues.end(),
            [](auto &&a, auto &&b) { return a.x < b.x; });
  std::unordered_set<i64> used;
  i64 count = 0;

  for (i64 i = 0; i < N; i++) {
    for (i64 j = N - 1; j >= 0; j--) {
      if (used.count(j) == 0 && canMakePair(reds[j], blues[i])) {
        count++;
        used.insert(j);
        break;
      }
    }
  }

  std::cout << count << std::endl;
exit:
  return 0;
}