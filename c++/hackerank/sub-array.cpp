#include <iostream>
#include <vector>

using std::cout;
using std::cin;

int subArrayDivision(std::vector<int> s, int d, int m)
{
	std::vector<int> sums(s.size());
	int count_conc = 0;
	for(size_t i = 0; i < m; ++i)
		sums[0] += s[i]; 
	if(sums[0] == d)
		++count_conc;
	for(size_t i = m; i < s.size(); ++i)
	{
		sums[i - m + 1] += sums[i - m] + s[i] - s[i - m];
		if(sums[i - m + 1] == d)
			++count_conc;
	}
	return count_conc;
}






int main()
{
	int n; cin >> n;
	std::vector<int> s(n);
	for(size_t i = 0; i < n; ++i)
		cin >> s[i];
	int d; cin >> d;
	int m; cin >> m;
	cout << subArrayDivision(s, d, m) << "\n";

	return 0;
}
