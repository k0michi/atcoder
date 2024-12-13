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

constexpr i64 kInf = std::numeric_limits<i64>::max() / 2;

int main() {
  i64 N;
  i64 NG_1, NG_2, NG_3;
  std::cin >> N >> NG_1 >> NG_2 >> NG_3;
  bool can;

  if (N <= 300) {
    std::array<i64, 301> memo{};
    memo.fill(kInf);
    memo[0] = 0;

    for (i64 i = 1; i <= 300; i++) {
      if (NG_1 == i || NG_2 == i || NG_3 == i) {
        continue;
      }

      memo[i] = std::min(memo[i], memo[i - 1] + 1);

      if (i - 2 >= 0) {
        memo[i] = std::min(memo[i], memo[i - 2] + 1);
      }

      if (i - 3 >= 0) {
        memo[i] = std::min(memo[i], memo[i - 3] + 1);
      }
    }

    can = memo[N] <= 100;
  } else {
    can = false;
  }

  std::cout << (can ? "YES" : "NO") << std::endl;
exit:
  return 0;
}