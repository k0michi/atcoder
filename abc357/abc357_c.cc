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

i64 getCell(i64 level, i64 x, i64 y) {
  if (level == 0) {
    return 0;
  }

  i64 blockW = std::pow(3, level - 1);

  if (x >= blockW && x < blockW * 2 && y >= blockW && y < blockW * 2) {
    return 1;
  } else {
    return getCell(level - 1, x % blockW, y % blockW);
  }
}

int main() {
  i64 N;
  std::cin >> N;
  i64 w = std::pow(3, N);

  for (i64 y = 0; y < w; y++) {
    for (i64 x = 0; x < w; x++) {
      std::cout << (getCell(N, x, y) ? '.' : '#');
    }

    std::cout << std::endl;
  }
exit:
  return 0;
}