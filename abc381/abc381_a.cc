#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
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

bool isAll(std::string_view string, char letter) {
  return std::all_of(string.begin(), string.end(),
                     [&](char c) { return c == letter; });
}

int main() {
  i64 N;
  std::string S;
  std::cin >> N >> S;
  i64 l = S.size();
  std::cout << (l % 2 == 1 && S[l / 2] == '/' &&
                        isAll(std::string_view(S).substr(0, l / 2), '1') &&
                        isAll(std::string_view(S).substr(l / 2 + 1), '2')
                    ? "Yes"
                    : "No")
            << std::endl;
exit:
  return 0;
}