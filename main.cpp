#include <iostream>
#include <fstream>
#include "IntMatrix.h"
#include "IntMatrix.h"


int main(int argc, char ** argv)
{
  std::ifstream input(argv[1]);
  std::cout << input.is_open() << " " << argv[1] << "\n";
  IntMatrix matrix;
  try {
    matrix.read(input);
  } catch (std::invalid_argument & e) {
    return 1;
  } catch (std::bad_alloc & e) {
    return 2;
  }
  input.close();
  matrix.print(std::cout);

  while (std::cin) {
    int command = 0;
    size_t p1 = 0, p2 = 0;
    std::cin >> command;
    std::cin >> p1 >> p2;
    if (std::cin.fail() && !std::cin.eof()) {
      return 1;
    }
    if (command == 2) {
      if (p1 > matrix.cols()) {
        std::cerr << "bad column id" << "\n";
        return 3;
      }
      matrix.insert_column(p1, p2);
    } else if (command == 3) {
      if (p1 > matrix.rows()) {
        std::cerr << "bad row id" << "\n";
        return 3;
      } else if (p2 > matrix.cols()) {
        std::cerr << "bad column id" << "\n";
        return 3;
      }
      matrix.insert_row(p1);
      matrix.insert_column(p2);
    } else {
      std::cerr << "bad command" << "\n";
      return 3;
    }
    matrix.print(std::cout);
  }
}
