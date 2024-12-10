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
  i64 N, Q;
  std::cin >> N >> Q;
  std::vector<char> H(Q);
  std::vector<i64> T(Q);
  for (i64 i = 0; i < Q; i++) {
    std::cin >> H[i] >> T[i];
    T[i]--;
  }

  i64 l = 0, r = 1;
  i64 ops = 0;

  for (i64 i = 0; i < Q; i++) {
    if (H[i] == 'L') {
      i64 rNormalized = (r + (N - l)) % N;
      i64 tNormalized = (T[i] + (N - l)) % N;
      ops += tNormalized < rNormalized ? tNormalized : (N - tNormalized);
      l = T[i];
    } else {
      i64 lNormalized = (l + (N - r)) % N;
      i64 tNormalized = (T[i] + (N - r)) % N;
      ops += tNormalized < lNormalized ? tNormalized : (N - tNormalized);
      r = T[i];
    }
  }

  std::cout << ops << std::endl;
exit:
  return 0;
}