#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
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

int main() {
  i32 N;
  std::cin >> N;
  std::unordered_set<i32> mochis;

  for (usize i = 0; i < N; i++) {
    i32 mochi;
    std::cin >> mochi;
    mochis.insert(mochi);
  }

  std::cout << mochis.size() << std::endl;
  return 0;
}