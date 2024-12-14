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

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::vector<i64> L(N), R(N);
  std::vector<i64> lMin(M + 1, -1);
  for (i64 i = 0; i < N; i++) {
    std::cin >> L[i] >> R[i];
    lMin[R[i]] = std::max(lMin[R[i]], L[i] + 1);
  }

  i64 lastLMin = 1;
  i64 count = 0;

  for (i64 r = 1; r <= M; r++) {
    lastLMin = std::max(lastLMin, lMin[r]);
    count += r - lastLMin + 1;
  }

  std::cout << count << std::endl;
exit:
  return 0;
}