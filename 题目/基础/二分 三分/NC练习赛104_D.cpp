#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct cmp {
	bool operator()(const pair<ll, ll>& x, const pair<ll, ll>&y)const {
		return x.second > y.second;
	}
};
struct edge {
	ll u, v, w;
};
void solve() {
	ll n, m, s, t, k;
	std::cin >> n >> m >> s >> t >> k;
	vector<vector<pair<ll, ll>>>tr(n + 5);
	ll u, v, w; ll mx = 0;
	vector<edge>ed(m + 5);
	for (ll i = 1; i <= m; i++) {
		std::cin >> ed[i].u >> ed[i].v >> ed[i].w;
		mx = max(mx, ed[i].w);
	}
	if (s == t) {
		puts("0"); return;
	}
	vector<ll>dis(n + 5, 0);
	vector<bool>vis(n + 5, 0);
	auto cal = [&](ll x) {
		return (x * 114 + 513) / 514;
	};
	auto check = [&](ll ts) {
		priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp>q;
		q.push({s, 0});
		std::fill(dis.begin(), dis.end(), inf);
		std::fill(vis.begin(), vis.end(), 0);
		dis[s] = 0;
		for (ll i = 1; i <= n; i++) {
			tr[i].clear();
		}
		for (ll i = 1; i <= m; i++) {
			auto [u, v, w] = ed[i];
			if (w <= ts) {
				tr[u].push_back({v, 0});
				tr[v].push_back({u, 0});
			} else if (w > ts and cal(w) <= ts) {
				w = cal(w);
				tr[u].push_back({v, 1});//这条路被更改过
				tr[v].push_back({u, 1});
			}
		}
		while (q.size()) {
			auto [u, d] = q.top(); q.pop(); vis[u] = 1;
			for (auto [v, w] : tr[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = min(dis[v], dis[u] + w);
					if (not vis[v]) {
						q.push({v, dis[v]});
					}
				}
			}
		}
		return dis[t] <= k;//满足最短路径上的药水<=k即可
	};
	ll l = 0, r = mx; ll ans = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1; ans = mid;
		} else {
			l = mid + 1;
		}
	}
	if (not ans) {
		puts("I really need TS1's time machine again!");
		return;
	}
	cout << ans << endl;
	/*while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	if (r == mx) {
		puts("I really need TS1's time machine again!");
		return;
	}
	cout << r << endl;*/
}
signed main() {
	solve();
}


/*用multiset + 重载代替优先队列也可*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct cmp {
	bool operator()(const pair<ll, ll>& x, const pair<ll, ll>&y)const {
		return x.second < y.second;
	}
};
struct edge {
	ll u, v, w;
};
void solve() {
	ll n, m, s, t, k;
	std::cin >> n >> m >> s >> t >> k;
	vector<vector<pair<ll, ll>>>tr(n + 5);
	ll u, v, w; ll mx = 0;
	vector<edge>ed(m + 5);
	for (ll i = 1; i <= m; i++) {
		std::cin >> ed[i].u >> ed[i].v >> ed[i].w;
		mx = max(mx, ed[i].w);
	}
	if (s == t) {
		puts("0"); return;
	}
	vector<ll>dis(n + 5, 0);
	vector<bool>vis(n + 5, 0);
	auto cal = [&](ll x) {
		return (x * 114 + 513) / 514;
	};
	auto check = [&](ll ts) {
		multiset<pair<ll, ll>, cmp>q;
		q.insert({s, 0});
		std::fill(dis.begin(), dis.end(), inf);
		std::fill(vis.begin(), vis.end(), 0);
		dis[s] = 0;
		for (ll i = 1; i <= n; i++) {
			tr[i].clear();
		}
		for (ll i = 1; i <= m; i++) {
			auto [u, v, w] = ed[i];
			if (w <= ts) {
				tr[u].push_back({v, 0});
				tr[v].push_back({u, 0});
			} else if (w > ts and cal(w) <= ts) {
				w = cal(w);
				tr[u].push_back({v, 1});//这条路被更改过
				tr[v].push_back({u, 1});
			}
		}
		while (q.size()) {
			auto [u, d] = (*q.begin()); q.erase(q.begin()); vis[u] = 1;
			for (auto [v, w] : tr[u]) {
				if (dis[u] + w < dis[v]) {
					dis[v] = min(dis[v], dis[u] + w);
					if (not vis[v]) {
						q.insert({v, dis[v]});
					}
				}
			}
		}
		return dis[t] <= k;//满足最短路径上的药水<=k即可
	};
	ll l = 0, r = mx; ll ans = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid - 1; ans = mid;
		} else {
			l = mid + 1;
		}
	}
	if (not ans) {
		puts("I really need TS1's time machine again!");
		return;
	}
	cout << ans << endl;
	/*while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	if (r == mx) {
		puts("I really need TS1's time machine again!");
		return;
	}
	cout << r << endl;*/
}
signed main() {
	solve();
}