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

template <typename T>
std::istream &operator>>(std::istream &s, std::vector<T> &v) {
  for (auto &&v_i : v) {
    s >> v_i;
  }
  return s;
}

i64 N;
std::vector<i64> Q, A, B;

i64 maximizeDishes(i64 aCount) {
  std::vector<i64> QTemp = Q;
  i64 dishes = 0;

  for (i64 i = 0; i < N; i++) {
    QTemp[i] -= A[i] * aCount;

    if (QTemp[i] < 0) {
      return 0;
    }
  }

  i64 bCount = std::numeric_limits<i64>::max();

  for (i64 i = 0; i < N; i++) {
    if (B[i] > 0) {
      bCount = std::min(bCount, QTemp[i] / B[i]);
    }
  }

  return aCount + bCount;
}

int main() {
  std::cin >> N;
  Q.resize(N);
  A.resize(N);
  B.resize(N);
  std::cin >> Q >> A >> B;

  i64 QMax = *std::max_element(Q.begin(), Q.end());
  i64 max = 0;

  for (i64 i = 0; i <= QMax; i++) {
    max = std::max(max, maximizeDishes(i));
  }

  std::cout << max << std::endl;
exit:
  return 0;
}