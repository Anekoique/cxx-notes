#include <iostream>
#include <valarray>

int main()
{
	double gpa[5] = {1, 2, 3, 4, 5};
	std::valarray<double> v1(gpa, 4);
	std::cout << v1.size() << std::endl;
	std::cout << v1.sum() << std::endl;
}
