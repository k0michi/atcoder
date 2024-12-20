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
  i64 N;
  std::cin >> N;
  std::vector<i64> A(N);
  std::cin >> A;

  i64 length = N;
  std::list<i64> stack;

  for (i64 i = 0; i < N; i++) {
    stack.push_back(A[i]);

    while (stack.size() >= 2 && *stack.rbegin() == *std::next(stack.rbegin())) {
      i64 back = *stack.rbegin();
      stack.pop_back();
      stack.pop_back();
      stack.push_back(back + 1);
      length--;
    }
  }

  std::cout << length << std::endl;
exit:
  return 0;
}