#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cctype>
#include <cmath>
#include <compare>
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

i64 a, b, c, d, e;

i64 getScore(i64 p) {
  return (p & 1 ? a : 0) + ((p >> 1) & 1 ? b : 0) + ((p >> 2) & 1 ? c : 0) +
         ((p >> 3) & 1 ? d : 0) + ((p >> 4) & 1 ? e : 0);
}

std::string getName(i64 p) {
  return std::string(p & 1 ? "A" : "") + ((p >> 1) & 1 ? "B" : "") +
         ((p >> 2) & 1 ? "C" : "") + ((p >> 3) & 1 ? "D" : "") +
         ((p >> 4) & 1 ? "E" : "");
}

int main() {
  std::cin >> a >> b >> c >> d >> e;
  std::vector<i64> participants(31);
  std::iota(participants.begin(), participants.end(), 1);

  std::sort(participants.begin(), participants.end(), [&](auto &&a, auto &&b) {
    i64 aScore = getScore(a);
    i64 bScore = getScore(b);

    return aScore != bScore ? aScore > bScore : getName(a) < getName(b);
  });

  for (i64 i = 0; i < participants.size(); i++) {
    std::cout << getName(participants[i]) << std::endl;
  }

exit:
  return 0;
}