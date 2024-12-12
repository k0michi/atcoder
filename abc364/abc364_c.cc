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

i64 attempt(std::vector<std::pair<i64, i64>> &dishes, i64 x, i64 y) {
  i64 count = 0;

  while (x >= 0 && y >= 0 && count < dishes.size()) {
    x -= dishes[count].first;
    y -= dishes[count].second;
    count++;
  }

  return count;
}

int main() {
  i64 N, X, Y;
  std::cin >> N >> X >> Y;
  std::vector<std::pair<i64, i64>> dishes(N);

  for (auto i = 0; i < N; i++) {
    std::cin >> dishes[i].first;
  }

  for (auto i = 0; i < N; i++) {
    std::cin >> dishes[i].second;
  }

  std::sort(dishes.begin(), dishes.end(),
            [](auto &&a, auto &&b) { return a.first > b.first; });
  i64 score = attempt(dishes, X, Y);
  std::sort(dishes.begin(), dishes.end(),
            [](auto &&a, auto &&b) { return a.second > b.second; });
  score = std::min(score, attempt(dishes, X, Y));
  std::cout << score << std::endl;
exit:
  return 0;
}