#include "singleton.h"
#include <iostream>

int main() {
	Singleton& s1 = Singleton::getInstance();
	Singleton& s2 = Singleton::getInstance();

	std::cout << &s1 << std::endl << &s2 << std::endl;

	return 0;
}
