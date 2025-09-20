#include <iomanip>
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "../includes/easyfind.hpp"

#define SAMPLE_SIZE 10

int main( int argc, char** argv )
{
  ( void )argc;
  ( void )argv;

  // Vector
  std::vector<int> vectorNumbers;
  vectorNumbers.push_back(1);
  vectorNumbers.push_back(5);
  vectorNumbers.push_back(6);

  std::vector<int>::iterator vectorResult;

  for (int searchNumber = 0; searchNumber < SAMPLE_SIZE; searchNumber++) {
    try {
      vectorResult = easyfind(vectorNumbers, searchNumber);
      std::cout << "Found " << searchNumber
                << " in the vector container." << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << " of: " << searchNumber << std::endl;
    }
  }

  std::cout << std::endl;

  // List
  std::list<int> listNumbers;
  listNumbers.push_back(4);
  listNumbers.push_back(8);
  listNumbers.push_back(9);

  std::list<int>::iterator listResult;

  for (int searchNumber = 0; searchNumber < SAMPLE_SIZE; searchNumber++) {
    try {
      listResult = easyfind( listNumbers, searchNumber );
      std::cout << "Found " << searchNumber
                << " in the list container." << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << " of: " << searchNumber << std::endl;
    }
  }

  std::cout << std::endl;

  std::deque<int> dequeNumbers;
  dequeNumbers.push_back(3);
  dequeNumbers.push_back(6);
  dequeNumbers.push_back(9);

  std::deque<int>::iterator dequeResult;

  for ( int searchNumber = 0; searchNumber < SAMPLE_SIZE; searchNumber++ ) {
    try {
      dequeResult = easyfind(dequeNumbers, searchNumber);
      std::cout << "Found " << searchNumber
                << " in the list container." << std::endl;
    } catch (std::exception& e) {
      std::cout << e.what() << " of: " << searchNumber << std::endl;
    }
  }
  return 0;
}
