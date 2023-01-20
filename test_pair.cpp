// pair::pair example
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout
#include "pair.hpp"

int main () {
	{
		std::cout << "=-=-=- test. Constructor =-=-=-" << std::endl;
		::pair <std::string,double> product1;
		::pair <std::string,double> product2 ("tomatoes",2.30);
		::pair <std::string,double> product3 (product2); 

		product1 = ::make_pair(std::string("lightbulbs"),0.99);

		product2.first = "shoes";
		product2.second = 39.90; 

		std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
		std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
		std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

		std::pair <std::string,double> std_product1;
		std::pair <std::string,double> std_product2 ("tomatoes",2.30);
		std::pair <std::string,double> std_product3 (std_product2);

		std_product1 = std::make_pair(std::string("lightbulbs"),0.99); 

		std_product2.first = "shoes";
		std_product2.second = 39.90; 

		std::cout << "The price of " << std_product1.first << " is $" << std_product1.second << '\n';
		std::cout << "The price of " << std_product2.first << " is $" << std_product2.second << '\n';
		std::cout << "The price of " << std_product3.first << " is $" << std_product3.second << '\n';
	}
	{
		std::cout << "=-=-=- test. make_fair() =-=-=-" << std::endl;
		::pair <std::string,int> planet, homeplanet;

		planet = ::make_pair("Earth",6371);

		homeplanet = planet;

		std::cout << "Home planet: " << homeplanet.first << '\n';
		std::cout << "Planet size: " << homeplanet.second << '\n';

		std::pair <std::string,int> std_planet, std_homeplanet;

		std_planet = std::make_pair("Earth",6371);

		std_homeplanet = std_planet;

		std::cout << "Home planet: " << std_homeplanet.first << '\n';
		std::cout << "Planet size: " << std_homeplanet.second << '\n';

	}
	{
		std::cout << "=-=-=- test. overloaded operator =-=-=-" << std::endl;

		::pair <std::string,double> product1 ("tomatoes",2.30);
		::pair <std::string,double> product2 ("a", 4);
		::pair <std::string,double> product3 ("tomatoes",5);

		std::pair <std::string,double> std_product1 ("tomatoes",2.30);
		std::pair <std::string,double> std_product2 ("a", 4);
		std::pair <std::string,double> std_product3 ("tomatoes",5);

		std::cout << (product1 == product3) << " " << (std_product1 == std_product3) << std::endl;
		std::cout << (product1 < product3) << " " << (std_product1 < std_product3) << std::endl;
		std::cout << (product1 >= product2) << " " << (std_product1 >= std_product2) << std::endl;
	}
}