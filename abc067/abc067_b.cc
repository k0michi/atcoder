#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_set>
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
  i32 N, K;
  std::cin >> N >> K;
  std::vector<i32> l(N);

  for (auto &&l_i : l) {
    std::cin >> l_i;
  }

  std::sort(l.begin(), l.end(), std::greater{});

  i32 max = 0;

  for (usize i = 0; i < K; i++) {
    max += l[i];
  }

  std::cout << max << std::endl;
  return 0;
}