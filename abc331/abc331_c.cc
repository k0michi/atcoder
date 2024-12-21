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

int main() {
  i64 N;
  std::cin >> N;
  std::vector<std::tuple<i64, i64, i64>> a(N);

  for (i64 i = 0; i < N; i++) {
    std::cin >> std::get<0>(a[i]);
    std::get<1>(a[i]) = i;
  }

  std::sort(a.begin(), a.end());
  i64 cumulative = 0;
  i64 temp = 0;

  for (i64 i = N - 2; i >= 0; i--) {
    if (std::get<0>(a[i]) == std::get<0>(a[i + 1])) {
      temp += std::get<0>(a[i + 1]);
    } else {
      cumulative += temp + std::get<0>(a[i + 1]);
      temp = 0;
    }

    std::get<2>(a[i]) = cumulative;
  }

  std::sort(a.begin(), a.end(),
            [](auto &&a, auto &&b) { return std::get<1>(a) < std::get<1>(b); });

  for (i64 i = 0; i < N; i++) {
    if (i > 0) {
      std::cout << ' ';
    }

    std::cout << std::get<2>(a[i]);
  }

  std::cout << std::endl;
exit:
  return 0;
}