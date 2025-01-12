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
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using uchar = unsigned char;
using schar = signed char;
using ushort = unsigned short;
using uint = unsigned int;
using ulong = unsigned long;
using llong = long long;
using ullong = unsigned long long;

using namespace std::literals;

template <typename T, typename = void> struct IsIterator : std::false_type {};
template <typename T>
struct IsIterator<T, std::void_t<typename std::iterator_traits<T>::value_type>>
    : public std::true_type {};
template <typename T> inline constexpr bool IsIteratorV = IsIterator<T>::value;

template <typename T, typename = void> struct IsIterable : std::false_type {};
template <typename T>
struct IsIterable<T, std::void_t<typename std::remove_reference_t<T>::iterator>>
    : public std::true_type {};
template <typename T> inline constexpr bool IsIterableV = IsIterable<T>::value;

template <typename T, typename = void> struct IsReadable : std::false_type {};
template <typename T>
struct IsReadable<
    T, std::void_t<decltype(std::declval<std::istream>() >> std::declval<T>())>>
    : public std::true_type {};
template <typename T> inline constexpr bool IsReadableV = IsReadable<T>::value;

template <typename T, typename = void> struct IsWritable : std::false_type {};
template <typename T>
struct IsWritable<
    T, std::void_t<decltype(std::declval<std::ostream>() << std::declval<T>())>>
    : public std::true_type {};
template <typename T> inline constexpr bool IsWritableV = IsWritable<T>::value;

std::string separator = " ";
ullong column = 0;
ullong row = 0;

void setSeparator(std::string_view s) { separator = s; }

std::istream &read() { return std::cin; }

std::istream &readln(std::string &s) { return std::getline(std::cin, s); }

template <typename T, typename... U,
          std::enable_if_t<IsReadableV<T>> * = nullptr>
std::istream &read(T &&t, U &&...u) {
  std::cin >> t;
  return read(std::forward<U>(u)...);
}

template <typename T, typename... U,
          std::enable_if_t<IsIterableV<T> && !IsReadableV<T>> * = nullptr>
std::istream &read(T &&t, U &&...u) {
  for (auto &&t_i : t) {
    read(t_i);
  }

  return read(std::forward<U>(u)...);
}

void readIterators() {}

template <typename T, typename... U> void readIterators(T &&t, U &&...u) {
  read(*t);
  ++t;
  readIterators(std::forward<U>(u)...);
}

template <typename T, typename... U> void readtImpl(T tBegin, T tEnd, U... u) {
  while (tBegin != tEnd) {
    readIterators(tBegin, u...);
  }
}

template <typename T, typename... U> std::istream &readt(T &&t, U &&...u) {
  readtImpl(t.begin(), t.end(), u.begin()...);
  return std::cin;
}

std::ostream &write() { return std::cout; }

std::ostream &writeln() {
  row++;
  column = 0;
  std::cout.put('\n');
  return std::cout;
}

template <typename T, typename... U,
          std::enable_if_t<IsWritableV<T>> * = nullptr>
std::ostream &write(T &&t, U &&...u) {
  if constexpr (!std::is_function_v<std::remove_reference_t<T>>) {
    if (column > 0 && !separator.empty()) {
      std::cout << separator;
    }

    column++;
  }

  std::cout << t;
  return write(std::forward<U>(u)...);
}

template <typename T, typename... U,
          std::enable_if_t<IsIterableV<T> && !IsWritableV<T>> * = nullptr>
std::ostream &write(T &&t, U &&...u) {
  ullong i = 0;

  for (auto it = t.begin(); it != t.end(); ++it, ++i) {
    if constexpr (IsIterable<decltype(*it)>::value) {
      if (i > 0) {
        writeln();
      }
    }

    write(*it);
  }

  return write(std::forward<U>(u)...);
}

template <typename... T> std::ostream &writeln(T &&...t) {
  write(std::forward<T>(t)...);
  return writeln();
}

void answer() {
  std::string S;
  llong T;
  read(S, T);

  llong x = 0, y = 0, q = 0;

  for (llong i = 0; i < S.size(); i++) {
    switch (S[i]) {
    case 'L':
      x--;
      break;
    case 'R':
      x++;
      break;
    case 'U':
      y++;
      break;
    case 'D':
      y--;
      break;
    case '?':
      q++;
      break;
    }
  }

  llong dist = std::abs(x) + std::abs(y);

  if (T == 1) {
    dist += q;
  } else {
    dist -= q;

    if (dist < 0) {
      dist = std::abs(dist % 2);
    }
  }

  writeln(dist);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  answer();
  return 0;
}