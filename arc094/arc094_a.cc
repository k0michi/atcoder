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

i64 isEven(i64 x) { return x % 2 == 0; }

i64 isOdd(i64 x) { return x % 2 == 1; }

i64 makeOdd(i64 x) { return x + (isEven(x)); }

i64 makeEven(i64 x) { return x + (isOdd(x)); }

int main() {
  i64 A, B, C;
  std::cin >> A >> B >> C;
  i64 odds = isOdd(A) + isOdd(B) + isOdd(C);
  i64 steps = 0;

  if (odds == 1) {
    A = makeOdd(A);
    B = makeOdd(B);
    C = makeOdd(C);
    steps++;
  } else if (odds == 2) {
    A = makeEven(A);
    B = makeEven(B);
    C = makeEven(C);
    steps++;
  }

  i64 max = std::max({A, B, C});
  steps += (max - A) / 2;
  steps += (max - B) / 2;
  steps += (max - C) / 2;

  std::cout << steps << std::endl;
  return 0;
}