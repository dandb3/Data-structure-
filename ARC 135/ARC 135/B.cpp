#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//void find1(vector<int> v, vector<int>& w, int N, int num);
//void find2(vector<int> v, vector<int>& w, int num);

bool flag1, flag2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, mmin = 2000000000, idx = 0;
	cin >> N;
	vector<int> v(N);
	vector<int> w(N + 2);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (mmin > v[i]) {
			mmin = v[i];
			idx = i;
		}
	}
	if (idx == 0) flag2 = true;
	for (int i = 0; i <= v[idx]; i++) {
		for (int j = 0; j <= v[idx] - i; j++) {
			w[idx] = i;
			w[idx + 1] = j;
			for (int k = idx; k < N; k++) {
				if (v[k] >= w[k] + w[k + 1]) {
					w[k + 2] = v[k] - w[k] - w[k + 1];
				}
				else break;
				if (k == N - 1) {
					flag1 = true;
				}
			}
			for (int k = idx - 1; k >= 0; k--) {
				if (v[k] >= w[k + 1] + w[k + 2]) {
					w[k] = v[k] - w[k + 1] - w[k + 2];
				}
				else break;
				if (k == 0) {
					flag2 = true;
				}
			}
			if (flag1 && flag2) break;
		}
		if (flag1 && flag2) break;
	}
	if (!(flag1 && flag2)) cout << "No" << "\n";
	else {
		cout << "Yes" << "\n";
		for (int i = 0; i < N + 2; i++) {
			cout << w[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}
/*
void find1(vector<int> v, vector<int>& w, int N, int num) {
	if (num == N) {
		//int _size = w.size();
		//cout << "Yes" << "\n";
		//for (int i = 0; i < _size; i++) {
		//	cout << w[i] << " ";
		//}
		//cout << "\n";
		flag1 = true;
		return;
	}
	if (v[num] >= w[num] + w[num + 1]) {
		w[num + 2] = v[num] - w[num] - w[num + 1];
		find1(v, w, N, num + 1);
	}
	return;
}

void find2(vector<int> v, vector<int>& w, int num) {
	if (num == -1) {
		int _size = w.size();
		cout << "Yes" << "\n";
		for (int i = 0; i < _size; i++) {
			cout << w[i] << " ";
		}
		cout << "\n";
		flag2 = true;
		return;
	}
	if (v[num] >= w[num + 1] + w[num + 2]) {
		w[num] = v[num] - w[num + 1] - w[num + 2];
		find2(v, w, num - 1);
	}
	return;
}*/