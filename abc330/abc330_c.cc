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

i64 minimize(i64 D, i64 x) {
  i64 yFloored = std::floor(std::sqrt(D - x * x));
  i64 yCeiled = std::ceil(std::sqrt(D - x * x));
  return std::min(std::abs(x * x + yFloored * yFloored - D),
                  std::abs(x * x + yCeiled * yCeiled - D));
}

int main() {
  i64 D;
  std::cin >> D;

  i64 min = std::numeric_limits<i64>::max();
  for (i64 x = 0; x <= std::sqrt(D); x++) {
    min = std::min(min, minimize(D, x));
  }
  std::cout << min << std::endl;
exit:
  return 0;
}