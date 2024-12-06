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
  char S_AB, S_AC, S_BC;
  std::cin >> S_AB >> S_AC >> S_BC;

  std::unordered_map<std::string, bool> compMap;
  compMap["AB"] = S_AB == '<';
  compMap["AC"] = S_AC == '<';
  compMap["BC"] = S_BC == '<';
  std::array<char, 3> brothers{'A', 'B', 'C'};

  std::sort(brothers.begin(), brothers.end(), [&](char a, char b) {
    if (a < b) {
      return compMap[std::string{a} + b];
    } else {
      return !compMap[std::string{b} + a];
    }
  });

  std::cout << brothers[1] << std::endl;
exit:
  return 0;
}