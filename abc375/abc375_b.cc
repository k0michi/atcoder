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
  std::vector<i64> X(N), Y(N);

  for (i64 i = 0; i < N; i++) {
    std::cin >> X[i] >> Y[i];
  }

  f64 distance = std::hypot(X[0], Y[0]);

  for (i64 i = 0; i < N - 1; i++) {
    distance += std::hypot(X[i + 1] - X[i], Y[i + 1] - Y[i]);
  }

  distance += std::hypot(X.back(), Y.back());
  std::cout << std::fixed << std::setprecision(7) << distance << std::endl;
exit:
  return 0;
}