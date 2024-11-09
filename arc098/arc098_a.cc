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
  i64 N;
  std::cin >> N;
  std::string S;
  std::cin >> S;

  i64 facingE = 0;

  for (i64 i = 0; i < S.size(); i++) {
    facingE += i64(S[i] == 'E');
  }

  i64 facingW = 0;
  i64 min = std::numeric_limits<i64>::max();

  for (i64 i = 0; i < S.size(); i++) {
    facingE -= i64(S[i] == 'E');
    min = std::min(facingE + facingW, min);
    facingW += i64(S[i] == 'W');
  }

  std::cout << min << std::endl;

exit:
  return 0;
}