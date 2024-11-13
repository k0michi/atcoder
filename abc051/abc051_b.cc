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
  i64 K, S;
  std::cin >> K >> S;
  i64 count = 0;

  for (i64 x = 0; x <= K; x++) {
    for (i64 y = 0; y <= K; y++) {
      i64 z = S - x - y;
      if (0 <= z && z <= K) {
        count++;
      }
    }
  }

  std::cout << count << std::endl;
exit:
  return 0;
}