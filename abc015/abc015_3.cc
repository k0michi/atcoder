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

i64 N, K;
std::vector<std::vector<i64>> T;

bool rec(i64 q, i64 answer) {
  if (q == N) {
    return answer == 0;
  }

  bool result = false;

  for (i64 i = 0; i < K; i++) {
    result = result || rec(q + 1, answer ^ T[q][i]);
  }

  return result;
}

int main() {
  std::cin >> N >> K;
  T.resize(N, std::vector<i64>(K));
  for (i64 i = 0; i < N; i++) {
    for (i64 j = 0; j < K; j++) {
      std::cin >> T[i][j];
    }
  }

  std::cout << (rec(0, 0) ? "Found" : "Nothing") << std::endl;
exit:
  return 0;
}