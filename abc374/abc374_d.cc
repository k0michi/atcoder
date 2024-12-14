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

struct Vector2 {
  i64 x, y;

  i64 lengthSquared() { return x * x + y * y; }

  f64 length() { return std::sqrt(lengthSquared()); }
};

Vector2 operator-(const Vector2 &a, const Vector2 &b) {
  return {a.x - b.x, a.y - b.y};
}

i64 N, S, T;
std::vector<i64> A(N), B(N), C(N), D(N);

f64 calcMoveTime(const std::vector<i64> &order, i64 directions) {
  f64 time = 0;
  Vector2 pos{0, 0};

  for (i64 i = 0; i < N; i++) {
    auto a = Vector2{A[order[i]], B[order[i]]},
         b = Vector2{C[order[i]], D[order[i]]};

    if ((directions >> i) & 1) {
      time += (a - pos).length();
      pos = b;
    } else {
      time += (b - pos).length();
      pos = a;
    }
  }

  return time / S;
}

f64 calcLaserTime() {
  f64 time = 0;

  for (i64 i = 0; i < N; i++) {
    time += (Vector2{C[i], D[i]} - Vector2{A[i], B[i]}).length();
  }

  return time / T;
}

int main() {
  std::cin >> N >> S >> T;
  A.resize(N);
  B.resize(N);
  C.resize(N);
  D.resize(N);
  for (i64 i = 0; i < N; i++) {
    std::cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  std::vector<i64> order(N);
  std::iota(order.begin(), order.end(), 0);
  f64 moveTime = std::numeric_limits<f64>::max();

  do {
    for (i64 i = 0; i < (1 << N); i++) {
      moveTime = std::min(moveTime, calcMoveTime(order, i));
    }
  } while (std::next_permutation(order.begin(), order.end()));

  std::cout << std::fixed << std::setprecision(7)
            << (moveTime + calcLaserTime()) << std::endl;
exit:
  return 0;
}