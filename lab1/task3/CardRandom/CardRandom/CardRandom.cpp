#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> deck(36);
	for (int i = 0; i < 36; i++) {
		deck[i] = i + 1;
	}
	copy(deck.begin(), deck.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	for (int i = 0; i < 36; i++) {
		swap(deck[i], deck[rand() % 35]);
	}
	copy(deck.begin(), deck.end(), ostream_iterator<int>(cout, " "));
}