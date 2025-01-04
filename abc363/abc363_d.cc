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

  if (N == 1) {
    std::cout << 0 << std::endl;
  } else {
    i64 firstDigit = 1;

    while (N / (firstDigit * 11) > 0) {
      firstDigit *= 10;
    }

    N -= firstDigit;
    std::string s = std::to_string(N);
    std::cout << s;
    std::reverse(s.begin(), s.end());
    std::cout << s.substr(N / firstDigit > 0) << std::endl;
  }
exit:
  return 0;
}