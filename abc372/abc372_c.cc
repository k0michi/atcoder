#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
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

i64 checkABC(const std::string &s, i64 i) {
  return i < s.size() - 2 && s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C';
}

i64 isABC(char c) { return c >= 'A' && c <= 'C'; }

int main() {
  i64 N, Q;
  std::string S;
  std::cin >> N >> Q >> S;
  std::set<i64, std::greater<i64>> beginnings;

  for (i64 i = 0; i < S.size(); i++) {
    if (checkABC(S, i)) {
      beginnings.insert(i);
    }
  }

  for (i64 i = 0; i < Q; i++) {
    i64 X_i;
    char C_i;
    std::cin >> X_i >> C_i;
    X_i--;
    auto before = beginnings.lower_bound(X_i);

    if (before != beginnings.end() && X_i - *before <= 2) {
      beginnings.erase(before);
    }

    S[X_i] = C_i;
    i64 a = X_i - (C_i - 'A');
    if (isABC(C_i) && checkABC(S, a)) {
      beginnings.insert(a);
    }

    std::cout << beginnings.size() << std::endl;
  }
exit:
  return 0;
}