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
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
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

i64 sum(i64 i, i64 j) { return (j * (j + 1) - (i - 1) * i) / 2; }

int main() {
  i64 N, K;
  std::cin >> N >> K;

  std::unordered_set<i64> appears;

  for (i64 i = 0; i < N; i++) {
    i64 A_i;
    std::cin >> A_i;

    if (A_i >= 1 && A_i <= K) {
      appears.insert(A_i);
    }
  }

  i64 appearsSum = std::reduce(appears.begin(), appears.end());
  i64 totalSum = sum(1, K);
  std::cout << (totalSum - appearsSum) << std::endl;
exit:
  return 0;
}