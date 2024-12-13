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

struct Range;
Range operator+(const Range &a, const Range &b);

struct Range {
  i64 left, right;

  bool has(i64 x) { return x >= left && x <= right; }

  Range &operator+=(const Range &b) {
    (*this) = (*this) + b;
    return *this;
  }
};

Range operator+(const Range &a, const Range &b) {
  return {a.left + b.left, a.right + b.right};
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<Range> ranges(N);
  for (auto &&r : ranges) {
    std::cin >> r.left >> r.right;
  }

  std::vector<Range> accRanges(N);
  accRanges.back() = ranges.back();
  for (i64 i = N - 2; i >= 0; i--) {
    accRanges[i] = ranges[i] + accRanges[i + 1];
  }

  if (accRanges.front().has(0)) {
    std::cout << "Yes" << std::endl;

    i64 partialSum = 0;
    std::vector<i64> X;

    for (i64 i = 0; i < N - 1; i++) {
      auto j = std::max(ranges[i].left, partialSum - accRanges[i + 1].right);
      X.push_back(j);
      partialSum -= j;
    }

    X.push_back(partialSum);
    std::cout << X << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }

exit:
  return 0;
}