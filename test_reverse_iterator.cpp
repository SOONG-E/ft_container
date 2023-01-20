#include <iostream>     
#include <iterator>
#include <vector>  
#include <map> 

#include "reverse_iterator.hpp"

int main () {
  std::vector<int> myvector;
  for (int i=0; i<10; i++) myvector.push_back(i);

  typedef std::vector<int>::iterator iter_type;

{
	std::cout << "=-=-=-=-= test : operator * =-=-=-=-=" << std::endl;
  ::reverse_iterator<iter_type> rev_end (myvector.begin());
  ::reverse_iterator<iter_type> rev_begin (myvector.end());

  std::reverse_iterator<iter_type> std_rev_end (myvector.begin());
  std::reverse_iterator<iter_type> std_rev_begin (myvector.end());

  std::cout << *rev_end << " " << *std_rev_end << " " << *myvector.begin() << std::endl;
  std::cout << *rev_begin << " " << *std_rev_begin << " " << *myvector.end() << std::endl;
}

{
	std::cout << "=-=-=-=-= test : operator + =-=-=-=-=" << std::endl;
	::reverse_iterator<iter_type> rev_it(myvector.begin());
  	std::reverse_iterator<iter_type> std_rev_it(myvector.begin());

  std::cout << "The fourth element from the end is: " << *(rev_it + 3) << '\n';
  std::cout << "The fourth element from the end is: " << *(std_rev_it + 3) << '\n';
}
{
	std::cout << "=-=-=-=-= test : operator >, <, ++ =-=-=-=-=" << std::endl;
	  iter_type from (myvector.begin()); 
  	iter_type until (myvector.end());

  	::reverse_iterator<iter_type> rev_until (from); 
  	::reverse_iterator<iter_type> rev_from (until); 

	std::reverse_iterator<iter_type> std_rev_until (from); 
  	std::reverse_iterator<iter_type> std_rev_from (until); 

	std::cout << (rev_until > rev_from) << std::endl;	
	std::cout << (std_rev_until > std_rev_from) << std::endl;	

	std::cout << (rev_until < rev_from) << std::endl;	
	std::cout << (std_rev_until < std_rev_from) << std::endl;	

	while (rev_from != rev_until) {
		std::cout << ' ' << *rev_from;
		++rev_from;
	}
	std::cout << '\n';
	while (std_rev_from != std_rev_until) {
		std::cout << ' ' << *std_rev_from;
		++std_rev_from;
	}

	std::cout << '\n';

}
{
	std::cout << "=-=-=-=-= test : operator += =-=-=-=-=" << std::endl;
	::reverse_iterator<iter_type> rev_iterator(myvector.end());
	std::reverse_iterator<iter_type> std_rev_iterator(myvector.end());

  rev_iterator += 2;
  std_rev_iterator += 2;

  std::cout << "The third element from the end is: " << *rev_iterator<<" " << *std_rev_iterator << '\n';
}
{
	std::cout << "=-=-=-=-= test : operator -> =-=-=-=-=" << std::endl;

  std::map<int,std::string> numbers;
  numbers.insert (std::make_pair(1,"one"));
  numbers.insert (std::make_pair(2,"two"));
  numbers.insert (std::make_pair(3,"three"));

  typedef std::map<int,std::string>::iterator map_iter;

	::reverse_iterator<map_iter> rev_end (numbers.begin());
  ::reverse_iterator<map_iter> rev_iterator (numbers.end());

  for ( ; rev_iterator != rev_end ; ++rev_iterator )
    std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';

  std::reverse_iterator<map_iter> std_rev_end (numbers.begin());
  std::reverse_iterator<map_iter> std_rev_iterator (numbers.end());

  for ( ; std_rev_iterator != std_rev_end ; ++std_rev_iterator )
    std::cout << std_rev_iterator->first << ' ' << std_rev_iterator->second << '\n';

}
{
	std::cout << "=-=-=-=-= test : operator [] =-=-=-=-=" << std::endl;
  ::reverse_iterator<iter_type> rev_iterator(myvector.end());
  std::reverse_iterator<iter_type> std_rev_iterator(myvector.end());

  std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
  std::cout << "The fourth element from the end is: " << std_rev_iterator[3] << '\n';
}
{
	std::cout << "=-=-=-=-= test : base() =-=-=-=-=" << std::endl;
	::reverse_iterator<iter_type> rev_end (myvector.begin());
  ::reverse_iterator<iter_type> rev_begin (myvector.end());

  std::cout << "myvector:";
  for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  	std::reverse_iterator<iter_type> std_rev_end (myvector.begin());
  std::reverse_iterator<iter_type> std_rev_begin (myvector.end());

  std::cout << "myvector:";
  for (iter_type it = std_rev_end.base(); it != std_rev_begin.base(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
  return 0;
}

