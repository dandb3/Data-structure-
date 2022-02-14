#include <iostream>
#include <algorithm>

using namespace std;

int lb(int target, int* mil2, int N);
void Bsearch(int serialNum, int N, int* mil2);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, order, idx, _add, mmin = 500000;
	cin >> N;
	int* mil = new int[N];
	int* mil2 = new int[N];
	cin >> mil[0];
	mil2[0] = mil[0];
	for (int i = 1; i < N; i++) {
		cin >> mil[i];
		mil2[i] = mil[i] + mil2[i - 1];
	}

	cin >> M;
	bool flag = true;
	while (M--) {
		cin >> order >> idx;
		if (order == 1) {
			cin >> _add;
			mmin = min(mmin, idx - 1);
			mil[idx - 1] += _add;
			flag = true;
		}
		else if (order == 2) {
			if (flag) {
				if (mmin == 0) {
					mil2[0] = mil[0];
					for (int i = mmin + 1; i < N; i++) {
						mil2[i] = mil[i] + mil2[i - 1];
					}
				}
				else {
					for (int i = mmin; i < N; i++) {
						mil2[i] = mil[i] + mil2[i - 1];
					}
				}
			}
			Bsearch(idx, N, mil2);
			flag = false;
		}
	}
	delete[] mil2;
	delete[] mil;
	return 0;
}

int lb(int target, int* mil2, int N) {
	int left = 0, right = N - 1, mid;
	while (left < right) {
		mid = left + right >> 1;
		if (target > mil2[mid]) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	return left + 1;
}

void Bsearch(int serialNum, int N, int* mil2)
{
	int first = 0;
	int last = N - 1;
	int mid;

	while (first <= last) {
		mid = (first + last) / 2;
		if (serialNum <= mil2[mid] && serialNum > mil2[mid - 1]) {
			std::cout << (mid + 1) << std::endl;
			break;
		}
		else
		{
			if (serialNum > mil2[mid]) {
				first = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
	}
}