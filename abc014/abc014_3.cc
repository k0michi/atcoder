#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <set>
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

int main() {
  i64 n;
  std::cin >> n;

  std::array<i64, 1000002> colors{};

  for (i64 i = 0; i < n; i++) {
    i64 a_i, b_i;
    std::cin >> a_i >> b_i;
    colors[a_i]++;
    colors[b_i + 1]--;
  }

  for (i64 i = 1; i < colors.size(); i++) {
    colors[i] += colors[i - 1];
  }

  i64 max = *std::max_element(colors.begin(), colors.end());
  std::cout << max << std::endl;
exit:
  return 0;
}