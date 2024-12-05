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
  i64 N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  std::list<i64> ones;
  char last = 0;
  i64 max = 1;

  for (i64 i = 0; i < N; i++) {
    if (S[i] == '1') {
      if (last != '1') {
        ones.clear();
      }

      ones.push_back(i);
    } else if (S[i] == '2') {
      if (last != '/' && last != '2') {
        ones.clear();
      }

      if (ones.size() > 0) {
        i64 prev = ones.back();
        ones.pop_back();
        max = std::max(max, i - prev + 1);
      }
    } else if (S[i] == '/') {
      if (last != '1') {
        ones.clear();
      }
    }

    last = S[i];
  }

  std::cout << max << std::endl;
exit:
  return 0;
}