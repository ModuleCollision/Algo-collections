#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N,  Q;
vector<ll>tr[maxn];
pair<ll, ll>e[maxn];
ll p[maxn], x, y; bool vis[maxn];
ll mp[maxn]; ll co[maxn];
struct DSU {
	vector<ll>fa;
	void init(ll N) {
		fa.resize(N + 5, 0);
		for (ll i = 1; i <= N; i++) {
			fa[i] = i;
		}
	}
	ll find(ll x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}
	ll merge(ll x, ll y) {
		ll a = find(x), b = find(y);
		fa[a] = b;
	}
} dsu;
void solve() {
	std::cin >> N;
	for (ll i = 1; i <= N; i++) {
		std::cin >> e[i].first >> e[i].second;
		tr[e[i].first].push_back(e[i].second);
		tr[e[i].second].push_back(e[i].first);
	}
	dsu.init(N);
	std::cin >> Q;
	for (ll i = 1; i <= N; i++) {
		ll s = e[i].first, t = e[i].second;
		if (dsu.find(s) == dsu.find(t)) {
			//cout << s << " " << t << endl;
			x = s; y = t; break;

		}
		dsu.merge(s, t);
	}
	auto bfs = [&]() {
		queue<ll>q;
		q.push(x);
		vis[x] = 1;
		while (not q.empty()) {
			auto cur = q.front();
			q.pop();
			if (cur == y)return;
			for (auto v : tr[cur]) {
				if (vis[v])continue;
				vis[v] = true;
				p[v] = cur;
				q.push(v);
			}
		}
	};
	bfs();
	mp[x] = mp[y] = 1;
	for (ll t = y; t != x; t = p[t]) {
		mp[t] = 1;
	}
	ll tot = 0;
	function<void(ll, ll)>tarjan = [&](ll u, ll f) {
		co[u] = tot;
		for (auto v : tr[u]) {
			if (v == f or mp[v] or co[v])continue;
			tarjan(v, u);
		}
	};
	for (ll i = 1; i <= N; i++) {
		if (mp[i]) {
			tot++;
			tarjan(i, 0);
		}
	}
	for (ll i = 1; i <= N; i++) {
		cout << co[i] << endl;
	}
	while (Q--) {
		ll l, r; std::cin >> l >> r;
		if (co[l] != co[r])puts("No");
		else puts("Yes");
	}
}
signed main() {
	solve();
}