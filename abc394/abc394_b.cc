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
#include <numbers>
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

using llong = long long;
using ullong = unsigned long long;

using namespace std::literals;

template <typename T, typename = void> struct IsIterable : std::false_type {};
template <typename T>
struct IsIterable<T, std::void_t<typename std::decay_t<T>::iterator>>
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

template <typename T, typename U = std::decay_t<T>>
struct IsIOManip
    : std::disjunction<std::is_function<U>,
                       std::is_same<U, decltype(std::resetiosflags({}))>,
                       std::is_same<U, decltype(std::setiosflags({}))>,
                       std::is_same<U, decltype(std::setbase({}))>,
                       std::is_same<U, decltype(std::setfill(char{}))>,
                       std::is_same<U, decltype(std::setprecision({}))>,
                       std::is_same<U, decltype(std::setw({}))>> {};
template <typename T> inline constexpr bool IsIOManipV = IsIOManip<T>::value;

template <typename T, typename = void> struct IsTupleLike : std::false_type {};
template <typename T>
struct IsTupleLike<
    T, std::void_t<decltype(std::tuple_size<std::decay_t<T>>::value)>>
    : public std::true_type {};
template <typename T>
inline constexpr bool IsTupleLikeV = IsTupleLike<T>::value;

std::string separator = " ";
ullong column = 0;
ullong row = 0;
bool flushEnabled = false;

void setSeparator(std::string_view s) { separator = s; }

void setFlushEnabled(bool enabled) { flushEnabled = enabled; }

std::istream &read() { return std::cin; }

std::istream &readln(std::string &s) { return std::getline(std::cin, s); }

std::istream &read(std::ios_base &(*f)(std::ios_base &)) {
  return std::cin >> f;
}

std::istream &read(std::ios &(*f)(std::ios &)) { return std::cin >> f; }

std::istream &read(std::istream &(*f)(std::istream &)) { return std::cin >> f; }

template <typename T, std::enable_if_t<IsReadableV<T &>> * = nullptr>
std::istream &read(T &t) {
  return std::cin >> t;
}

template <typename T, size_t N = 0,
          std::enable_if_t<IsTupleLikeV<T &> && !IsReadableV<T &>> * = nullptr>
std::istream &read(T &t);

template <typename T,
          std::enable_if_t<IsIterableV<T &> && !IsReadableV<T &>> * = nullptr>
std::istream &read(T &t) {
  for (auto &&t_i : t) {
    read(t_i);
  }

  return std::cin;
}

template <typename T, size_t N,
          std::enable_if_t<IsTupleLikeV<T &> && !IsReadableV<T &>> *>
std::istream &read(T &t) {
  if constexpr (std::tuple_size_v<std::decay_t<T>> != N) {
    read(std::get<N>(t));
    return read<T &, N + 1>(t);
  } else {
    return std::cin;
  }
}

template <typename T, typename... U> std::istream &read(T &t, U &...u) {
  read(t);
  return read(u...);
}

std::ostream &write() { return std::cout; }

std::ostream &writeln() {
  ++row;
  column = 0;

  if (flushEnabled) {
    return std::cout.put('\n').flush();
  } else {
    return std::cout.put('\n');
  }
}

std::ostream &write(std::ios_base &(*f)(std::ios_base &)) {
  return std::cout << f;
}

std::ostream &write(std::ios &(*f)(std::ios &)) { return std::cout << f; }

std::ostream &write(std::ostream &(*f)(std::ostream &)) {
  return std::cout << f;
}

template <typename T, std::enable_if_t<IsIOManipV<T &&>> * = nullptr>
std::ostream &write(T &&t) {
  return std::cout << t;
}

template <typename T,
          std::enable_if_t<IsWritableV<T &&> && !IsIOManipV<T &&>> * = nullptr>
std::ostream &write(T &&t) {
  if (column > 0 && !separator.empty()) {
    std::cout << separator;
  }

  ++column;
  return std::cout << t;
}

template <
    typename T, size_t N = 0,
    std::enable_if_t<IsTupleLikeV<T &&> && !IsWritableV<T &&>> * = nullptr>
std::ostream &write(T &&t);

template <typename T,
          std::enable_if_t<IsIterableV<T &&> && !IsWritableV<T &&>> * = nullptr>
std::ostream &write(T &&t) {
  ullong i = 0;

  for (auto it = t.begin(); it != t.end(); ++it, ++i) {
    if constexpr (IsIterableV<decltype(*it)> || IsTupleLikeV<decltype(*it)>) {
      if (i > 0) {
        writeln();
      }
    }

    write(*it);
  }

  return std::cout;
}

template <typename T, size_t N,
          std::enable_if_t<IsTupleLikeV<T &&> && !IsWritableV<T &&>> *>
std::ostream &write(T &&t) {
  if constexpr (std::tuple_size_v<std::decay_t<T>> != N) {
    write(std::get<N>(t));
    return write<T &&, N + 1>(std::forward<T>(t));
  } else {
    return std::cout;
  }
}

template <typename T, typename... U> std::ostream &write(T &&t, U &&...u) {
  write(std::forward<T>(t));
  return write(std::forward<U>(u)...);
}

template <typename... T> std::ostream &writeln(T &&...t) {
  write(std::forward<T>(t)...);
  return writeln();
}

void answer() {
  llong N;
  read(N);
  std::vector<std::string> S(N);
  read(S);
  std::sort(S.begin(), S.end(),
            [](auto &&a, auto &&b) { return a.size() < b.size(); });

  setSeparator("");
  for (auto &&S_i : S) {
    write(S_i);
  }
  writeln();
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  answer();
  return 0;
}