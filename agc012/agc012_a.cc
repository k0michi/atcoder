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
  i64 N;
  std::cin >> N;

  std::vector<i64> a(3 * N);

  for (auto &&a_i : a) {
    std::cin >> a_i;
  }

  std::sort(a.begin(), a.end());

  i64 total = 0;

  for (i64 i = 0; i < N; i++) {
    total += a[a.size() - 1 - (1 + 2 * i)];
  }

  std::cout << total << std::endl;
  return 0;
}