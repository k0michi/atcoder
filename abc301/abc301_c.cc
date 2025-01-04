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

const std::unordered_set<char> kCards{'a', 't', 'c', 'o', 'd', 'e', 'r'};

int main() {
  std::string S, T;
  std::cin >> S >> T;
  std::unordered_map<char, i64> SCounts, TCounts;
  std::unordered_set<char> letters;

  for (auto &&S_i : S) {
    SCounts[S_i]++;
    letters.insert(S_i);
  }

  for (auto &&T_i : T) {
    TCounts[T_i]++;
    letters.insert(T_i);
  }

  i64 diffTotal = 0;
  bool can = true;

  for (auto &&l : letters) {
    if (l != '@') {
      i64 diff = std::abs(SCounts[l] - TCounts[l]);

      if (diff > 0 && !kCards.contains(l)) {
        can = false;
      }

      diffTotal += diff;
    }
  }

  if (diffTotal > SCounts['@'] + TCounts['@']) {
    can = false;
  }

  std::cout << (can ? "Yes" : "No") << std::endl;
exit:
  return 0;
}