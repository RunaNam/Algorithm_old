#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string check(string s) {
	int count = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			count++;
		else if (s[i] == ')')
			count--;
		if (count < 0)
			return ("NO");
	}
	if (count != 0)
		return("NO");
	else
		return("YES");
}


int main(void) {
	int a;
	cin >> a;
	while (a--) {
		string s;
		cin >> s;
		cout << check(s) << '\n';
	}
	return 0;
}