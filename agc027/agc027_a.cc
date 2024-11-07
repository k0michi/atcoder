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
  i64 N, x;
  std::cin >> N >> x;
  std::vector<i64> a(N);

  for (auto &&a_i : a) {
    std::cin >> a_i;
  }

  std::sort(a.begin(), a.end());

  i64 count = 0;

  for (i64 i = 0; i < N; i++) {
    x -= a[i];

    if (i == N - 1) {
      if (x == 0) {
        count++;
      }
    } else {
      if (x >= 0) {
        count++;
      }
    }
  }

  std::cout << count << std::endl;
  return 0;
}