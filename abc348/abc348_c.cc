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
  std::unordered_map<i64, i64> mins;

  for (i64 i = 0; i < N; i++) {
    i64 A_i, C_i;
    std::cin >> A_i >> C_i;

    if (mins.count(C_i) == 0) {
      mins[C_i] = A_i;
    } else {
      mins[C_i] = std::min(mins[C_i], A_i);
    }
  }

  i64 max = 0;
  for (auto &&[k, v] : mins) {
    max = std::max(max, v);
  }

  std::cout << max << std::endl;
exit:
  return 0;
}