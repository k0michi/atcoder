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

struct Cell {
  i64 cell, amount;
};

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::vector<Cell> initial(M);
  for (i64 i = 0; i < M; i++) {
    std::cin >> initial[i].cell;
    initial[i].cell--;
  }
  for (i64 i = 0; i < M; i++) {
    std::cin >> initial[i].amount;
  }

  std::sort(initial.begin(), initial.end(),
            [](auto &&a, auto &&b) { return a.cell < b.cell; });

  i64 steps = 0;
  i64 cumulative = 0;
  i64 last = -1;

  for (i64 i = 0; i < M; i++) {
    cumulative -= initial[i].cell;

    if (cumulative < 0) {
      steps = -1;
      break;
    }

    steps += initial[i].amount * (initial[i].amount - 1) / 2;
    steps += cumulative * initial[i].amount;
    last = initial[i].cell + cumulative + initial[i].amount - 1;
    cumulative += initial[i].cell + initial[i].amount;
  }

  if (last != N - 1) {
    steps = -1;
  }

  std::cout << steps << std::endl;
exit:
  return 0;
}