#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
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

i64 W = 10;
i64 H = 10;

struct Cell {
  bool visited = false;
  i64 landID = -1;
};

std::vector<std::vector<Cell>> initialState() {
  std::vector<std::vector<Cell>> state(H);

  for (auto &&s : state) {
    s.resize(W);
  }

  return state;
}

std::vector<std::string> A(H);
std::vector<std::vector<Cell>> state;

bool isInside(i64 x, i64 y) { return x >= 0 && x < W && y >= 0 && y < H; }

bool markLand(i64 x, i64 y, i64 landID) {
  if (!isInside(x, y) || state[y][x].visited || A[y][x] != 'o') {
    return false;
  }

  state[y][x].visited = true;
  state[y][x].landID = landID;
  markLand(x - 1, y, landID);
  markLand(x + 1, y, landID);
  markLand(x, y - 1, landID);
  markLand(x, y + 1, landID);
  return true;
}

void addLand(i64 x, i64 y, std::unordered_set<i64> &lands) {
  if (!isInside(x, y)) {
    return;
  }

  if (A[y][x] == 'o') {
    lands.insert(state[y][x].landID);
  }
}

void getAdjacentLands(i64 x, i64 y, std::unordered_set<i64> &lands) {
  if (A[y][x] != 'x') {
    return;
  }

  addLand(x - 1, y, lands);
  addLand(x + 1, y, lands);
  addLand(x, y - 1, lands);
  addLand(x, y + 1, lands);
}

int main() {
  for (i64 i = 0; i < H; i++) {
    std::cin >> A[i];
  }

  state = initialState();
  i64 nextID = 0;

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      if (markLand(x, y, nextID)) {
        nextID++;
      }
    }
  }

  for (i64 y = 0; y < H; y++) {
    for (i64 x = 0; x < W; x++) {
      std::unordered_set<i64> lands;
      getAdjacentLands(x, y, lands);

      if (lands.size() == nextID) {
        std::cout << "YES" << std::endl;
        goto exit;
      }
    }
  }

  std::cout << "NO" << std::endl;
exit:
  return 0;
}