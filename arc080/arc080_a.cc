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
#include <tuple>
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

i64 primeFactorize(i64 n, i64 p) {
  i64 k = 0;

  while (n % p == 0) {
    n /= p;
    k++;
  }

  return k;
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> a(N);
  std::cin >> a;

  i64 count0 = 0, count1 = 0, countGE2 = 0;

  for (i64 i = 0; i < N; i++) {
    i64 factor = primeFactorize(a[i], 2);
    count0 += i64(factor == 0);
    count1 += i64(factor == 1);
    countGE2 += i64(factor >= 2);
  }

  i64 requiredGE2 = count0 + std::min(count1, i64(1)) - 1;
  bool result = requiredGE2 <= countGE2;
  std::cout << (result ? "Yes" : "No") << std::endl;
exit:
  return 0;
}