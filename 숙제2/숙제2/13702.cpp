#include <iostream>
#include <algorithm>
#define _MAX 2147483647

typedef long long ll;
using namespace std;

int find(int a, int N, int* mak);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	int* mak = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> mak[i];
	}
	cout << find(K, N, mak) << "\n";
	delete[] mak;
	return 0;
}

int find(int K, int N, int* mak) {
	int left = 0, right = _MAX;
	ll mid;
	while (left < right) {
		mid = (static_cast<ll>(left) + right) / 2 + (left + right) % 2;
		ll result = 0;
		for (int i = 0; i < N; i++) {
			result += mak[i] / mid;
		}
		if (result >= K) {
			left = mid;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}