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
  if (!std::cin) {
    return 1;
  }
  IntArray a;
  a.add(next);


  for (size_t i = 0ull; i < a.size(); ++i) {
    int d = a.get(i)
  }
}
