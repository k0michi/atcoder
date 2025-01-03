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
  std::cin >> N;
  std::vector<std::tuple<i64, i64, i64>> people(N);

  for (i64 i = 0; i < N; i++) {
    std::cin >> std::get<0>(people[i]) >> std::get<1>(people[i]);
    std::get<2>(people[i]) = i + 1;
  }

  std::sort(people.begin(), people.end(), [](auto &&a, auto &&b) {
    return std::make_tuple(std::get<0>(b) * (std::get<0>(a) + std::get<1>(a)),
                           std::get<2>(a)) <
           std::make_tuple(std::get<0>(a) * (std::get<0>(b) + std::get<1>(b)),
                           std::get<2>(b));
  });

  for (i64 i = 0; i < N; i++) {
    if (i > 0) {
      std::cout << ' ';
    }

    std::cout << std::get<2>(people[i]);
  }

  std::cout << std::endl;
exit:
  return 0;
}