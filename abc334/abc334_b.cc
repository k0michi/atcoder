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
#include <tuple>
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

i64 floorDiv(i64 x, i64 y) {
  i64 q = x / y;

  if ((x ^ y) < 0 && q * y != x) {
    q--;
  }

  return q;
}

int main() {
  i64 A, M, L, R;
  std::cin >> A >> M >> L >> R;
  L -= A;
  R -= A;
  std::cout << floorDiv(R, M) - floorDiv(L - 1, M) << std::endl;
exit:
  return 0;
}