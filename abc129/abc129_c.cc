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

template <typename T>
inline T getOrDefault(const std::vector<T> &vector, usize index, T orDefault) {
  if (index >= 0 && index < vector.size()) {
    return vector[index];
  }

  return orDefault;
}

constexpr i64 kBase = 1000000007;

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::unordered_set<i64> a;

  for (i64 i = 0; i < M; i++) {
    i64 a_i;
    std::cin >> a_i;
    a.insert(a_i);
  }

  std::vector<i64> memo(N + 1);
  memo[0] = 1;

  for (i64 i = 1; i <= N; i++) {
    memo[i] = a.contains(i)
                  ? 0
                  : (memo[i - 1] + getOrDefault<i64>(memo, i - 2, 0)) % kBase;
  }

  std::cout << memo[N] << std::endl;

exit:
  return 0;
}