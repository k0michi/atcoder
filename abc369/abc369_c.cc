#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cctype>
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

i64 sum(i64 i, i64 j) { return (j * (j + 1) - (i - 1) * i) / 2; }

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> A(N);
  for (auto &&A_i : A) {
    std::cin >> A_i;
  }

  i64 lastD, lastDBegin = 0;
  i64 count = 0;

  for (i64 i = 1; i < N; i++) {
    if (i > 1) {
      i64 d = A[i] - A[i - 1];

      if (lastD != d) {
        count += sum(1, (i - 1) - lastDBegin + 1) - 1;
        lastDBegin = i - 1;
      }

      lastD = d;
    } else if (i == 1) {
      lastD = A[i] - A[i - 1];
    }
  }

  count += sum(1, (N - 1) - lastDBegin + 1);
  std::cout << count << std::endl;
exit:
  return 0;
}