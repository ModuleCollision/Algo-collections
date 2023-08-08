#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void kk() {
	ll n; std::cin >> n;
	vector<bool>vis(n + 5, 0);
	vector<ll>SG(n + 5, 0); ll l, r; std::cin >> l >> r;
	function<void(ll)>dfs = [&](ll x) {
		vis[x] = 1;
		if (not x) {
			SG[x] = 0; return;//无状态可转移是必输状态,SG值为0
		}
		std::set<ll>st;
		for (ll i = max(0ll, x - r); i <= x - l; i++) {
			if (not vis[i]) {
				dfs(i);
			}
			st.insert(SG[i]);
		}
		//所有待转移的值取mex值,即为该状态的SG值
		for (ll i = 0;; i++) {
			if (not st.count(i)) {
				SG[x] = i; return;
			}
		}//SG定理,直接求出其SG值
	};
	dfs(n);
	for (ll i = 0; i <= n; i++) {
		cout << SG[i] << " ";
	}
	cout << endl;
}
void solve() {
	ll l, r, n;
	std::cin >> n >> l >> r;
	auto SG = [&](ll x) {
		return x % (l + r) / l;
	};
	vector<ll>A(n + 5, 0); ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> A[i]; ans ^= SG(A[i]);
	}
	//SG定理,必输状态(先手输)的状态SG值为0,总状态的SG值所有子状态(每一位)SG值的异或和
	if (ans)puts("First");
	else puts("Second");
}
signed main() {
	solve();
}