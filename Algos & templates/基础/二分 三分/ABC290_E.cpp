#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0), B;
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector<vector<ll>>k(n + 1);
	vector<vector<ll>>pre(n + 1);
	for (ll i = 1; i <= n; i++)k[A[i]].push_back(i);
	for (ll i = 1; i <= n; i++) {
		if (not k[i].size())continue;
		pre[i].resize(k[i].size() + 5);
		pre[i][k[i].size() - 1] = n + 1 - k[i].back();
		for (ll j = k[i].size() - 2; j >= 0; j--)pre[i][j] = pre[i][j + 1] + n + 1 - k[i][j];
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ans += (n - i + 1) * (i / 2);
	}
	//cout << ans << endl;
	for (ll i = 1; i <= n; i++) {
		if (not k[i].size())continue;
		//cout << i << ": " << endl;
		for (ll j = 0; j < k[i].size(); j++) {
			ll sz1 = upper_bound(k[i].begin() + j + 1, k[i].end(), n + 1 - k[i][j]) - (k[i].begin() + j) - 1;
			ll idx = j + 1 + sz1;
			//cout << idx << endl;
			ans -= max(0ll, (sz1)) * k[i][j];
			if (idx >= k[i].size())continue;
			ans -= pre[i][idx];
			//cout << pre[i][idx + 1] << endl;
			//cout << ans << endl;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}