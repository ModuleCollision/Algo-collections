#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; cin >> n;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector<ll>ans(n + 5, 0);
	vector<bool>vis(n + 5, 0);
	ll idx = max_element(A.begin() + 1, A.begin() + 1 + n) - A.begin();
	ans[1] = idx; vis[idx] = 1;
	ll k = 0;
	for (ll i = 0; A[idx] >> i; i++) {
		k = i;
	}
	vector<vector<ll>>sk(35);
	for (ll i = 2; i <= n; i++) {
		for (ll j = 0; j <= 32; j++) {
			if ((A[i] >> j) & 1) {
				sk[j].push_back(i);
			}
		}
	}
	ll cur = A[idx];
	for (ll i = 1; i <= n - 1; i++) {
		vector<ll>f;
		for (ll j = 0; j <= 32; j++) {
			if (not((cur >> j) & 1)) {
				for (auto c : sk[j]) {
					if (vis[c])continue;
					f.push_back(c);
				}
			}
		}
		ll idx = 0, mx = 0;
		for (auto c : f) {
			if (A[c] | cur >= mx) {
				mx = A[c] | cur;
				idx = c;
			}
		}
		ans[i + 1] = idx; cur |= A[idx]; vis[idx] = 1;
	}
	for (ll i = 1; i <= n; i++) {
		if (not ans[i])break;
		cout << A[ans[i]] << " ";
	}
	for (ll i = 1; i <= n; i++) {
		if (not vis[i]) {
			cout << A[i] << " ";
		}
	}
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--) {
		solve();
	}
}