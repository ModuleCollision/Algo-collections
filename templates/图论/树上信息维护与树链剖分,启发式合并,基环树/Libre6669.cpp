#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector fa(n + 5, 0), dep(n + 5, 0), siz(n + 5, 0), son(n + 5, 0);
	vector ch(n + 5, vector(2, 0));
	vector bot(n + 5, 0), id(n + 5, 0);
	auto query = [&](ll u, ll v) {
		cout << "? " << u << " " << v << endl;
		cout.flush();
		ll d; std::cin >> d;
		return d;
	};
	auto setf = [&](ll u, ll v) {
		fa[v] = u;
		if (ch[u][0])ch[u][1] = v;
		else ch[u][0] = v;
	};
	function<void(ll)>dfs = [&](ll u) {
		if (ch[u][0])dfs(ch[u][0]);
		if (ch[u][1])dfs(ch[u][1]);
		siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1;
		if (ch[u][1]) {
			son[u] = (ll)(siz[ch[u][0]] < siz[ch[u][1]]);
		} else son[u] = 0;
		if (ch[u][son[u]]) {//并非重链的底端
			bot[u] = bot[ch[u][son[u]]];
		} else {
			bot[u] = u;//重链的底端
		}
	};//模拟重链剖分,son记录重链走向

	function<void(ll, ll)>tarjan = [&](ll u, ll k) {
		if (not ch[u][0]) {
			setf(u, k); return;
		}
		ll d = query(k, bot[u]);
		ll v = bot[u];
		while (dep[v] > (dep[k] + dep[bot[u]] - d) / 2)v = fa[v];
		ll w = ch[v][son[v] ^ 1];//由已知树链的信息定向到k的父亲
		if (w)tarjan(w, k);
		else setf(v, k);
	};
	for (ll i = 2; i <= n; i++) {
		id[i] = i; dep[i] = query(1, i);
	}
	std::sort(id.begin() + 2, id.begin() + n + 1, [&](ll x, ll y)->bool{
		return dep[x] < dep[y];
	});
	for (ll i = 2; i <= n; i++) {
		dfs(1); tarjan(1, id[i]);
	}
	putchar('!');
	for (ll i = 2; i <= n; i++) {
		cout << " " << fa[i];
	}
	cout << endl;
	cout.flush();
}
signed main() {
	solve();
}
