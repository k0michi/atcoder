#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
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
  i64 D, G;
  std::cin >> D >> G;
  std::vector<i64> p(D), c(D);

  for (i64 i = 0; i < D; i++) {
    std::cin >> p[i] >> c[i];
  }

  i64 problemsMin = std::numeric_limits<i64>::max();

  for (i64 i = 0; i < (1 << D); i++) {
    i64 GTemp = G;
    i64 problems = 0;
    i64 unusedMax;

    for (i64 j = 0; j < D; j++) {
      i64 score = (j + 1) * 100;

      if ((i >> j) & 1) {
        GTemp -= p[j] * score + c[j];
        problems += p[j];
      } else {
        unusedMax = j;
      }
    }

    if (GTemp > 0) {
      i64 unusedScore = (unusedMax + 1) * 100;
      i64 q =
          std::min(i64(std::ceil(double(GTemp) / unusedScore)), p[unusedMax]);
      GTemp -= q * unusedScore;
      problems += q;
    }

    if (GTemp <= 0) {
      problemsMin = std::min(problems, problemsMin);
    }
  }

  std::cout << problemsMin << std::endl;
exit:
  return 0;
}