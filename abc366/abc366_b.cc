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
  i64 N;
  std::cin >> N;
  std::vector<std::string> S(N);
  i64 height = 0;
  for (auto &&S_i : S) {
    std::cin >> S_i;
    height = std::max(height, i64(S_i.size()));
  }

  std::vector<i64> rightMost(height, -1);
  for (i64 i = 0; i < S.size(); i++) {
    for (i64 j = 0; j < S[i].size(); j++) {
      rightMost[j] = std::max(rightMost[j], N - i - 1);
    }
  }

  for (i64 y = 0; y < height; y++) {
    for (i64 x = 0; x < N; x++) {
      if (y < S[N - x - 1].size()) {
        std::cout << S[N - x - 1][y];
      } else if (rightMost[y] > x) {
        std::cout << '*';
      }
    }
    std::cout << std::endl;
  }

exit:
  return 0;
}