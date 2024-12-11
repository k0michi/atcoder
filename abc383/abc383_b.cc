#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
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

i64 distance(i64 x, i64 y) { return std::abs(x) + std::abs(y); }

int main() {
  i64 H, W, D;
  std::cin >> H >> W >> D;
  std::vector<std::string> S(H);
  for (auto &&S_i : S) {
    std::cin >> S_i;
  }

  i64 max = 0;
  for (i64 i = 0; i < H; i++) {
    for (i64 j = 0; j < W; j++) {
      if (S[i][j] == '#') {
        continue;
      }

      for (i64 k = 0; k < H; k++) {
        for (i64 l = 0; l < W; l++) {
          if (S[k][l] == '#') {
            continue;
          }

          i64 count = 0;

          for (i64 m = 0; m < H; m++) {
            for (i64 n = 0; n < W; n++) {
              if (S[m][n] == '.' && std::min(distance(m - i, n - j),
                                             distance(m - k, n - l)) <= D) {
                count++;
              }
            }
          }

          max = std::max(max, count);
        }
      }
    }
  }

  std::cout << max << std::endl;
exit:
  return 0;
}