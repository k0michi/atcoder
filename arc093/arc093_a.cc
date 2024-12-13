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

i64 N;
std::vector<i64> A(N);

i64 getLocation(i64 i) { return i == -1 || i == N ? 0 : A[i]; }

int main() {
  std::cin >> N;
  A.resize(N);
  std::cin >> A;

  i64 totalCost = 0;

  for (i64 i = 0; i <= N; i++) {
    totalCost += std::abs(getLocation(i) - getLocation(i - 1));
  }

  for (i64 i = 0; i < N; i++) {
    i64 cost = totalCost;
    cost -= std::abs(getLocation(i) - getLocation(i - 1));
    cost -= std::abs(getLocation(i + 1) - getLocation(i));
    cost += std::abs(getLocation(i + 1) - getLocation(i - 1));
    std::cout << cost << std::endl;
  }
exit:
  return 0;
}