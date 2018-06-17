#include <iostream>
#include <vector>

using namespace std;

int changePossiblities(int amount, vector<int> denominations) {
	vector<int> storedValues(amount+1, 0);
	storedValues[0] = 1;
	for (unsigned int i = 0; i < denominations.size(); i++) {
		for (int j = 1; j <= amount; j++) {
			if (j >= denominations[i]) {
				storedValues[j] += storedValues[j-denominations[i]];
			}
		}
	}
	return storedValues[storedValues.size()-1];
}

int main() {
	int amount = 100;
	vector<int> d{1, 2, 5};
	cout << "Amount : " << amount << endl;
	cout << "Denominations : ";
	for (int i : d) {
		cout << i << " ";
	}
	cout << endl;
	cout << "Possiblities : ";
	cout << changePossiblities(amount, d);
	return 0;
}