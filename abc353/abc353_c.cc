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
std::istream &operator>>(std::istream &s, std::vector<T> &v) {
  for (auto &&v_i : v) {
    s >> v_i;
  }
  return s;
}

constexpr i64 kBase = 100000000;

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> A(N);
  std::cin >> A;
  std::vector<i64> cumulative(kBase + 1);
  i64 sum = 0;

  for (i64 i = 0; i < N; i++) {
    cumulative[A[i] + 1]++;
    sum += A[i];
  }

  for (i64 i = 1; i < cumulative.size(); i++) {
    cumulative[i] += cumulative[i - 1];
  }

  i64 count = 0;

  for (i64 i = 0; i < N; i++) {
    count +=
        cumulative[kBase] - cumulative[kBase - A[i]] - i64(2 * A[i] >= kBase);
  }

  i64 result = (N - 1) * sum;
  result -= count / 2 * kBase;
  std::cout << result << std::endl;
exit:
  return 0;
}