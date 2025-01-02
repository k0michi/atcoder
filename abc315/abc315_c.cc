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
  std::vector<std::multiset<i64>> tastes(N + 1);

  for (i64 i = 0; i < N; i++) {
    i64 F_i, S_i;
    std::cin >> F_i >> S_i;
    tastes[F_i].insert(S_i);
  }

  tastes.erase(std::remove_if(tastes.begin(), tastes.end(),
                              [](auto &&t) { return t.size() == 0; }),
               tastes.end());
  std::sort(tastes.begin(), tastes.end(),
            [](auto &&a, auto &&b) { return *a.rbegin() > *b.rbegin(); });

  i64 max = 0;

  if (tastes[0].size() >= 2) {
    max = std::max(max, *tastes[0].rbegin() + *(++tastes[0].rbegin()) / 2);
  }

  if (tastes.size() >= 2) {
    max = std::max(max, *tastes[0].rbegin() + *tastes[1].rbegin());
  }

  std::cout << max << std::endl;
exit:
  return 0;
}