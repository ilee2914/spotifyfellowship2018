#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

string decodeHelper(string &s, unsigned int &i) {
	string result = "";
	for (; i < s.size(); i++) {
		if (isalpha(s[i])) {
			result += s[i];
		} else if (isdigit(s[i])) {
			int num = s[i]-'0';
			while(i+1 < s.size() && isdigit(s[i+1])) {
				i++;
				num *= 10;
				num += (s[i]-'0');
			}
			i++;
			string decoded = decodeHelper(s, i);
			for (int j = 0; j < num; j++) {
				result += decoded;
			}
		} else if (s[i] == ']') {
			return result;
		}
	}
	return result;
}
string decodeString(string s) {
	unsigned int i = 0;
	return decodeHelper(s, i);
}

// Assuming there are no stray [ or ] symbols
// Assuming that the string consists only of alphanumeric characters
int main() {
	string s = "4[fe2[5[a]x]asdc9[ab]]";
	cout << "Encoded string : " << s << endl;
	cout << "Decoded string : " << decodeString(s);
	return 0;
}