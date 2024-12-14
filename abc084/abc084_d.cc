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

std::vector<bool> eratosthenes(i64 n) {
  std::vector<bool> result(n + 1, true);
  result[0] = false;
  result[1] = false;
  for (i64 i = 2; i <= n; i++) {
    if (result[i]) {
      for (i64 j = i * 2; j <= n; j += i) {
        result[j] = false;
      }
    }
  }
  return result;
}

constexpr i64 kMax = 100000;

std::vector<bool> table = eratosthenes(kMax);

bool isPrime(i64 n) { return table[n]; }

bool isLike2017(i64 n) { return isPrime(n) && isPrime((n + 1) / 2); }

int main() {
  i64 Q;
  std::cin >> Q;

  std::vector<i64> cumulative(kMax + 1);
  for (i64 i = 1; i <= kMax; i++) {
    cumulative[i] = cumulative[i - 1] + i64(isLike2017(i - 1));
  }

  for (i64 i = 0; i < Q; i++) {
    i64 l_i, r_i;
    std::cin >> l_i >> r_i;
    i64 count = cumulative[r_i + 1] - cumulative[l_i];
    std::cout << count << std::endl;
  }
exit:
  return 0;
}