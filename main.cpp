#include <iostream>
#include <fstream>
#include "IntMatrix.h"


int main(int argc, char ** argv)
{
  std::ifstream input(argv[1]);
  IntMatrix matrix;
  try {
    matrix.read(input);
  } catch (std::invalid_argument &e) {
    return 1;
  } catch (std::bad_alloc &e) {
    return 2;
  }
  input.close();

  while (std::cin) {
    int command = 0, p1 = 0, p2 = 0;
    std::cin >> command >> p1 >> p2;
    if (std::cin.fail() && !std::cin.eof()) {
      return 1;
    }
    if (command == 1) {
      matrix.insert_row(p1, p2);
    } else if (command == 2) {
      matrix.insert_column(p1, p2);
    } else if (command == 3) {
      matrix.insert_row(p1);
      matrix.insert_column(p2);
    }
  }
}

