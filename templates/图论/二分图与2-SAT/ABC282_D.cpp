#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll co[maxn]; vector<ll>tr[maxn];
ll sz[5]; ll N, M, cnt = 0;
void solve() {
	std::cin >> N >> M;
	for (ll i = 1; i <= M; i++) {
		ll u, v;
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	bool f = 1;
	function<bool(ll)>dfs = [&](ll u) {
		cnt += tr[u].size();
		for (auto v : tr[u]) {
			if (co[v]) {
				if (co[v] == co[u]) {
					return false;
				}
			} else {
				co[v] = 3 - co[u];
				sz[co[v]]++;
				bool f = dfs(v); if (not f)return false;
			}
		}
		return true;
	};
	ll ans1 = 0, ans2 = 0;
	for (ll i = 1; i <= N; i++) {
		if (not co[i]) {
			cnt = 0; sz[1] = sz[2] = 0;
			co[i] = 1; bool ff = dfs(i);
			sz[co[i]]++;
			if (not ff) {
				puts("0"); return;
			}
			ans1 += sz[1] * sz[2] - cnt / 2;
			ans2 += (sz[1] + sz[2]) * (N - (sz[1] + sz[2]));
		}
	}/*分成不同可以组成二部图的连通块*/
	cout << ans1 + ans2 / 2 << endl;
}
signed main() {
	solve();
}


/*两种判断二分图的方式*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll co[maxn];
ll sz[5]; ll N, M, cnt = 0;
void solve() {
	std::cin >> N >> M; vector<vector<ll>>tr(N + 5);
	for (ll i = 1; i <= M; i++) {
		ll u, v;
		std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	bool f = 1;
	function<void(ll)>dfs = [&](ll u) {
		cnt += tr[u].size();//边的度数 = 连通块的点数 * 2
		for (auto v : tr[u]) {
			if (co[v]) {
				if (co[v] == co[u]) {
					f = false; return;
				}
			} else {
				co[v] = 3 - co[u];
				sz[co[v]]++;
				dfs(v);
			}
		}
	};
	ll ans1 = 0, ans2 = 0;
	for (ll i = 1; i <= N; i++) {
		if (not co[i]) {
			cnt = 0; sz[1] = sz[2] = 0;
			co[i] = 1; dfs(i);
			sz[co[i]]++;
			if (not f) {
				puts("0"); return;
			}
			ans1 += sz[1] * sz[2] - cnt / 2;
			ans2 += (sz[1] + sz[2]) * (N - (sz[1] + sz[2]));
		}
	}/*分成不同可以组成二部图的连通块*/
	cout << ans1 + ans2 / 2 << endl;
}
signed main() {
	solve();
}