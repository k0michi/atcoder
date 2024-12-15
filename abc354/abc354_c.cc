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
std::ostream &operator<<(std::ostream &s, const std::vector<T> &v) {
  i64 i = 0;

  for (auto &&v_i : v) {
    if (i > 0) {
      s << ' ';
    }

    s << v_i;
    i++;
  }

  return s;
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<std::tuple<i64, i64, i64>> cards(N);
  for (i64 i = 0; i < N; i++) {
    std::cin >> std::get<0>(cards[i]) >> std::get<1>(cards[i]);
    std::get<2>(cards[i]) = i + 1;
  }

  std::sort(cards.begin(), cards.end());

  i64 costMin = std::numeric_limits<i64>::max();
  std::vector<i64> remaining;

  for (i64 i = N - 1; i >= 0; i--) {
    i64 cost = std::get<1>(cards[i]);
    costMin = std::min(costMin, cost);

    if (cost <= costMin) {
      remaining.push_back(std::get<2>(cards[i]));
    }
  }

  std::sort(remaining.begin(), remaining.end());
  std::cout << remaining.size() << std::endl;
  std::cout << remaining << std::endl;
exit:
  return 0;
}