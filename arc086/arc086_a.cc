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
  i64 N, K;
  std::cin >> N >> K;
  std::unordered_map<i64, i64> balls;

  for (i64 i = 0; i < N; i++) {
    i64 A_i;
    std::cin >> A_i;
    balls[A_i]++;
  }

  auto ballVec = std::vector<std::pair<i64, i64>>(balls.begin(), balls.end());

  std::sort(ballVec.begin(), ballVec.end(),
            [](auto &&a, auto &&b) { return a.second < b.second; });

  i64 rewrites = 0;

  for (i64 i = 0; i < i64(ballVec.size()) - K; i++) {
    rewrites += ballVec[i].second;
  }

  std::cout << rewrites << std::endl;
  return 0;
}