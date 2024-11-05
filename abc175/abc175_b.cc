#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_set>
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

int main() {
  i32 N;
  std::cin >> N;
  std::vector<i32> L(N);

  for (auto &&l : L) {
    std::cin >> l;
  }

  i32 triangles = 0;

  for (i32 i = 0; i < N; i++) {
    for (i32 j = i + 1; j < N; j++) {
      for (i32 k = j + 1; k < N; k++) {
        auto a = L[i], b = L[j], c = L[k];

        if (a != b && b != c && a != c && a + b > c && b + c > a && a + c > b) {
          triangles++;
        }
      }
    }
  }

  std::cout << triangles << std::endl;
  return 0;
}