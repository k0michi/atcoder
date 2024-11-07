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
  std::string S;
  std::cin >> S;

  std::array<bool, 'z' - 'a' + 1> chars{};

  for (auto &&S_i : S) {
    chars[S_i - 'a'] = true;
  }

  bool none = true;

  for (i64 i = 0; i < chars.size(); i++) {
    if (!chars[i]) {
      std::cout << char('a' + i) << std::endl;
      none = false;
      break;
    }
  }

  if (none) {
    std::cout << "None" << std::endl;
  }
  return 0;
}