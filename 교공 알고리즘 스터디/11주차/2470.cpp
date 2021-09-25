#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	int n;
	int left, right;
	vector<int> v;

	int min;
	pair<int, int> min_pair;

	scanf("%d", &n);
	while (n--) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	

	sort(v.begin(), v.end());
	// 좌우, min pair, min값 초기화
	left = 0; right = v.size() - 1;
	min = abs(v[left] + v[right]);
	min_pair.first = v[left];
	min_pair.second = v[right];

	while (left < right) {
		int sum = v[left] + v[right];

		if (abs(sum) < min) {
			min = abs(sum);
			min_pair.first = v[left];
			min_pair.second = v[right];
		}

		if (sum == 0) {
			break;
		}
		else if (sum > 0) {
			right--;
		}
		else {
			left++;
		}
	}

	printf("%d %d", min_pair.first, min_pair.second);

}