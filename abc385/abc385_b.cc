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

i64 H, W, X, Y;
std::vector<std::string> S(H);
std::string T;

bool canEnter(i64 x, i64 y) {
  return x >= 0 && x < H && y >= 0 && y < W && S[x][y] != '#';
}

int main() {
  std::cin >> H >> W >> X >> Y;
  X--;
  Y--;
  S.resize(H);
  for (auto &&S_i : S) {
    std::cin >> S_i;
  }
  std::cin >> T;

  std::unordered_set<i64> houses;

  for (i64 i = 0; i < T.size(); i++) {
    if (S[X][Y] == '@') {
      houses.insert(X + (Y * 1000));
    }

    switch (T[i]) {
    case 'U':
      if (canEnter(X - 1, Y)) {
        X--;
      }
      break;
    case 'D':
      if (canEnter(X + 1, Y)) {
        X++;
      }
      break;
    case 'L':
      if (canEnter(X, Y - 1)) {
        Y--;
      }
      break;
    case 'R':
      if (canEnter(X, Y + 1)) {
        Y++;
      }
      break;
    }
  }

  if (S[X][Y] == '@') {
    houses.insert(X + (Y * 1000));
  }

  std::cout << X + 1 << ' ' << Y + 1 << ' ' << houses.size() << std::endl;
exit:
  return 0;
}