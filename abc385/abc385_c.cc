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

template <typename T>
std::istream &operator>>(std::istream &s, std::vector<T> &v) {
  for (auto &&v_i : v) {
    s >> v_i;
  }
  return s;
}

i64 N;
std::vector<i64> H(N);

i64 test(i64 begin, i64 step) {
  i64 h = H[begin];
  i64 count = 1;

  for (i64 i = begin + step; i < N; i += step) {
    if (H[i] != h) {
      break;
    }

    count++;
  }

  return count;
}

int main() {
  std::cin >> N;
  H.resize(N);
  std::cin >> H;
  i64 max = 0;

  for (i64 i = 0; i < N; i++) {
    for (i64 j = 1; j <= N; j++) {
      max = std::max(max, test(i, j));
    }
  }

  std::cout << max << std::endl;
exit:
  return 0;
}