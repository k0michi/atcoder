#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
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
  i64 N, M;
  std::cin >> N >> M;
  std::array<bool, 100> born{};

  for (i64 i = 0; i < M; i++) {
    i64 A_i;
    char B_i;
    std::cin >> A_i >> B_i;

    if (B_i == 'M' && !born[A_i]) {
      std::cout << "Yes" << std::endl;
      born[A_i] = true;
    } else {
      std::cout << "No" << std::endl;
    }
  }

exit:
  return 0;
}