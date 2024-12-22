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

bool checkSquare(const std::vector<std::vector<i64>> &numberPlace, i64 left,
                 i64 top) {
  std::unordered_set<i64> n;

  for (i64 y = 0; y < 3; y++) {
    for (i64 x = 0; x < 3; x++) {
      n.insert(numberPlace[top + y][left + x]);
    }
  }

  return n.size() == 9;
}

bool checkColumn(const std::vector<std::vector<i64>> &numberPlace, i64 column) {
  std::unordered_set<i64> n;

  for (i64 i = 0; i < 9; i++) {
    n.insert(numberPlace[i][column]);
  }

  return n.size() == 9;
}

bool checkRow(const std::vector<std::vector<i64>> &numberPlace, i64 row) {
  std::unordered_set<i64> n;

  for (i64 i = 0; i < 9; i++) {
    n.insert(numberPlace[row][i]);
  }

  return n.size() == 9;
}

bool check(const std::vector<std::vector<i64>> &numberPlace) {
  bool result = true;

  for (i64 i = 0; i < 9; i++) {
    result = result && checkRow(numberPlace, i);
  }

  for (i64 i = 0; i < 9; i++) {
    result = result && checkColumn(numberPlace, i);
  }

  for (i64 y = 0; y < 9; y += 3) {
    for (i64 x = 0; x < 9; x += 3) {
      result = result && checkSquare(numberPlace, x, y);
    }
  }

  return result;
}

int main() {
  std::vector<std::vector<i64>> A(9, std::vector<i64>(9));

  for (auto &&A_i : A) {
    for (auto &&A_ij : A_i) {
      std::cin >> A_ij;
    }
  }

  std::cout << (check(A) ? "Yes" : "No") << std::endl;
exit:
  return 0;
}