#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

void convert(int num, int base)
{
	if (num == 0)
		return;
	convert(num / base, base);
	printf("%d ", num % base);
}

int main(void)
{
	int a, b, count;
	int num = 0;
	scanf("%d %d", &a, &b);
	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		int n;
		scanf("%d", &n);
		num += pow(a, count - i - 1) * n;
	}
	convert(num, b);
	return 0;
}