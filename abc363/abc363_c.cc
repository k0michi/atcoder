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

bool hasPalindrome(const std::string &s, i64 k) {
  i64 n = s.size();

  for (i64 i = 0; i <= n - k; i++) {
    for (i64 j = 0; j < k; j++) {
      if (s[i + j] != s[i + k - 1 - j]) {
        goto next;
      }
    }

    return true;
  next:;
  }

  return false;
}

int main() {
  i64 N, K;
  std::cin >> N >> K;
  std::string S;
  std::cin >> S;
  std::sort(S.begin(), S.end());
  i64 result = 0;

  do {
    result += i64(!hasPalindrome(S, K));
  } while (std::next_permutation(S.begin(), S.end()));

  std::cout << result << std::endl;
exit:
  return 0;
}