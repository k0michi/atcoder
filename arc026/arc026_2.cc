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

std::vector<i64> enumerateDivisors(i64 n) {
  std::list<i64> divisors;
  auto mid = divisors.end();

  for (i64 i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      divisors.insert(mid, i);

      if (i * i != n) {
        mid = divisors.insert(mid, n / i);
      }
    }
  }

  return std::vector<i64>(divisors.begin(), divisors.end());
}

int main() {
  i64 N;
  std::cin >> N;
  auto divisors = enumerateDivisors(N);
  i64 sum = 0;

  for (i64 i = 0; i < divisors.size() - 1; i++) {
    sum += divisors[i];
  }

  std::cout << (sum == N  ? "Perfect"
                : sum < N ? "Deficient"
                          : "Abundant")
            << std::endl;
exit:
  return 0;
}