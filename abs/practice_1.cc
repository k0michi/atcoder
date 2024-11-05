#include <cstdint>
#include <iostream>
#include <string>

int main() {
  int32_t a, b, c;
  std::string s;
  std::cin >> a >> b >> c >> s;
  std::cout << (a + b + c) << ' ' << s << std::endl;
  return 0;
}