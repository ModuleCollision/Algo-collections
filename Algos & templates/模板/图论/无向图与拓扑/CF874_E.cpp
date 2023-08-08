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
	vector<ll>tr[n + 5];
	vector<ll>d(n + 5, 0), vis(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		ll x; std::cin >> x;
		tr[i].push_back(x);
		d[x]++;
	}//每个点的出度都为1
	ll ans1 = 0, ans2 = 0;
	auto topsort = [&](ll u) {
		ll cur = u, sz = 1;
		vis[cur] = 1; bool f = 0;
		while (1) {
			cur = tr[cur][0];
			if (cur == u)f = 1;
			if (vis[cur])break;
			vis[cur] = 1;
			++sz;
		}//在环上则说明拥有了左邻有舍
		if (f and sz > 2)++ans2;//如果整个连通块是一个环
		else ++ans1;
	};
	//如果整个连通块是一个环,那么不能和其他联通块合并
	for (ll i = 1; i <= n; i++) {
		if (not d[i]) {//入度为零
			topsort(i);
		}
	}
	for (ll i = 1; i <= n; i++) {
		if (not vis[i]) {
			topsort(i);
		}
	}
	cout << ans2 + (ans1 ? 1 : 0) << " " << ans2 + ans1 << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}