#include <cstdio>
#include <string>
#include <queue>
using namespace std;
int num;
priority_queue<int> q;

int main(void)
{
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int a;
		scanf("%d", &a);
		if (a == 0)
		{
			if (q.empty())
				printf("0\n");
			else
			{
				printf("%d\n", -q.top());
				q.pop();
			}
		}
		else
		{
			q.push(-a);
		}
	}
}