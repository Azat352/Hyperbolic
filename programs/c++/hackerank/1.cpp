#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}


int lcm(int a, int b)
{
	return std::abs(a * b) / gcd(a, b);
}



int getTotalX(std::vector<int> a, std::vector<int> b)
{
	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());
	int g = b[0];
	int l = 0;
	if(a.size() > 1)
		l = lcm(a[0], a[1]);
	else
		l = a[0];
	for(int i = 2; i < a.size(); ++i)
		l = lcm(l, a[i]);
	
	for(int i = 1; i < b.size(); ++i)
		g = gcd(g, b[i]);
	
	if(g % l == 0)
	{
		int count = 1;
		for(int i = 2; i <= g; ++i)
			if(g % (l * i) == 0)
				++count;
		return count;
	}
	else return 0;
}



int main()
{
	int m, n;
	std::cin >> m >> n;
	std::vector<int> a(m), b(n);
	for(int i = 0; i < m; ++i)
		std::cin >> a[i];
	for(int i = 0; i < n; ++i)
		std::cin >> b[i];
	std::cout << getTotalX(a, b) << "\n";
	return 0;
}
