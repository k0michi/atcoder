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

std::vector<bool> eratosthenes(i64 n) {
  std::vector<bool> result(n + 1, true);
  result[0] = false;
  result[1] = false;
  for (i64 i = 2; i <= n; i++) {
    if (result[i]) {
      for (i64 j = i * 2; j <= n; j += i) {
        result[j] = false;
      }
    }
  }
  return result;
}

i64 powInt(i64 base, i64 exp) {
  if (exp == 0) {
    return 1;
  }

  i64 h = powInt(base, exp / 2);

  if (exp % 2 == 0) {
    return h * h;
  } else {
    return base * h * h;
  }
}

int main() {
  i64 N;
  std::cin >> N;
  i64 sqrtN = std::sqrt(N);
  auto table = eratosthenes(sqrtN);
  i64 count = 0;

  for (i64 i = 1; i <= sqrtN; i++) {
    if (table[i]) {
      if (powInt(i, 2) > sqrtN) {
        break;
      }

      if (powInt(i, 4) <= sqrtN) {
        count++;
      }

      for (i64 j = i + 1; j <= sqrtN; j++) {
        if (table[j]) {
          if (i * j <= sqrtN) {
            count++;
          } else {
            break;
          }
        }
      }
    }
  }

  std::cout << count << std::endl;
exit:
  return 0;
}