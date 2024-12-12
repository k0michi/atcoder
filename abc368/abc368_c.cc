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
  i64 N;
  std::cin >> N;
  i64 T = 0;

  for (i64 i = 0; i < N; i++) {
    i64 H_i;
    std::cin >> H_i;

    i64 a = H_i / 5;
    H_i -= a * 5;
    T += a * 3;

    while (H_i > 0) {
      T++;
      if (T % 3 == 0) {
        H_i -= 3;
      } else {
        H_i--;
      }
    }
  }

  std::cout << T << std::endl;
exit:
  return 0;
}