#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, k; std::cin >> n >> k;
	ll ans = 0;
	vector<ll>A(n + 1);
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i];
		A[i] += A[i - 1];
	}
	vector<ll>w;
	for (ll l = 1; l <= n; l++) {
		for (ll r = l; r <= n; r++) {
			w.push_back(A[r] - A[l - 1]);
		}
	}
	ll sz = w.size(); vector<ll>vis(sz + 1, 0);
	for (ll i = 40; i >= 0; i--) {
		ll cnt = 0;
		for (ll j = 0; j < sz; j++) {
			if (vis[j] == 40 - i and ((w[j] >> i) & 1))cnt++;
		}
		if (cnt >= k) {
			ans |= (1ll << i);
			for (ll j = 0; j < sz; j++) {
				if (vis[j] == 40 - i and ((w[j] >> i) & 1))vis[j]++;//选中了
			}
		} else { //没必要选择
			for (ll j = 0; j < sz; j++) {
				if (vis[j] == 40 - i)vis[j]++;//继承上一轮的
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}