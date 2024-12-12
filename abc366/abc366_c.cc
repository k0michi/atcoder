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
  std::unordered_map<i64, i64> bag;
  i64 kinds = 0;

  for (i64 i = 0; i < Q; i++) {
    i64 q;
    std::cin >> q;

    switch (q) {
    case 1: {
      i64 x;
      std::cin >> x;
      if (bag[x] == 0) {
        kinds++;
      }
      bag[x]++;
      break;
    }
    case 2: {
      i64 x;
      std::cin >> x;
      bag[x]--;
      if (bag[x] == 0) {
        kinds--;
      }
      break;
    }
    case 3: {
      std::cout << kinds << std::endl;
      break;
    }
    }
  }
exit:
  return 0;
}