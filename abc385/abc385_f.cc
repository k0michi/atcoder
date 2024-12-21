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

f64 intercept(i64 xA, i64 yA, i64 xB, i64 yB) {
  return f64(xA * yB - xB * yA) / (xA - xB);
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> X(N), H(N);
  for (i64 i = 0; i < N; i++) {
    std::cin >> X[i] >> H[i];
  }

  f64 max = std::numeric_limits<f64>::lowest();
  for (i64 i = 1; i < N; i++) {
    max = std::max(max, intercept(X[i - 1], H[i - 1], X[i], H[i]));
  }

  if (max < 0) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << std::fixed << std::setprecision(10) << max << std::endl;
  }
exit:
  return 0;
}