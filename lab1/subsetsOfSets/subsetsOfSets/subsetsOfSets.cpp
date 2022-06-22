#include <iostream>
#include <vector>
#include <boost/timer.hpp>

using namespace std;

void search(int k, int n, vector<int> set, vector<size_t> subset) {
	if (k == n) 
	{
		//for (int i = 0; i < subset.size(); i++) {
		//	cout << subset[i];
		//}
		subset.resize(0);
		/*cout << endl;*/
	} 
	else 
	{
		subset.push_back(set[k]);
		search(k + 1, n, set, subset);
		subset.pop_back();
		search(k + 1, n, set, subset);
	}

}

int main() {
	boost::timer t;
	t.restart();

	int k = 10;
	vector<int> set(k);
	vector<size_t> subset;

	for (int i = 0; i < k; i++) 
	{
		set[i] = i + 1;
	}

	search(0, k, set, subset);

	double duration = t.elapsed();
	std::cout << duration << std::endl;

	return 0;
}