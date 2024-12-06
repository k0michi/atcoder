#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
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

std::pair<usize, usize> twoMax(const std::vector<i64> &v) {
  i64 max1 = std::numeric_limits<i64>::min(),
      max2 = std::numeric_limits<i64>::min();
  usize max1I, max2I;

  for (usize i = 0; i < v.size(); i++) {
    if (v[i] > max2) {
      if (v[i] > max1) {
        max2 = max1;
        max2I = max1I;
        max1 = v[i];
        max1I = i;
      } else {
        max2 = v[i];
        max2I = i;
      }
    }
  }

  return {max1I, max2I};
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> A(N);
  for (auto &&A_i : A) {
    std::cin >> A_i;
  }

  i64 ops = 0;

  while (true) {
    auto two = twoMax(A);

    if (A[two.second] <= 0) {
      break;
    }

    A[two.first]--;
    A[two.second]--;
    ops++;
  }

  std::cout << ops << std::endl;
exit:
  return 0;
}