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

int main() {
  i64 N, S;
  std::cin >> N >> S;
  std::vector<i64> A(N);
  for (auto &&A_i : A) {
    std::cin >> A_i;
  }

  std::vector<i64> cumulative(2 * N);
  std::unordered_set<i64> cumulativeSet;
  cumulativeSet.insert(0);

  for (i64 i = 1; i < cumulative.size(); i++) {
    cumulative[i] = cumulative[i - 1] + A[(i - 1) % N];
    cumulativeSet.insert(cumulative[i]);
  }

  S %= cumulative[N];
  bool can = false;

  for (i64 i = 0; i < N; i++) {
    can = can || cumulativeSet.contains(cumulative[i] + S);
  }

  std::cout << (can ? "Yes" : "No") << std::endl;
exit:
  return 0;
}