#include <algorithm>
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

std::string S;
std::vector<std::string> strings = {"dream", "dreamer", "erase", "eraser"};

bool check(i32 i) {
  if (i == S.size()) {
    return true;
  }

  std::string sub = S.substr(i, 7);

  return sub.starts_with(strings[0]) && check(i + strings[0].size()) ||
         sub.starts_with(strings[1]) && check(i + strings[1].size()) ||
         sub.starts_with(strings[2]) && check(i + strings[2].size()) ||
         sub.starts_with(strings[3]) && check(i + strings[3].size());
}

int main() {
  std::cin >> S;
  std::reverse(S.begin(), S.end());

  for (auto &&s : strings) {
    std::reverse(s.begin(), s.end());
  }

  std::cout << (check(0) ? "YES" : "NO") << std::endl;
  return 0;
}