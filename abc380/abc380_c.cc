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

std::string substring(const std::string &string, i64 start, i64 end) {
  return string.substr(start, end - start);
}

std::string substring(const std::string &string, i64 start) {
  return substring(string, start, string.size());
}

int main() {
  i64 N, K;
  std::string S;
  std::cin >> N >> K >> S;
  i64 begin, end, insertAfter;
  i64 chunk = 0;

  for (i64 i = 0; i < S.size(); i++) {
    if (S[i] == '1') {
      chunk++;

      if (chunk == K) {
        begin = i;
      }

      while (S[i] == '1') {
        if (chunk == K - 1) {
          insertAfter = i;
        }

        i++;
      }

      if (chunk == K) {
        end = i;
      }
    }
  }

  std::string inserted =
      substring(S, 0, insertAfter + 1) + substring(S, begin, end) +
      substring(S, insertAfter + 1, begin) + substring(S, end);
  std::cout << inserted << std::endl;
exit:
  return 0;
}