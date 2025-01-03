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
  i64 N, K;
  std::cin >> N >> K;
  std::vector<std::pair<i64, i64>> medicines(N);
  i64 count = 0;

  for (i64 i = 0; i < N; i++) {
    std::cin >> medicines[i].first >> medicines[i].second;
    count += medicines[i].second;
  }

  std::sort(medicines.begin(), medicines.end());
  i64 first;

  if (count <= K) {
    first = 1;
  } else {
    for (i64 i = 0; i < N; i++) {
      count -= medicines[i].second;

      if (count <= K) {
        first = medicines[i].first + 1;
        break;
      }
    }
  }

  std::cout << first << std::endl;
exit:
  return 0;
}