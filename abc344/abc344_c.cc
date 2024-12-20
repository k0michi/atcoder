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

std::vector<i64> readVector() {
  i64 N;
  std::cin >> N;
  std::vector<i64> A(N);
  std::cin >> A;
  return A;
}

int main() {
  auto A = readVector();
  auto B = readVector();
  auto C = readVector();
  auto X = readVector();

  std::unordered_map<i64, bool> possible;

  for (i64 i = 0; i < A.size(); i++) {
    for (i64 j = 0; j < B.size(); j++) {
      for (i64 k = 0; k < C.size(); k++) {
        i64 sum = A[i] + B[j] + C[k];
        possible[sum] = true;
      }
    }
  }

  for (i64 i = 0; i < X.size(); i++) {
    std::cout << (possible[X[i]] ? "Yes" : "No") << std::endl;
  }
exit:
  return 0;
}