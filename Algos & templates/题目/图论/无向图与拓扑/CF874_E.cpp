#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 1);
	vector<ll>d(n + 5, 0), vis(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		ll x; std::cin >> x; A[i] = x;
		d[x]++;
	}//每个点的出度都为1
	ll ans1 = 0, ans2 = 0; ll idx = 0;
	auto topsort = [&](ll u) {
		ll cur = u, sz = 1;
		vis[cur] = idx; bool f1 = 0, f2 = 0;
		bool f = 0;
		while (1) {
			cur = A[cur];
			if (cur == u)f = 1;
			if (vis[cur]) {
				if (vis[cur] == idx)f1 = 1;
				else f2 = 1;
				break;
			}
			vis[cur] = idx;
			sz++;
		}
		if (f and sz > 2)++ans2;//如果整个连通块是一个环
		else if (f1)++ans1;
	};
	//如果整个连通块是一个环,那么不能和其他联通块合并
	for (ll i = 1; i <= n; i++) {
		if (not d[i] and not vis[i]) {//入度为零
			idx++;
			topsort(i);
		}
	}
	for (ll i = 1; i <= n; i++) {
		if (not vis[i]) {
			idx++;
			topsort(i);
		}
	}
	cout << ans2 + (ans1 ? 1 : 0) << " " << ans2 + ans1 << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}
/*实现2*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 1);
	vector<ll>d(n + 5, 0), vis(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		ll x; std::cin >> x; A[i] = x;
		d[x]++;
	}//每个点的出度都为1
	ll ans1 = 0, ans2 = 0; ll idx = 0;
	bool f1 = 0, f = 0;
	function<ll(ll, ll)>dfs = [&](ll u, ll p) {
		if (vis[u]) {
			if (u == p) {
				f = 1;
			}
			if (vis[u] == idx) {
				f1 = 1;
			} return 1ll;
		}
		vis[u] = idx;
		ll w = dfs(A[u], p) + 1; return w;
	};
	//如果整个连通块是一个环,那么不能和其他联通块合并
	for (ll i = 1; i <= n; i++) {
		if (not d[i]) {//入度为零
			idx++; f1 = 0, f = 0;
			vis[i] = idx;
			ll sz = dfs(A[i], i);
			if (f and sz > 2)++ans2;
			else if (f1)++ans1;
		}
	}
	for (ll i = 1; i <= n; i++) {
		if (not vis[i]) {
			idx++; f1 = 0, f = 0;
			vis[i] = idx;
			ll sz = dfs(A[i], i);
			if (f and sz > 2)++ans2;
			else if (f1)++ans1;
		}
	}
	cout << ans2 + (ans1 ? 1 : 0) << " " << ans2 + ans1 << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}