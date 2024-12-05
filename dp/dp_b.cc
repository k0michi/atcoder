#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
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

int main() {
  i64 N, K;
  std::cin >> N >> K;
  std::vector<i64> h(N);

  for (auto &&h_i : h) {
    std::cin >> h_i;
  }

  std::vector<i64> memo(N, std::numeric_limits<i64>::max());
  memo[0] = 0;

  for (i64 i = 1; i < N; i++) {
    for (i64 j = std::max(i - K, i64(0)); j < i; j++) {
      memo[i] = std::min(memo[i], memo[j] + std::abs(h[i] - h[j]));
    }
  }

  std::cout << memo[N - 1] << std::endl;

exit:
  return 0;
}