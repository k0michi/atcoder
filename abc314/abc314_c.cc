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

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::string S;
  std::cin >> S;
  std::vector<std::vector<i64>> indices(M);

  for (i64 i = 0; i < N; i++) {
    i64 C_i;
    std::cin >> C_i;
    indices[C_i - 1].push_back(i);
  }

  for (i64 i = 0; i < M; i++) {
    for (i64 j = indices[i].size() - 2; j >= 0; j--) {
      std::swap(S[indices[i][j]], S[indices[i][j + 1]]);
    }
  }

  std::cout << S << std::endl;
exit:
  return 0;
}