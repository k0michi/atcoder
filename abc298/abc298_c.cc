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

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::set<T> &set) {
  i64 i = 0;

  for (auto &&set_i : set) {
    if (i > 0) {
      s << ' ';
    }

    s << set_i;
    i++;
  }

  return s;
}

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::multiset<T> &set) {
  i64 i = 0;

  for (auto &&set_i : set) {
    if (i > 0) {
      s << ' ';
    }

    s << set_i;
    i++;
  }

  return s;
}

int main() {
  i64 N, Q;
  std::cin >> N >> Q;
  std::unordered_map<i64, std::set<i64>> boxes;
  std::unordered_map<i64, std::multiset<i64>> cards;

  for (i64 k = 0; k < Q; k++) {
    i64 op, i;
    std::cin >> op >> i;

    switch (op) {
    case 1:
      i64 j;
      std::cin >> j;
      boxes[i].insert(j);
      cards[j].insert(i);
      break;
    case 2:
      std::cout << cards[i] << std::endl;
      break;
    case 3:
      std::cout << boxes[i] << std::endl;
      break;
    }
  }
exit:
  return 0;
}