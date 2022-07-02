#include <iostream>
#include <vector>
#include <boost/timer.hpp>
using namespace std;

int main() {
	//Инициализация
	int x = 0;
	cout << "Enter count of numbers: ";
	cin >> x;

	int m = x + 1;
	vector<size_t> n(x+2);
	vector<size_t> p(x+1);
	vector<int> d(x+1);

	boost::timer t;
	t.restart();

	//Заполнение начальных значений
	for (int i = 0; i < x+1; i++) { n[i] = i; p[i] = i; d[i] = -1; }
	n[x + 1] = x + 1;
	n[0] = x + 1;
	d[1] = 0;
	d[0] = 0;

	copy(n.begin(), n.end(), ostream_iterator<size_t>(cout, " "));
	cout << endl;

	copy(p.begin(), p.end(), ostream_iterator<size_t>(cout, " "));
	cout << endl;

	copy(d.begin(), d.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	
	while (m != 1) {
		copy(n.begin(), n.end(), ostream_iterator<size_t>(cout, " "));
		cout << endl;
		m = x;
		while (n[p[m] + d[m]] > m) {
			d[m] = -d[m];
			m--;
		}
		swap(n[p[m]], n[p[m] + d[m]]);
		swap(p[n[p[m]]], p[m]);
	} 

	cout << endl;
	double duration = t.elapsed();
	std::cout << duration << std::endl;
}