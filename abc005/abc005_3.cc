#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
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

int main() {
  i64 T, N, M;
  std::cin >> T >> N;
  std::vector<i64> A(N);
  for (auto &&A_i : A) {
    std::cin >> A_i;
  }
  std::cin >> M;
  std::vector<i64> B(M);
  for (auto &&B_i : B) {
    std::cin >> B_i;
  }

  std::deque<i64> queue;

  for (i64 i = 0, j = 0; i < N || j < M;) {
    if (i < N && j < M && A[i] <= B[j] || j == M) {
      queue.push_back(A[i]);
      i++;
    } else {
      while (!queue.empty() && B[j] - queue.front() > T) {
        queue.pop_front();
      }

      if (queue.empty()) {
        std::cout << "no" << std::endl;
        goto exit;
      }

      queue.pop_front();
      j++;
    }
  }

  std::cout << "yes" << std::endl;
exit:
  return 0;
}