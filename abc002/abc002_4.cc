#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
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

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::unordered_map<i64, i64> relations;

  for (i64 i = 0; i < M; i++) {
    i64 x_i, y_i;
    std::cin >> x_i >> y_i;
    x_i--;
    y_i--;
    relations[x_i] |= (1 << y_i);
    relations[y_i] |= (1 << x_i);
  }

  i64 max = 0;

  for (i64 i = 0; i < (1 << N); i++) {
    i64 members = 0;

    for (i64 j = 0; j < N; j++) {
      if ((i >> j) & 1) {
        i64 masked = i & ~(1 << j);

        if ((masked & relations[j]) != masked) {
          goto next;
        }

        members++;
      }
    }

    max = std::max(members, max);
  next:;
  }

  std::cout << max << std::endl;
exit:
  return 0;
}