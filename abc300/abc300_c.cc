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

template <typename T>
std::istream &operator>>(std::istream &s, std::vector<T> &v) {
  for (auto &&v_i : v) {
    s >> v_i;
  }
  return s;
}

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &v) {
  i64 i = 0;

  for (auto &&v_i : v) {
    if (i > 0) {
      s << ' ';
    }

    s << v_i;
    i++;
  }

  return s;
}

i64 H, W;
std::vector<std::string> S;

char at(i64 x, i64 y) {
  return x >= 0 && x < W && y >= 0 && y < H ? S[y][x] : '.';
}

template <typename T> bool allEqualTo(std::initializer_list<T> l, T value) {
  return std::all_of(l.begin(), l.end(), [&](auto &&v) { return v == value; });
}

int main() {
  std::cin >> H >> W;
  S.resize(H);
  std::cin >> S;

  std::vector<i64> counts(std::min(H, W));

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      if (at(x, y) == '#') {
        i64 s = 0;

        while (allEqualTo(
            {at(x + (s + 1), y + (s + 1)), at(x + (s + 1), y - (s + 1)),
             at(x - (s + 1), y + (s + 1)), at(x - (s + 1), y - (s + 1))},
            '#')) {
          s++;
        }

        if (s >= 1) {
          counts[s - 1]++;
        }
      }
    }
  }

  std::cout << counts << std::endl;
exit:
  return 0;
}