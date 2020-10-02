#include <iostream>
#include <vector>



int main()
{
	std::vector<int> a{2, 3, 4, 3, 2, 2, 1, 2, 2};
	std::vector<int> b(a.begin() + 2, a.end() - 4);
	for(auto i : b)
		std::cout << i << " ";
	std::cout << "\n";
	return 0;

}
