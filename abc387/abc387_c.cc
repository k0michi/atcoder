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

i64 powInt(i64 base, i64 exp) {
  if (exp == 0) {
    return 1;
  }

  i64 h = powInt(base, exp / 2);

  if (exp % 2 == 0) {
    return h * h;
  } else {
    return base * h * h;
  }
}

std::vector<i64> digits(i64 x, i64 base) {
  std::vector<i64> result;

  while (x > 0) {
    result.push_back(x % base);
    x /= base;
  }

  std::reverse(result.begin(), result.end());
  return result;
}

i64 countSnakesBeginWith(i64 head, i64 width) {
  return powInt(head, width - 1);
}

i64 countSnakes(i64 max) {
  auto d = digits(max, 10);
  auto w = d.size();
  i64 result = 1;

  for (i64 i = 1; i < w; i++) {
    result += std::min(d[0], d[i]) * countSnakesBeginWith(d[0], w - i);

    if (d[i] >= d[0]) {
      result--;
      break;
    }
  }

  for (i64 i = 1; i < d[0]; i++) {
    result += countSnakesBeginWith(i, w);
  }

  for (i64 i = 1; i < w; i++) {
    for (i64 j = 1; j <= 9; j++) {
      result += countSnakesBeginWith(j, i);
    }
  }

  return result;
}

int main() {
  i64 L, R;
  std::cin >> L >> R;
  std::cout << countSnakes(R) - countSnakes(L - 1) << std::endl;
exit:
  return 0;
}