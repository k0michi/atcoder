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

i64 swapCount(std::string a, std::string b) {
  i64 count = 0;

  for (i64 i = 0; i < b.size(); i++) {
    if (a[i] != b[i]) {
      count++;
    }
  }

  return count;
}

std::string minimizeSwaps(std::string string, i64 begin,
                          std::string compareTo) {
  std::vector<char> swapped(string.size());

  for (i64 i = 0; i < begin; i++) {
    swapped[i] = string[i];
  }

  std::unordered_multiset<char> letters;

  for (i64 i = 0; i < string.size(); i++) {
    letters.insert(string[i]);
  }

  for (i64 i = 0; i < string.size(); i++) {
    if (i < begin) {
      letters.erase(letters.find(string[i]));
      swapped[i] = string[i];
    } else {
      if (letters.count(compareTo[i]) > 0) {
        letters.erase(letters.find(compareTo[i]));
        swapped[i] = compareTo[i];
      }
    }
  }

  auto shouldMove = std::vector(letters.begin(), letters.end());
  std::sort(shouldMove.begin(), shouldMove.end());

  for (i64 i = 0, j = 0; i < string.size(); i++) {
    if (swapped[i] == 0) {
      swapped[i] = shouldMove[j++];
    }
  }

  return std::string{swapped.begin(), swapped.end()};
}

i64 N, K;
std::string S;

std::string tryModify(i64 target, std::string string) {
  std::vector<i64> swapWith;

  for (i64 i = target + 1; i < string.size(); i++) {
    if (string[target] > string[i]) {
      swapWith.push_back(i);
    }
  }

  std::sort(swapWith.begin(), swapWith.end(),
            [&](auto &&a, auto &&b) { return string[a] < string[b]; });

  for (auto &&s : swapWith) {
    std::string swapped = string;
    std::swap(swapped[target], swapped[s]);
    swapped = minimizeSwaps(swapped, target + 1, S);
    i64 count = swapCount(swapped, S);

    if (K >= count) {
      return swapped;
    }
  }

  return string;
}

std::string modify() {
  std::string string = S;

  for (i64 i = 0; i < S.size(); i++) {
    string = tryModify(i, string);
  }

  return string;
}

int main() {
  std::cin >> N >> K >> S;
  std::cout << modify() << std::endl;
exit:
  return 0;
}