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
  std::string S;
  i64 Q;
  std::cin >> N >> S >> Q;
  std::unordered_map<char, char> replaces;

  for (char i = 'a'; i <= 'z'; i++) {
    replaces[i] = i;
  }

  for (i64 i = 0; i < Q; i++) {
    char c_i, d_i;
    std::cin >> c_i >> d_i;

    for (auto &&[k, v] : replaces) {
      if (v == c_i) {
        v = d_i;
      }
    }
  }

  std::transform(S.begin(), S.end(), S.begin(),
                 [&](auto c) { return replaces[c]; });
  std::cout << S << std::endl;
exit:
  return 0;
}