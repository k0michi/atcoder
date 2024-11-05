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

i32 result10000 = -1;
i32 result5000 = -1;
i32 result1000 = -1;

void process5000(i32 yen, i32 unusedBills, i32 bills10000, i32 bills5000) {
  if (yen < 0 || unusedBills == -1) {
    return;
  } else if (yen == unusedBills * 1000) {
    result10000 = bills10000;
    result5000 = bills5000;
    result1000 = unusedBills;
    return;
  }

  process5000(yen - 5000, unusedBills - 1, bills10000, bills5000 + 1);
}

void process10000(i32 yen, i32 unusedBills, i32 bills10000) {
  if (yen < 0 || unusedBills == -1) {
    return;
  } else if (yen == 0 && unusedBills == 0) {
    result10000 = bills10000;
    result5000 = 0;
    result1000 = 0;
    return;
  }

  process10000(yen - 10000, unusedBills - 1, bills10000 + 1);
  process5000(yen, unusedBills, bills10000, 0);
}

int main() {
  i32 N, Y;
  std::cin >> N >> Y;
  process10000(Y, N, 0);
  std::cout << result10000 << ' ' << result5000 << ' ' << result1000
            << std::endl;
  return 0;
}