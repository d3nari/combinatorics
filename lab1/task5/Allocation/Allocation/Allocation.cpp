#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/timer.hpp>

void PrintVector(std::vector<size_t>& c, int k) {
	for (int i = k - 1; i >= 0; --i) {
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;
}


int main() {
	boost::timer t;
	t.restart();
	int n = 3;
	int k = 3;
	std::vector<size_t> c(n);
	c[0] = -1;

	for (int i = 1; i <= k; i++) { c[i] = i; }

	int m = 1;
	while (m != 0)
	{
		do
		{
			copy(c.begin() + 1, c.begin() + k + 1, std::ostream_iterator<int>(std::cout, " "));
			std::cout << "\n";
		} while (std::next_permutation(c.begin() + 1, c.begin() + k + 1));

	    m = k;
		while (c[m] == n - k + m) {
			m = m - 1;
		}
		c[m]++;
		for (int i = m + 1; i <= k; i++) {
			c[i] = c[i - 1] + 1;
		}

	}



	std::cout << std::endl;
	double duration = t.elapsed();
	std::cout << duration << std::endl;
}