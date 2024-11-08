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
  std::unordered_set<i64> buttons;
  i64 N;
  std::cin >> N;
  std::vector<i64> a(N);

  for (auto &&a_i : a) {
    std::cin >> a_i;
  }

  i64 button = 1;
  i64 count = 0;

  while (button != 2) {
    if (buttons.count(button) > 0) {
      std::cout << -1 << std::endl;
      goto exit;
    }

    count++;
    buttons.insert(button);
    button = a[button - 1];
  }

  std::cout << count << std::endl;

exit:
  return 0;
}