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

int main() {
  i64 N;
  std::string S;
  std::cin >> N >> S;

  i64 max = -1;
  i64 last = std::numeric_limits<i64>::max() / 2;

  for (i64 i = 0; i < N; i++) {
    if (S[i] == '-') {
      last = i;
    } else {
      max = std::max(max, i - last);
    }
  }

  last = std::numeric_limits<i64>::min() / 2;

  for (i64 i = N - 1; i >= 0; i--) {
    if (S[i] == '-') {
      last = i;
    } else {
      max = std::max(max, last - i);
    }
  }

  std::cout << max << std::endl;
exit:
  return 0;
}