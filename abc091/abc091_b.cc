#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
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
  i64 N, M;
  std::cin >> N;
  std::unordered_map<std::string, i64> cards;

  for (i64 i = 0; i < N; i++) {
    std::string s_i;
    std::cin >> s_i;
    cards[s_i] = cards[s_i] + 1;
  }

  std::cin >> M;

  for (i64 i = 0; i < M; i++) {
    std::string t_i;
    std::cin >> t_i;
    cards[t_i] = cards[t_i] - 1;
  }

  i64 max = 0;

  for (auto &&c : cards) {
    max = std::max(c.second, max);
  }

  std::cout << max << std::endl;
  return 0;
}