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

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &v) {
  i64 i = 0;

  for (auto &&v_i : v) {
    if (i > 0) {
      s << ' ';
    }

    s << v_i;
    i++;
  }

  return s;
}

i64 differentElement(const std::string &s, const std::string &t) {
  i64 i = 0;

  for (; i < std::min(s.size(), t.size()); i++) {
    if (s[i] != t[i]) {
      return i;
    }
  }

  return i;
}

i64 compare(const std::string &s, const std::string &t) {
  if (s == t) {
    return true;
  } else if (t.size() == s.size()) {
    i64 i = differentElement(s, t);
    return s.substr(0, i) == t.substr(0, i) &&
           s.substr(i + 1) == t.substr(i + 1);
  } else if (t.size() == s.size() - 1) {
    i64 i = differentElement(s, t);
    return s.substr(0, i) == t.substr(0, i) && s.substr(i + 1) == t.substr(i);
  } else if (t.size() == s.size() + 1) {
    i64 i = differentElement(s, t);
    return s.substr(0, i) == t.substr(0, i) && s.substr(i) == t.substr(i + 1);
  }

  return false;
}

int main() {
  i64 N;
  std::string TPrime;
  std::cin >> N >> TPrime;
  std::vector<i64> results;

  for (i64 i = 0; i < N; i++) {
    std::string S_i;
    std::cin >> S_i;

    if (compare(TPrime, S_i)) {
      results.push_back(i + 1);
    }
  }

  std::cout << results.size() << std::endl;
  std::cout << results << std::endl;
exit:
  return 0;
}