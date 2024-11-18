#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
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
  i64 N;
  std::cin >> N;
  std::multiset<i64, std::greater<i64>> toys;

  for (i64 i = 0; i < N; i++) {
    i64 A_i;
    std::cin >> A_i;
    toys.insert(A_i);
  }

  for (i64 i = 0; i < N - 1; i++) {
    i64 B_i;
    std::cin >> B_i;
    auto it = toys.lower_bound(B_i);

    if (it == toys.end()) {
      std::cout << -1 << std::endl;
      goto exit;
    }

    toys.erase(it);
  }

  std::cout << (*toys.begin()) << std::endl;
exit:
  return 0;
}