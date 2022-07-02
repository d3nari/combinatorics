#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> original, composed;
int n;


int findMin()
{
	for (int i = 1; i < original.size(); i++)
	{
		if (original[0] > original[i] and i != original.size() - 1) 
		{
			return i;
		}
	}
	return 0;
}

void permutation(vector<int> original)
{
	sort(original.begin(), original.end());
	do
	{
		copy(original.begin(), original.end(), ostream_iterator<size_t>(cout, " "));
		cout << endl;
	} while (next_permutation(original.begin(), original.end()));
}

int main()
{
	cout << "Enter a number: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		original.push_back(1);
	}

	copy(original.begin(), original.end(), ostream_iterator<size_t>(cout, " "));
	cout << endl;
	
	
	while (original[0] != n)
	{
		int i = findMin();
		original[i] += 1;
		original[original.size()-1] -= 1;

		if (original[original.size() - 1] == 0)
		{
			original.pop_back();
		}

		composed = original;
		permutation(composed);
	}



}
