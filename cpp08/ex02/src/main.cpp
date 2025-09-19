/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rapcampo <rapcampo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 13:54:43 by rapcampo          #+#    #+#             */
/*   Updated: 2025/09/19 19:10:27 by rapcampo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MutantStack.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define SAMPLE_SIZE 20

void subjectTest();
template <typename T> void aditionalTest();
template <typename T> void emptyTest(T &cont);
template <typename T> void sortTest(T &cont);
template <typename T> void reverseTest(T &cont);
template <typename T> void deletionTest(T &cont);


int main(){
  std::srand(std::time(0));
  subjectTest();
  std::cout << GRN "\n :: [Test] vector test ::" RST << std::endl;
  aditionalTest<std::vector<int> >();
 std::cout << YLW "\n :: [Test] list test ::" RST << std::endl;
  aditionalTest<std::list<int> >();
  std::cout << RED "\n :: [Test] MutantStack test ::" RST << std::endl;
  aditionalTest<MutantStack<int> >();
  std::cout << RED "\n :: [Test] deque test ::" RST << std::endl;
  aditionalTest<std::deque<int> >();
}

static int randomizer(){
  return std::rand() % std::numeric_limits<int>::max(); 
}

template <typename T>
void aditionalTest(){
  T container;
  T toDelete;

  emptyTest(container);
  sortTest(container);
  reverseTest(container);
  deletionTest(toDelete);
}

template <typename T>
static void contSort(T& cont){
  std::sort(cont.begin(), cont.end());
}

template <typename T>
static void contSort(std::list<T>& cont){
  cont.sort();
}

template <typename T>
void sortTest(T &cont){
  std::cout << PRP "\n *** [Test] sort test ***" RST << std::endl;
  for (unsigned int i = 0; i < SAMPLE_SIZE; i++){
    cont.push_back(randomizer());
  }
  std::cout << "generated numbers" << std::endl;
  for (typename T::iterator it = cont.begin(); it != cont.end(); it++){
    std::cout << *it << "\n";
  }
  std::cout << std::endl;
  contSort(cont);
  std::cout << "\n" RED "--- after sorting ---" RST << std::endl;
  for (typename T::iterator it = cont.begin(); it != cont.end(); it++){
    std::cout << *it << "\n";
  }
  std::cout << std::endl;
}

template <typename T>

void emptyTest(T &cont){
  std::cout << GRN "\n *** [Test] empty test ***" RST << std::endl;
  std::cout << "size of container: " << cont.size() << std::endl;

  if (cont.begin() == cont.end())
    std::cout << "Container is empty! this is correct" << std::endl;
  else
    std::cout << "Container is not empty or command did not work!" << 
      "this is not correct" << std::endl;
}

template <typename T>
void reverseTest(T &cont){
  std::cout << CYN "\n *** [Test] reverse test ***" RST << std::endl;
  for (unsigned int i = 0; i < SAMPLE_SIZE; i++){
    cont.push_back(randomizer());
  }
  contSort(cont);
  typename T::reverse_iterator rit = cont.rbegin();
  std::cout << "\n" RED "--- after sorting ---" RST << std::endl;
  for (; rit != cont.rend(); rit++){
    std::cout << "reversed is: "<< *rit << "\n";
  }
  std::cout << std::endl;
  std::reverse(cont.begin(), cont.end());
  rit = cont.rbegin();
  std::cout << "\n" BLK "--- after reverting back---" RST << std::endl;
  for (; rit != cont.rend(); rit++){
    std::cout << "unreversed is: "<< *rit << "\n";
  }
  std::cout << std::endl;
}

template <typename T>
void deletionTest(T &cont){
  std::cout << RED "\n *** [Test] deletion test ***" RST << std::endl;
  unsigned int i;
  for (i = 0; i < SAMPLE_SIZE; i++){
    cont.push_back(randomizer());
  }
  std::cout << "\n" RED "--- before deletion ---" RST << std::endl;
  std::cout << "Current container size: " << cont.size() << std::endl;

  while (i-- > 0){
    std::cout << cont.back() << std::endl;
    cont.pop_back();
  }
  std::cout << "\n" RED "--- after deletion ---" RST << std::endl;
  std::cout << "Current container size: " << cont.size() << std::endl;
}

void subjectTest( )
{
  std::cout << "\n  [Test] Subject test ::" << std::endl;

  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);

  std::cout << mstack.top() << std::endl;

  mstack.pop();

  std::cout << mstack.size() << std::endl;

  mstack.push(3);
  mstack.push(5);
  mstack.push(737);
  //[...]
  mstack.push(0);

  MutantStack<int>::iterator it = mstack.begin();
  MutantStack<int>::iterator ite = mstack.end();

  ++it;
  --it;
  while (it != ite)
  {
    std::cout << *it << std::endl;
    ++it;
  }
  std::stack<int> s(mstack);
}
