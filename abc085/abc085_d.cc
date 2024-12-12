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

int main() {
  i64 N, H;
  std::cin >> N >> H;
  std::vector<std::pair<i64, i64>> katanas(N);
  std::pair<i64, i64> katanaA{0, 0};
  for (i64 i = 0; i < N; i++) {
    std::cin >> katanas[i].first >> katanas[i].second;

    if (katanaA.first < katanas[i].first) {
      katanaA = katanas[i];
    }
  }

  katanas.erase(
      std::remove_if(katanas.begin(), katanas.end(),
                     [&](auto &&k) { return k.second < katanaA.first; }),
      katanas.end());
  std::sort(katanas.begin(), katanas.end(),
            [](auto &&a, auto &&b) { return a.second > b.second; });

  i64 count = 0;

  for (i64 i = 0; i < katanas.size(); i++) {
    H -= katanas[i].second;
    count++;

    if (H <= 0) {
      goto done;
    }
  }

  count += H / katanaA.first;
  count += i64(H % katanaA.first > 0);
done:
  std::cout << count << std::endl;
exit:
  return 0;
}