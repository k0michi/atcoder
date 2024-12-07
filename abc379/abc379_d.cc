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

int main() {
  i64 Q;
  std::cin >> Q;

  std::list<i64> pots;
  i64 time = 0;

  for (i64 i = 0; i < Q; i++) {
    i64 query_i;
    std::cin >> query_i;
    switch (query_i) {
    case 1:
      pots.push_back(time);
      break;
    case 2:
      i64 T;
      std::cin >> T;
      time += T;
      break;
    case 3:
      i64 H;
      std::cin >> H;
      i64 count = 0;

      while (!pots.empty() && time - pots.front() >= H) {
        pots.pop_front();
        count++;
      }

      std::cout << count << std::endl;
      break;
    }
  }

exit:
  return 0;
}