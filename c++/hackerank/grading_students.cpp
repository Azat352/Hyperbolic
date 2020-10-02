#include <iostream>
#include <vector>

using std::cout;
using std::cin;

std::vector<int> gradingStudents(std::vector<int> grades)
{
	for(size_t i = 0; i < grades.size(); ++i)
	{
		if( 5 - grades[i] % 5 < 3 && grades[i] >= 38)
			grades[i] += 5 - grades[i] % 5;
	}
	return grades;
}

int main()
{
	int n; cin >> n;
	std::vector<int> grades(n);
	for(size_t i = 0; i < n; ++i)
		cin >> grades[i];
	std::vector<int> rounded_grades = gradingStudents(grades);
	for(auto i : rounded_grades)
		cout << i << "\n";
	return 0;
}
