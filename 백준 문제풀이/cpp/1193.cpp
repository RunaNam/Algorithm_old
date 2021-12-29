#include <iostream>
#include <stdio.h>
using namespace std;


int main(void) {
	int a, b, x, y;

	cin >> a;
	b = 1;

	while (a > b) {
		a -= b++;
	}

	if (b % 2 == 1) {
		x = b;
		y = 1;
		while (a > 1) {
			x--;
			y++;
			a--;
		}
	}

	else {
		x = 1;
		y = b;
		while (a> 1) {
			x++;
			y--;
			a--;
		}
	}

	printf("%d/%d", x, y);

}
