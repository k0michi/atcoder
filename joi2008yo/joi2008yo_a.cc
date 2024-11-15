#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
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

std::vector<i64> coins = {500, 100, 50, 10, 5, 1};

int main() {
  i64 money;
  std::cin >> money;
  money = 1000 - money;
  i64 change = 0;

  for (i64 i = 0; i < coins.size() && money > 0; i++) {
    i64 c = money / coins[i];
    change += c;
    money -= c * coins[i];
  }

  std::cout << change << std::endl;
exit:
  return 0;
}