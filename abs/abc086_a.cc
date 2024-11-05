#include <cstdint>
#include <iostream>
#include <type_traits>

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
  i32 a, b;
  std::cin >> a >> b;
  std::cout << (a * b % 2 == 0 ? "Even" : "Odd") << std::endl;
  return 0;
}