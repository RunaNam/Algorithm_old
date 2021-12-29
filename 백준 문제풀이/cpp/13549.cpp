#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 100001

int n, k;
bool v[MAX][3];// -1, 1, 2순서


int bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(n, 0));

	while (!q.empty()) {
		int pos = q.front().first;
		int c = q.front().second;

		if (pos == k)
			return c;

		q.pop();

		if (pos * 2 < MAX && v[pos][2] == false) {
			q.push(make_pair(pos * 2, c));
			v[pos][2] = true;
		}
		if (0 < pos && v[pos][0] ==false) {
			q.push(make_pair(pos - 1, c + 1));
			v[pos][0] = true;
		}
		if (pos + 1 <= MAX && v[pos][1] == false) {
			q.push(make_pair(pos + 1, c + 1));
			v[pos][1] = true;
		}

	}

}



int main()
{
	scanf("%d %d", &n, &k);
	printf("%d", bfs());
}