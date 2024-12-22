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

int main() {
  i64 N, A, B;
  std::cin >> N >> A >> B;
  std::vector<i64> D(N);
  std::cin >> D;

  std::set<i64> schedule;

  for (i64 i = 0; i < N; i++) {
    schedule.insert(D[i] % (A + B));
  }

  i64 max = 0;
  i64 last = *schedule.rbegin() - (A + B);
  for (auto it = schedule.begin(); it != schedule.end(); it++) {
    max = std::max(max, *it - last - 1);
    last = *it;
  }

  std::cout << (B <= max ? "Yes" : "No") << std::endl;
exit:
  return 0;
}