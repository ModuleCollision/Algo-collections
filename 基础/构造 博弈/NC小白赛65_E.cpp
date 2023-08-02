#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const ll inf = 0X3F3F3F3F;
const int N = 1000010;
int a[N];
int b[N];
ll lg[maxn], f[maxn], f_sum[maxn], n, k;
signed main() {
	lg[0] = 0;
	lg[1] = 0;
	std::cin >> n >> k;
	ll sum = 0;
	for (ll i = 2; i <= 1e6; i++) {
		lg[i] = lg[i >> 1] + 1;
	}
	//cout << lg[33] << endl;
	for (ll i = 2; i <= n; i++) {
		f[i] = lg[i - 1] + 1;
	}
	for (ll i = 2; i <= n; i++) {
		sum += (lg[i - 1] + 1);
	}
	if (sum < k) {
		cout << -1;
		return 0;
	}
	vector<ll>ans1, ans2;
	for (ll i = n; i >= 1; i--) {
		if (k >= f[i]) {
			ans1.push_back(i);
			k -= f[i];
		} else {
			ans2.push_back(i);
		}
	}
	reverse(ans2.begin(), ans2.end());
	for (auto c : ans1) {
		cout << c << " ";
	}
	for (auto c : ans2) {
		cout << c << " ";
	}
	return 0;
}