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

bool isAC(const std::string &s, i64 i) {
  return s[i] == 'A' && s[i + 1] == 'C';
}

int main() {
  i64 N, Q;
  std::cin >> N >> Q;
  std::string S;
  std::cin >> S;

  std::vector<i64> cumulative(S.size());
  for (i64 i = 1; i < cumulative.size(); i++) {
    cumulative[i] = cumulative[i - 1] + i64(isAC(S, i - 1));
  }

  for (i64 i = 0; i < Q; i++) {
    i64 l_i, r_i;
    std::cin >> l_i >> r_i;
    i64 count = cumulative[r_i - 1] - cumulative[l_i - 1];
    std::cout << count << std::endl;
  }
exit:
  return 0;
}