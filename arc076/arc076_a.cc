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

constexpr i64 kBase = 1000000007;

i64 factorial(i64 x) {
  if (x == 0) {
    return 1;
  } else {
    return x * factorial(x - 1) % kBase;
  }
}

int main() {
  i64 N, M;
  std::cin >> N >> M;
  i64 result = factorial(N) * factorial(M);
  result %= kBase;

  if (N == M) {
    result *= 2;
    result %= kBase;
  } else if (N == M - 1 || N == M + 1) {
  } else {
    result = 0;
  }

  std::cout << result << std::endl;
exit:
  return 0;
}