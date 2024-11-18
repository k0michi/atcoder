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
  std::vector<i64> q(N), r(N);
  for (i64 i = 0; i < N; i++) {
    std::cin >> q[i] >> r[i];
  }
  i64 Q;
  std::cin >> Q;
  for (i64 i = 0; i < Q; i++) {
    i64 t_i, d_i;
    std::cin >> t_i >> d_i;
    t_i--;
    std::cout << ((d_i + (q[t_i] - r[t_i] - 1)) / q[t_i] * q[t_i] + r[t_i])
              << std::endl;
  }
exit:
  return 0;
}