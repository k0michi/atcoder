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

bool compare(std::string s, std::string t) {
  if (s == t) {
    return true;
  }

  if (s.size() == t.size()) {
    i64 diff = 0;

    for (i64 i = 0; i < s.size(); i++) {
      diff += i64(s[i] != t[i]);
    }

    return diff == 1;
  } else {
    if (s.size() < t.size()) {
      std::swap(s, t);
    }

    i64 diffI = 0;

    while (s[diffI] == t[diffI]) {
      diffI++;
    }

    return s.substr(0, diffI) == t.substr(0, diffI) &&
           s.substr(diffI + 1) == t.substr(diffI);
  }
}

int main() {
  i64 K;
  std::string S, T;
  std::cin >> K >> S >> T;
  std::cout << (compare(S, T) ? "Yes" : "No") << std::endl;
exit:
  return 0;
}