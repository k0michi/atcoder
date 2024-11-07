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
#include <unordered_map>
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

i64 digits(i64 x) { return std::to_string(x).size(); }

i64 F(i64 A, i64 B) { return std::max(digits(A), digits(B)); }

int main() {
  i64 N;
  std::cin >> N;

  i64 min = std::numeric_limits<i64>::max();
  i64 sqrtN = i64(std::sqrt(N));

  for (i64 i = 1; i <= sqrtN; i++) {
    if (N % i == 0) {
      min = std::min(F(i, N / i), min);
    }
  }

  std::cout << min << std::endl;
  return 0;
}