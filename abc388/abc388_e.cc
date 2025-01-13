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

template <typename T>
struct IsIOManip
    : std::disjunction<std::is_function<std::remove_reference_t<T>>,
                       std::is_same<T, decltype(std::resetiosflags({}))>,
                       std::is_same<T, decltype(std::setiosflags({}))>,
                       std::is_same<T, decltype(std::setbase({}))>,
                       std::is_same<T, decltype(std::setfill(char{}))>,
                       std::is_same<T, decltype(std::setprecision({}))>,
                       std::is_same<T, decltype(std::setw({}))>> {};
template <typename T> inline constexpr bool IsIOManipV = IsIOManip<T>::value;

std::string separator = " ";
ullong column = 0;
ullong row = 0;

void setSeparator(std::string_view s) { separator = s; }

std::istream &read() { return std::cin; }

std::istream &readln(std::string &s) { return std::getline(std::cin, s); }

std::istream &read(std::ios_base &(*f)(std::ios_base &)) {
  return std::cin >> f;
}

std::istream &read(std::ios &(*f)(std::ios &)) { return std::cin >> f; }

std::istream &read(std::istream &(*f)(std::istream &)) { return std::cin >> f; }

template <typename T, std::enable_if_t<IsReadableV<T>> * = nullptr>
std::istream &read(T &&t) {
  return std::cin >> t;
}

template <typename T,
          std::enable_if_t<IsIterableV<T> && !IsReadableV<T>> * = nullptr>
std::istream &read(T &&t) {
  for (auto &&t_i : t) {
    read(t_i);
  }

  return std::cin;
}

template <typename T, typename... U> std::istream &read(T &&t, U &&...u) {
  read(t);
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
  ++row;
  column = 0;
  return std::cout.put('\n');
}

std::ostream &write(std::ios_base &(*f)(std::ios_base &)) {
  return std::cout << f;
}

std::ostream &write(std::ios &(*f)(std::ios &)) { return std::cout << f; }

std::ostream &write(std::ostream &(*f)(std::ostream &)) {
  return std::cout << f;
}

template <typename T, std::enable_if_t<IsIOManipV<T>> * = nullptr>
std::ostream &write(T &&t) {
  return std::cout << t;
}

template <typename T,
          std::enable_if_t<IsWritableV<T> && !IsIOManipV<T>> * = nullptr>
std::ostream &write(T &&t) {
  if (column > 0 && !separator.empty()) {
    std::cout << separator;
  }

  ++column;
  return std::cout << t;
}

template <typename T,
          std::enable_if_t<IsIterableV<T> && !IsWritableV<T>> * = nullptr>
std::ostream &write(T &&t) {
  ullong i = 0;

  for (auto it = t.begin(); it != t.end(); ++it, ++i) {
    if constexpr (IsIterableV<decltype(*it)>) {
      if (i > 0) {
        writeln();
      }
    }

    write(*it);
  }

  return std::cout;
}

template <typename T, typename... U> std::ostream &write(T &&t, U &&...u) {
  write(std::forward<T>(t));
  return write(std::forward<U>(u)...);
}

template <typename... T> std::ostream &writeln(T &&...t) {
  write(std::forward<T>(t)...);
  return writeln();
}

void writeIterators() {}

template <typename T, typename... U> void writeIterators(T &&t, U &&...u) {
  write(*t);
  ++t;
  writeIterators(std::forward<U>(u)...);
}

template <typename T, typename... U> void writetImpl(T tBegin, T tEnd, U... u) {
  for (ullong i = 0; tBegin != tEnd; ++i) {
    if (i > 0) {
      writeln();
    }

    writeIterators(tBegin, u...);
  }
}

template <typename T, typename... U> std::ostream &writet(T &&t, U &&...u) {
  writetImpl(t.begin(), t.end(), u.begin()...);
  return std::cout;
}

template <typename... T> std::ostream &writetln(T &&...t) {
  writet(std::forward<T>(t)...);
  return writeln();
}

void answer() {
  llong N;
  read(N);
  std::vector<llong> A(N);
  read(A);
  llong NHalf = N / 2;
  llong count = 0;

  for (llong i = 0, j = NHalf; i < NHalf && j < N; j++) {
    if (A[i] * 2 <= A[j]) {
      count++;
      i++;
    }
  }

  writeln(count);
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  answer();
  return 0;
}