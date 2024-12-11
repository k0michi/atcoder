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

struct AABB {
  i64 x0, x1;
  i64 y0, y1;
  i64 z0, z1;

  static bool intersect(const AABB &a, const AABB &b) {
    return a.x0 < b.x1 && a.x1 > b.x0 && a.y0 < b.y1 && a.y1 > b.y0 &&
           a.z0 < b.z1 && a.z1 > b.z0;
  }
};

std::istream &operator>>(std::istream &s, AABB &aabb) {
  s >> aabb.x0 >> aabb.y0 >> aabb.z0 >> aabb.x1 >> aabb.y1 >> aabb.z1;
  return s;
}

int main() {
  AABB a, b;
  std::cin >> a >> b;
  std::cout << (AABB::intersect(a, b) ? "Yes" : "No") << std::endl;
exit:
  return 0;
}