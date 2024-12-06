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
  i64 M;
  std::cin >> M;

  std::vector<i64> A;
  while (M > 0) {
    i64 i = 1, a = 0;

    while (i * 3 <= M) {
      a++;
      i *= 3;
    }

    A.push_back(a);
    M -= i;
  }

  std::cout << A.size() << std::endl;
  for (i64 i = 0; i < A.size(); i++) {
    if (i > 0) {
      std::cout << ' ';
    }

    std::cout << A[i];
  }
  std::cout << std::endl;
exit:
  return 0;
}