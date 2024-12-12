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

i64 binarySearch(i64 left, i64 right, std::function<bool(i64)> f) {
  while (left < right) {
    auto mid = (left + right + 1) / 2;

    if (f(mid)) {
      left = mid;
    } else {
      right = mid - 1;
    }
  }

  return left;
}

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::vector<i64> A(N);
  std::cin >> A;

  if (std::reduce(A.begin(), A.end()) <= M) {
    std::cout << "infinite" << std::endl;
  } else {
    i64 result = binarySearch(0, M, [&](auto &&max) {
      i64 cost = 0;

      for (auto &&A_i : A) {
        cost += std::min(max, A_i);
      }

      return cost <= M;
    });
    std::cout << result << std::endl;
  }
exit:
  return 0;
}