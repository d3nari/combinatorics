#include <iostream>
#include <vector>
#include <boost/timer.hpp>

void PrintVector(std::vector<size_t>& c, int k) {
	for (int i = 1; i <= k; ++i) {
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;
}


int main() {
	boost::timer t;
	t.restart();
	int n = 10;
	int k = 5;
	std::vector<size_t> c(k+1);

	c[0] = -1;
	for (int i = 1; i <= k; i++) { c[i] = i; }
	//PrintVector(c, k);
	std::cout << std::endl;

	int j = 1;
	while (j != 0) {
		PrintVector(c, k);
		j = k;
		
		while (c[j] == n - k + j) {
			j = j - 1;
		}
		c[j] = c[j] + 1;
		for (int i = j + 1; i <= k; ++i) {
			c[i] = c[i - 1] + 1;
		}
	} 


	std::cout << std::endl;
	double duration = t.elapsed();
	std::cout << duration << std::endl;
}