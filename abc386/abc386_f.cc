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

constexpr i64 kInsertDeleteCost = 1;
constexpr i64 kReplaceCost = 1;
constexpr i64 kInf = std::numeric_limits<i64>::max() / 2;

i64 levenshtein(const std::string &s1, const std::string &s2, i64 K) {
  std::vector<std::vector<i64>> memo(2, std::vector<i64>(s2.size() + 1, kInf));

  for (i64 i = 0; i <= s2.size(); i++) {
    memo[0][i] = kInsertDeleteCost * i;
  }

  for (i64 i = 1; i <= s1.size(); i++) {
    for (i64 j = std::max(i64(1), i - 2 - K);
         j <= std::min(i64(s2.size()), i - 2 + K); j++) {
      memo[i % 2][j] = kInf;
    }

    memo[i % 2][0] = kInsertDeleteCost * i;

    for (i64 j = std::max(i64(1), i - K); j <= std::min(i64(s2.size()), i + K);
         j++) {
      memo[i % 2][j] = std::min({memo[(i - 1) % 2][j - 1] +
                                     i64(s1[i - 1] != s2[j - 1]) * kReplaceCost,
                                 memo[(i - 1) % 2][j] + kInsertDeleteCost,
                                 memo[i % 2][j - 1] + kInsertDeleteCost});
    }
  }

  return memo[s1.size() % 2][s2.size()];
}

int main() {
  i64 K;
  std::string S, T;
  std::cin >> K >> S >> T;
  bool result = levenshtein(S, T, K) <= K;
  std::cout << (result ? "Yes" : "No") << std::endl;
exit:
  return 0;
}