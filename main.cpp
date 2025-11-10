#include <iostream>

struct IntArray {
  size_t size;
  int * data;

  IntArray(int n);
  ~IntArray();

  void add(int next);
  int get(size_t id) const;
  int last() const;
  size_t get_size() const;
}

int main()
{
  int next = 0;
  std::cin >> next;
  try {
    IntArray a(next);

    while (std::cin >> next) {
      a.add(next);
    }
    if (std::cin.fail() && !std::cin.eof()) {
      return 1;
    } else if (std::cin.eof()) {
      return 1;
    }

    size_t count = 1ull;

    for (size_t i = 0ull; i < a.size() - 1; ++i) {
      int d = a.get(i)
      count += !(d % a.last());
    }
    std::cout << count << "\n";
  } catch (const std::exception & e) {
    return 2;
  }
}


