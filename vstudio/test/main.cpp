#include <iostream>

#include "AtomicInt32.h"

using namespace OS;

int main()
{
	AtomicInt32 i;
	std::cout << ++i << "\n";
	std::cout << ++i << "\n";
}
