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

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::vector<i64> shops(N);
  for (i64 i = 0; i < N; i++) {
    std::string S_i;
    std::cin >> S_i;
    i64 s = 0;

    for (i64 j = 0; j < M; j++) {
      s <<= 1;
      s |= i64(S_i[j] == 'o');
    }

    shops[i] = s;
  }

  i64 min = std::numeric_limits<i64>::max();

  for (i64 i = 0; i < (1 << N); i++) {
    i64 kinds = 0;

    for (i64 j = 0; j < N; j++) {
      if ((i >> j) & 1) {
        kinds |= shops[j];
      }
    }

    if (kinds == (1 << M) - 1) {
      min = std::min(min, i64(std::bitset<10>(i).count()));
    }
  }

  std::cout << min << std::endl;
exit:
  return 0;
}