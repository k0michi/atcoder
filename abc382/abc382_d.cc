#include <algorithm>
#include <array>
#include <bit>
#include <bitset>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
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

i64 N, M;
std::vector<std::vector<i64>> sequences;

void dfs(std::vector<i64> seq) {
  if (seq.size() == N) {
    sequences.push_back(seq);
    return;
  }

  i64 first = seq.size() == 0 ? 1 : seq.back() + 10;
  i64 restSize = N - (seq.size() + 1);

  for (i64 i = first; i <= (M - restSize * 10); i++) {
    std::vector<i64> appended = seq;
    appended.push_back(i);
    dfs(appended);
  }
}

int main() {
  std::cin >> N >> M;
  dfs({});

  std::cout << sequences.size() << std::endl;
  for (i64 i = 0; i < sequences.size(); i++) {
    for (i64 j = 0; j < sequences[i].size(); j++) {
      if (j > 0) {
        std::cout << ' ';
      }

      std::cout << sequences[i][j];
    }

    std::cout << std::endl;
  }

exit:
  return 0;
}