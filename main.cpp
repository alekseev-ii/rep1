#include <iostream>

struct IntArray {
  size_t size;
  void add(int next);
  int get(size_t id) const;
  size_t get_size() const;
}

int main() {
  int next = 0;
  std::cin >> next;
  IntArray a;
  a.add(next);

  while (std::cin >> next) {
    a.add(next);
  }
  if (std::cin.fail()) {
    return 1;
  }

  for (size_t i = 0ull; i < a.size(); ++i) {
    int d = a.get(i)
  }
}
