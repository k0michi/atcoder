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

template <typename T>
std::istream &operator>>(std::istream &s, std::vector<T> &v) {
  for (auto &&v_i : v) {
    s >> v_i;
  }
  return s;
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> A(N), W(N);
  std::cin >> A >> W;

  std::vector<std::vector<i64>> boxes(N);
  for (i64 i = 0; i < N; i++) {
    boxes[A[i] - 1].push_back(W[i]);
  }

  i64 result = 0;

  for (i64 i = 0; i < N; i++) {
    if (boxes[i].size() > 1) {
      std::sort(boxes[i].begin(), boxes[i].end());
      result += std::reduce(boxes[i].begin(), boxes[i].end() - 1);
    }
  }

  std::cout << result << std::endl;
exit:
  return 0;
}