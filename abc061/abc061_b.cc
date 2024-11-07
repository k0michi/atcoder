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
  i64 N, M;
  std::cin >> N >> M;
  std::vector<i64> roads(N);

  for (i64 i = 0; i < M; i++) {
    i64 a_i, b_i;
    std::cin >> a_i >> b_i;
    roads[a_i - 1]++;
    roads[b_i - 1]++;
  }

  for (i64 i = 0; i < N; i++) {
    std::cout << roads[i] << std::endl;
  }
  return 0;
}