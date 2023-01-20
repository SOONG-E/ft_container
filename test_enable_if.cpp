#include <iostream>
#include <type_traits>
#include "enable_if.hpp"

template <class T>
typename ::enable_if<std::is_integral<T>::value,bool>::type
  is_odd (T i) {return bool(i%2);}

int main() {

  short int i = 1;

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(3) << std::endl;

  return 0;
}
