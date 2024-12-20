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

i64 digitSum(i64 n, i64 base) {
  i64 sum = 0;

  while (n > 0) {
    sum += n % base;
    n /= base;
  }

  return sum;
}

i64 repunitTrio(i64 n) {
  i64 i = 1;
  i64 sum = 0;

  while (n > 0) {
    sum += (n % 4) * i;
    n /= 4;
    i = i * 10 + 1;
  }

  return sum;
}

int main() {
  i64 N;
  std::cin >> N;

  for (i64 i = 1;; i++) {
    if (digitSum(i, 4) == 3) {
      N--;

      if (N == 0) {
        std::cout << repunitTrio(i) << std::endl;
        break;
      }
    }
  }
exit:
  return 0;
}