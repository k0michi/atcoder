#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
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

i64 N, M;
std::unordered_set<i64> knights;

void insert(i64 a, i64 b) {
  if (a >= 1 && a <= N && b >= 1 && b <= N) {
    knights.insert((a << 30) | b);
  }
}

int main() {
  std::cin >> N >> M;

  for (i64 i = 0; i < M; i++) {
    i64 a_i, b_i;
    std::cin >> a_i >> b_i;
    insert(a_i, b_i);
    insert(a_i + 2, b_i + 1);
    insert(a_i + 1, b_i + 2);
    insert(a_i - 1, b_i + 2);
    insert(a_i - 2, b_i + 1);
    insert(a_i - 2, b_i - 1);
    insert(a_i - 1, b_i - 2);
    insert(a_i + 1, b_i - 2);
    insert(a_i + 2, b_i - 1);
  }

  std::cout << (N * N - knights.size()) << std::endl;
exit:
  return 0;
}