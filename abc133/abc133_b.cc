#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
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

i64 pow2(i64 x) { return x * x; }

bool isPerfectSquare(i64 x) { return pow2(i64(std::sqrt(x))) == x; }

i64 distance(std::vector<i64> &a, std::vector<i64> &b) {
  i64 d = 0;

  for (i32 i = 0; i < a.size(); i++) {
    d += pow2(a[i] - b[i]);
  }

  return d;
}

int main() {
  i32 N, D;
  std::cin >> N >> D;
  std::vector<std::vector<i64>> X(N, std::vector<i64>(D));

  for (i32 i = 0; i < N; i++) {
    for (i32 j = 0; j < D; j++) {
      std::cin >> X[i][j];
    }
  }

  i32 pairs = 0;

  for (i32 i = 0; i < N; i++) {
    for (i32 j = i + 1; j < N; j++) {
      if (isPerfectSquare(distance(X[i], X[j]))) {
        pairs++;
      }
    }
  }

  std::cout << pairs << std::endl;
  return 0;
}