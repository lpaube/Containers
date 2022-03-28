#include <iostream>

int	main() {
	std::cout << std::endl;

	std::allocator<int> intAlloc;

	std::cout << "intAlloc.max_size(): " << intAlloc.max_size()
		<< std::endl;
	
	int* intArray = intAlloc.allocate(100);

	std::cout << "intArray[4]: " << intArray[4] << std::endl;

	intArray[4] = 2011;

	std::cout << "intArray[4]: " << intArray[4] << std::endl;

	intAlloc.deallocate(intArray, 100);

	std::cout << std::endl;

	std::allocator<double> doubleAlloc;
	std::cout << "doubleAlloc.max_size(): " << doubleAlloc.max_size() << std::endl;
	std::cout << "math: " << intAlloc.max_size() - doubleAlloc.max_size() << std::endl;
}