#include <iostream>

struct IntArray {
  size_t k;
  int * data;

  IntArray(int i);
  ~IntArray();

  void add(int i);
  int get(size_t id) const noexcept;
  int last() const noexcept;
  size_t size() const noexcept;
};

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
      int d = a.get(i);
      count += !(d % a.last());
    }
    std::cout << count << "\n";
  } catch (const std::exception & e) {
    return 2;
  }
}

IntArray::~IntArray()
{
  delete[] data;
}

IntArray::IntArray(int i) : data(new int[1]),
                            k(1)
{
  data[0] = i;
}

int IntArray::get(size_t id) const noexcept
{
  return data[id];
}

size_t IntArray::size() const noexcept
{
  return k;
}

int IntArray::last() const noexcept
{
  return get( size() - 1);
}

void IntArray::add(int i)
{
  int * temp = new int[size() + 1];
  for (size_t j = 0; j < size(); ++j) {
    temp[j] = get(i);
  }
  temp[size()] = i;
  delete[] data;
  data = temp;
  ++k;
}

