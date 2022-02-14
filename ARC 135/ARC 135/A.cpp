#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll cal(ll X);

vector<pair<ll, ll>> v;
ll mod = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ll X;
	cin >> X;
	cout << cal(X) << "\n";
	return 0;
}

ll cal(ll X) {
	if (X <= 4) return X;
	ll X1 = X / 2, X2 = X / 2 + X % 2, result1 = 0, result2 = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (X2 == v[i].first) {
			result2 = v[i].second;
			break;
		}
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		if (X1 == v[i].first) {
			result1 = v[i].second;
			break;
		}
	}
	if (!result1) {
		if (X % 2 == 0) {
			result1 = cal(X1);
			v.push_back(make_pair(X1, result1));
		}
		else {
			result1 = cal(X1);
			v.push_back(make_pair(X1, result1));
		}
	}
	if (!result2) {
		if (X % 2 == 0) {
			result2 = result1;
		}
		else {
			result2 = cal(X2);
			v.push_back(make_pair(X2, result2));
		}
	}
	return (result1 * result2) % mod;
}