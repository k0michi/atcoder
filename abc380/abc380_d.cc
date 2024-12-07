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

std::string S;

char flip(char c) { return isupper(c) ? tolower(c) : toupper(c); }

i64 log2Int(i64 n) {
  i64 result = 0;

  while ((n >> 1) > 0) {
    n >>= 1;
    result++;
  }

  return result;
}

i64 pow2Int(i64 n) { return n == 0 ? 1 : pow2Int(n - 1) << 1; }

char get(i64 i) {
  if (i >= 0 && i < S.size()) {
    return S[i];
  }

  return flip(get(i - pow2Int(log2Int(i / S.size())) * S.size()));
}

int main() {
  i64 Q;
  std::cin >> S >> Q;
  std::vector<i64> K(Q);
  for (auto &&K_i : K) {
    std::cin >> K_i;
  }

  for (i64 i = 0; i < Q; i++) {
    if (i > 0) {
      std::cout << ' ';
    }

    std::cout << get(K[i] - 1);
  }

  std::cout << std::endl;
exit:
  return 0;
}