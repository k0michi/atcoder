#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
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

bool isPairBegin(const std::vector<i64> &s, i64 i) { return s[i] == s[i + 1]; }

void popFrontUntil(std::list<i64> &l, i64 e, std::unordered_set<i64> &set) {
  while (l.front() != e) {
    set.erase(l.front());
    l.pop_front();
  }

  set.erase(l.front());
  l.pop_front();
}

int main() {
  i64 N;
  std::cin >> N;
  std::vector<i64> A(N);
  for (auto &&A_i : A) {
    std::cin >> A_i;
  }

  std::array<std::unordered_set<i64>, 2> seriesSets{};
  std::array<std::list<i64>, 2> series{};
  i64 max = 0;

  for (i64 i = 0; i < N - 1; i++) {
    i64 evenOdd = i % 2;

    if (isPairBegin(A, i)) {
      if (seriesSets[evenOdd].contains(A[i])) {
        popFrontUntil(series[evenOdd], A[i], seriesSets[evenOdd]);
      }

      seriesSets[evenOdd].insert(A[i]);
      series[evenOdd].push_back(A[i]);
      max = std::max(max, i64(series[evenOdd].size() * 2));
    } else {
      seriesSets[evenOdd].clear();
      series[evenOdd].clear();
    }
  }

  std::cout << max << std::endl;
exit:
  return 0;
}