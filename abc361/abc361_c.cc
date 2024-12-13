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

int main() {
  i64 N, K;
  std::cin >> N >> K;
  std::vector<i64> A(N);
  std::cin >> A;
  std::sort(A.begin(), A.end());

  i64 min = std::numeric_limits<i64>::max();

  for (i64 i = 0; i <= K; i++) {
    min = std::min(min, A[i + (A.size() - K - 1)] - A[i]);
  }

  std::cout << min << std::endl;
exit:
  return 0;
}