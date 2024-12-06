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
  std::vector<std::vector<i64>> A(N, std::vector<i64>(N, 0));

  for (i64 i = 0; i < N; i++) {
    for (i64 j = 0; j <= i; j++) {
      std::cin >> A[i][j];
    }
  }

  i64 current = 1;

  for (i64 i = 1; i <= N; i++) {
    i64 a = current, b = i;

    if (a <= b) {
      std::swap(a, b);
    }

    current = A[a - 1][b - 1];
  }

  std::cout << current << std::endl;
exit:
  return 0;
}