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
  std::set<i64> x, y;

  for (i64 i = 0; i < 8; i++) {
    std::string S_i;
    std::cin >> S_i;
    for (i64 j = 0; j < 8; j++) {
      if (S_i[j] == '#') {
        x.insert(j);
        y.insert(i);
      }
    }
  }

  i64 count = 0;
  for (i64 i = 0; i < 8; i++) {
    for (i64 j = 0; j < 8; j++) {
      if (!x.contains(j) && !y.contains(i)) {
        count++;
      }
    }
  }

  std::cout << count << std::endl;
exit:
  return 0;
}