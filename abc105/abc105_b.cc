#include <algorithm>
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

int main() {
  i32 N;
  std::cin >> N;
  bool can = false;

  for (i32 i = 0; i <= N; i += 4) {
    if ((N - i) % 7 == 0) {
      can = true;
    }
  }

  std::cout << (can ? "Yes" : "No") << std::endl;
  return 0;
}