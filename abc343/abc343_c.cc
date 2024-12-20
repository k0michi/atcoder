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

i64 reverseInteger(i64 n) {
  i64 reversed = 0;

  while (n > 0) {
    reversed *= 10;
    reversed += n % 10;
    n /= 10;
  }

  return reversed;
}

bool isPalindromic(i64 n) { return n == reverseInteger(n); }

i64 cube(i64 n) { return n * n * n; }

int main() {
  i64 N;
  std::cin >> N;
  i64 max = 0;

  for (i64 x = 1; cube(x) <= N; x++) {
    i64 y = cube(x);

    if (isPalindromic(y)) {
      max = y;
    }
  }

  std::cout << max << std::endl;
exit:
  return 0;
}