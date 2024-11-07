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

int main() {
  i64 A, B, C, X, Y;
  std::cin >> A >> B >> C >> X >> Y;

  i64 ab = 0;

  if (C * 2 < A && C * 2 < B) {
    auto max = std::max(X, Y);
    ab += max * 2;
    X -= max;
    Y -= max;
  }

  if (C * 2 < A + B) {
    auto min = std::min(X, Y);
    ab += min * 2;
    X -= min;
    Y -= min;
  }

  if (C * 2 < A) {
    ab += X * 2;
    Y -= X;
    X = 0;
  }

  if (C * 2 < B) {
    ab += Y * 2;
    X -= Y;
    Y = 0;
  }

  i64 a = std::max(X, i64(0));
  i64 b = std::max(Y, i64(0));

  std::cout << (a * A + b * B + ab * C) << std::endl;
  return 0;
}