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

i64 upperAlphaToInt(char a) { return a - 'A'; }

constexpr i64 kNumAlphabets = 'Z' - 'A' + 1;

int main() {
  std::string S;
  std::cin >> S;

  std::vector<std::vector<i64>> cumulative(S.size(),
                                           std::vector<i64>(kNumAlphabets));

  for (i64 i = 0; i < S.size(); i++) {
    if (i - 1 >= 0) {
      cumulative[i] = cumulative[i - 1];
    }

    cumulative[i][upperAlphaToInt(S[i])]++;
  }

  i64 count = 0;

  for (i64 i = 1; i < S.size() - 1; i++) {
    for (i64 j = 0; j < kNumAlphabets; j++) {
      i64 left = cumulative[i - 1][j];
      i64 right = cumulative[S.size() - 1][j] - cumulative[i][j];
      count += left * right;
    }
  }

  std::cout << count << std::endl;
exit:
  return 0;
}