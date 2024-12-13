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

std::unordered_map<char, i64> letterMap = {
    {'M', 0}, {'A', 1}, {'R', 2}, {'C', 3}, {'H', 4},
};

int main() {
  i64 N;
  std::cin >> N;
  std::array<i64, 5> counts{};

  for (i64 i = 0; i < N; i++) {
    std::string S_i;
    std::cin >> S_i;
    if (letterMap.contains(S_i[0])) {
      counts[letterMap[S_i[0]]]++;
    }
  }

  i64 result = 0;

  for (i64 i = 0; i <= 0b11111; i++) {
    i64 count = std::bitset<5>(i).count();

    if (count == 3) {
      i64 choices = 1;

      for (i64 j = 0; j < 5; j++) {
        if ((i >> j) & 1) {
          choices *= counts[j];
        }
      }

      result += choices;
    }
  }

  std::cout << result << std::endl;
exit:
  return 0;
}