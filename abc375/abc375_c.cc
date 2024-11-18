#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
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

i64 N;

i64 distanceFromCenter(i64 x, i64 y) {
  return std::min({std::max(std::abs(N / 2 - x), std::abs(N / 2 - y)),
                   std::max(std::abs(N / 2 - 1 - x), std::abs(N / 2 - y)),
                   std::max(std::abs(N / 2 - x), std::abs(N / 2 - 1 - y)),
                   std::max(std::abs(N / 2 - 1 - x), std::abs(N / 2 - 1 - y))});
}

int main() {
  std::cin >> N;
  std::vector<std::vector<char>> A(N, std::vector<char>(N));

  for (i64 i = 0; i < N; i++) {
    for (i64 j = 0; j < N; j++) {
      std::cin >> A[i][j];
    }
  }

  for (i64 y = 0; y < N; y++) {
    for (i64 x = 0; x < N; x++) {
      i64 rotates = (N / 2 - distanceFromCenter(x, y)) % 4;

      switch (rotates) {
      case 0:
        std::cout << A[y][x];
        break;
      case 1:
        std::cout << A[N - x - 1][y];
        break;
      case 2:
        std::cout << A[N - y - 1][N - x - 1];
        break;
      case 3:
        std::cout << A[x][N - y - 1];
        break;
      }
    }

    std::cout << std::endl;
  }
exit:
  return 0;
}