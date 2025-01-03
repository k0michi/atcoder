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

int main() {
  i64 H, W;
  std::cin >> H >> W;
  std::vector<std::string> S(H);
  std::cin >> S;

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      if (S[y][x] == '.') {
        i64 count = 0;

        for (i64 y2 = -1; y2 <= 1; y2++) {
          for (i64 x2 = -1; x2 <= 1; x2++) {
            if (std::abs(y2) + std::abs(x2) == 1) {
              count += i64(y + y2 >= 0 && y + y2 < H && x + x2 >= 0 &&
                           x + x2 < W && S[y + y2][x + x2] == '#');
            }
          }
        }

        if (count >= 2) {
          std::cout << y + 1 << ' ' << x + 1 << std::endl;
          goto exit;
        }
      }
    }
  }

exit:
  return 0;
}