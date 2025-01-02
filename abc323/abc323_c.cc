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

template <typename T>
std::istream &operator>>(std::istream &s, std::vector<T> &v) {
  for (auto &&v_i : v) {
    s >> v_i;
  }
  return s;
}

int main() {
  i64 N, M;
  std::cin >> N >> M;
  std::vector<i64> A(M);
  std::cin >> A;
  std::vector<std::string> S(N);
  std::cin >> S;

  std::vector<std::pair<i64, i64>> points;

  for (i64 i = 0; i < M; i++) {
    points.push_back({A[i], i});
  }

  std::sort(points.rbegin(), points.rend());

  i64 maxScore = 0;

  for (i64 i = 0; i < N; i++) {
    i64 score = i + 1;

    for (i64 j = 0; j < M; j++) {
      score += S[i][j] == 'o' ? A[j] : 0;
    }

    maxScore = std::max(maxScore, score);
  }

  for (i64 i = 0; i < N; i++) {
    i64 score = i + 1;

    for (i64 j = 0; j < M; j++) {
      score += S[i][j] == 'o' ? A[j] : 0;
    }

    i64 count = 0;

    for (i64 j = 0; j < M && maxScore > score; j++) {
      if (S[i][points[j].second] == 'x') {
        score += points[j].first;
        count++;
      }
    }

    std::cout << count << std::endl;
  }
exit:
  return 0;
}