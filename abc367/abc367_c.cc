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

template <typename T>
std::istream &operator>>(std::istream &s, std::vector<T> &v) {
  for (auto &&v_i : v) {
    s >> v_i;
  }
  return s;
}

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::list<T> &l) {
  i64 i = 0;

  for (auto &&l_i : l) {
    if (i > 0) {
      s << ' ';
    }

    s << l_i;
    i++;
  }

  return s;
}

i64 N, K;
std::vector<i64> R;

void rec(std::list<i64> s, i64 sum) {
  if (s.size() == N) {
    if (sum % K == 0) {
      std::cout << s << std::endl;
    }
    return;
  }

  for (i64 i = 1; i <= R[s.size()]; i++) {
    auto sNext = s;
    sNext.push_back(i);
    rec(sNext, sum + i);
  }
}

int main() {
  std::cin >> N >> K;
  R.resize(N);
  std::cin >> R;
  rec({}, 0);
exit:
  return 0;
}