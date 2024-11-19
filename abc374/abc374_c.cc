#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
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

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> K(N);

  for (auto &&K_i : K) {
    std::cin >> K_i;
  }

  i64 min = std::numeric_limits<i64>::max();

  for (i64 i = 0; i <= ((1 << N) - 1); i++) {
    i64 iCopy = i;
    i64 a = 0, b = 0;

    for (i64 j = 0; j < N; j++) {
      if (iCopy & 1) {
        a += K[j];
      } else {
        b += K[j];
      }

      iCopy >>= 1;
    }

    min = std::min(std::max(a, b), min);
  }

  std::cout << min << std::endl;
exit:
  return 0;
}