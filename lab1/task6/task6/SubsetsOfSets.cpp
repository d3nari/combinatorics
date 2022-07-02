#include <iostream>
#include <vector>
#include <boost/timer.hpp>
using namespace std;

vector<size_t> set, subset;

void gen(int m, int l, int n, int k)
{
	if(m == 0)
	{
		/*for (int i = 1; i < subset.size(); i++)
			cout << subset[i] << " ";
		cout << endl;*/
	}
	else

		for (int i = l; i <= n - m + 1; i++)
		{
			subset[k - m + 1] = set[i];
			gen(m - 1, i + 1, n, k);
		}
}



int main() 
{
	boost::timer t;
	t.restart();

	int n = 20;

	for (int i = 0; i <= n; i++)
		set.push_back(i);

	for (int k = 1; k <= n; k++) {

		for (int i = 0; i <= k; i++)
			subset.push_back(i);

		gen(k, 1, n, k);

		subset.clear();
	}

	double duration = t.elapsed();
	cout << duration << endl;

}