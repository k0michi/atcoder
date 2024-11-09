#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
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

int main() {
  i64 N;
  std::cin >> N;
  std::vector<std::vector<i64>> A(2, std::vector<i64>(N));
  i64 row2Total = 0;

  for (i64 i = 0; i < 2; i++) {
    for (i64 j = 0; j < N; j++) {
      std::cin >> A[i][j];

      if (i == 1) {
        row2Total += A[i][j];
      }
    }
  }

  i64 row1Total = 0;
  i64 max = 0;

  for (i64 i = 0; i < N; i++) {
    row1Total += A[0][i];
    max = std::max(row1Total + row2Total, max);
    row2Total -= A[1][i];
  }

  std::cout << max << std::endl;
exit:
  return 0;
}