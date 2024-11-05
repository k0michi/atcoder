#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <type_traits>
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

int main() {
  i32 N, A, B;
  std::cin >> N >> A >> B;

  i32 sumSum = 0;

  for (i32 i = 1; i <= N; i++) {
    i32 sum = 0;

    for (i32 j = i; j > 0; j /= 10) {
      sum += j % 10;
    }

    if (sum >= A && sum <= B) {
      sumSum += i;
    }
  }

  std::cout << sumSum << std::endl;
  return 0;
}