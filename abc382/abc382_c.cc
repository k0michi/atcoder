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

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::vector<i64> A(N), B(M);

  for (i64 i = 0; i < N; i++) {
    std::cin >> A[i];
    if (i > 0) {
      A[i] = std::min(A[i], A[i - 1]);
    }
  }

  for (auto &&B_i : B) {
    std::cin >> B_i;
  }

  for (i64 i = 0; i < M; i++) {
    auto eater =
        std::lower_bound(A.begin(), A.end(), B[i], std::greater<i64>{});
    std::cout << (eater == A.end() ? -1 : (std::distance(A.begin(), eater) + 1))
              << std::endl;
  }

exit:
  return 0;
}