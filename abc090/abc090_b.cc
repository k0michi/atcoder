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

bool isPalindromicNumber(i32 x) {
  auto str = std::to_string(x);
  std::reverse(str.begin(), std::next(str.begin(), str.size() / 2));
  return str.substr(0, str.size() / 2) ==
         str.substr(str.size() - str.size() / 2);
}

int main() {
  i32 A, B;
  std::cin >> A >> B;
  i32 count = 0;

  for (i32 i = A; i <= B; i++) {
    if (isPalindromicNumber(i)) {
      count++;
    }
  }

  std::cout << count << std::endl;
  return 0;
}