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
  i64 N, R;
  std::cin >> N >> R;
  std::vector<i64> D(N), A(N);
  for (i64 i = 0; i < N; i++) {
    std::cin >> D[i] >> A[i];
  }

  i64 rate = R;

  for (i64 i = 0; i < N; i++) {
    if ((D[i] == 1 && rate >= 1600 && rate <= 2799) ||
        (D[i] == 2 && rate >= 1200 && rate <= 2399)) {
      rate += A[i];
    }
  }

  std::cout << rate << std::endl;
exit:
  return 0;
}