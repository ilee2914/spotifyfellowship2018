#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int split(string &s, vector<int> &order, int low, int high) {
	int pivot = order[s[high]-'a'];
	int i = low - 1;
	
	for (int j = low; j <= high - 1; j++) {
		if (order[s[j]-'a'] == -1 || order[s[j]-'a'] <= pivot) {
			i++;
			char temp = s[j];
			s[j] = s[i];
			s[i] = temp;
		}
	}
	
	char temp = s[i + 1];
	s[i + 1] = s[high];
	s[high] = temp;
	return i + 1;
}

void quickSort(string &s, vector<int> &order, int low, int high) {
	if (low < high) {
		int index = split(s, order, low, high);
		quickSort(s, order, low, index - 1);
		quickSort(s, order, index + 1, high);
	}
}

void getOrderOfChars(vector<int> &order, string &t) {
	int orderCount = 0;
	for (unsigned int i = 0; i < t.size(); i++) {
		order[t[i]-'a'] = orderCount;
		orderCount++;
	}
}

//Assuming that if the character in s doesn't exist in t, then it will be placed at the beginning
void sortByString(string &s, string &t) {
	vector<int> order(26, -1);
	getOrderOfChars(order, t);
	quickSort(s, order, 0, s.size()-1);
	
	/*sort(s.begin(), s.end(), 
	[&](int a, int b) {
		if (order[a-'a'] == -1) {
			return false;
		} 
		return order[a - 'a'] < order[b - 'a'];
	});*/
	
}

int main(){
	string s = "weather";
	string t = "therapyw";
	
	cout << "String s : " << s << endl;
	cout << "String t : " << t << endl;
	sortByString(s, t);
	cout << "Result : " << s;
	return 0;
}
