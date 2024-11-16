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

std::string restore(std::string SPrime, std::string T) {
  std::vector<std::string> candidates;

  for (i64 i = 0; i <= i64(SPrime.size()) - i64(T.size()); i++) {
    std::string S = SPrime;

    for (i64 j = 0; j < S.size(); j++) {
      if (j >= i && j < i + T.size()) {
        if (S[j] != '?' && S[j] != T[j - i]) {
          goto next;
        }
        S[j] = T[j - i];
      } else if (S[j] == '?') {
        S[j] = 'a';
      }
    }

    candidates.push_back(S);
  next:;
  }

  if (candidates.empty()) {
    return "UNRESTORABLE";
  }

  std::sort(candidates.begin(), candidates.end());
  return candidates[0];
}

int main() {
  std::string SPrime, T;
  std::cin >> SPrime >> T;
  std::cout << restore(SPrime, T) << std::endl;
exit:
  return 0;
}