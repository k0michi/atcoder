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

struct Range {
  i64 begin, end;
};

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::vector<Range> ranges(M);

  for (i64 i = 0; i < M; i++) {
    i64 a_i, b_i;
    std::cin >> a_i >> b_i;
    ranges[i] = {a_i, b_i};
  }

  std::sort(ranges.begin(), ranges.end(),
            [](auto &&a, auto &&b) { return a.end < b.end; });

  i64 end = std::numeric_limits<i64>::min();
  i64 count = 0;
  for (auto &&r : ranges) {
    if (end <= r.begin) {
      end = r.end;
      count++;
    }
  }

  std::cout << count << std::endl;
exit:
  return 0;
}