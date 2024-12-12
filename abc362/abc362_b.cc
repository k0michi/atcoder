#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
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
};

Vector2 operator-(const Vector2 &a, const Vector2 &b) {
  return {a.x - b.x, a.y - b.y};
}

bool isRight(const Vector2 &a, const Vector2 &b, const Vector2 &c) {
  return (a - c).lengthSquared() + (b - c).lengthSquared() ==
         (a - b).lengthSquared();
}

int main() {
  Vector2 A, B, C;
  std::cin >> A.x >> A.y;
  std::cin >> B.x >> B.y;
  std::cin >> C.x >> C.y;

  std::cout << (isRight(A, B, C) || isRight(B, C, A) || isRight(A, C, B) ? "Yes"
                                                                         : "No")
            << std::endl;
exit:
  return 0;
}