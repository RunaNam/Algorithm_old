#include <iostream>
#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

void reverse(string s) {
	int count;
	stack <char>s_new;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ' || s[i]=='\n') {
			while (!s_new.empty()) {
				cout << s_new.top();
				s_new.pop();
			}
			cout << s[i];
		}
		else
		{
			s_new.push(s[i]);
		}
	}
	while (!s_new.empty()) {
		cout << s_new.top();
		s_new.pop();
	}
	printf("\n");

}

int main(void) {
	int a;
	string s;
	cin >> a;
	cin.ignore();

	while (a--) {
		getline(cin, s);
		reverse(s);
	}
}