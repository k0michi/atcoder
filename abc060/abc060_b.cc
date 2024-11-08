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
  std::unordered_set<i64> remainders;
  i64 A, B, C;
  std::cin >> A >> B >> C;
  i64 sum = 0;

  while (sum % B != C) {
    if (remainders.count(sum % B) > 0) {
      std::cout << "NO" << std::endl;
      goto exit;
    }

    remainders.insert(sum % B);
    sum += A;
  }

  std::cout << "YES" << std::endl;

exit:
  return 0;
}