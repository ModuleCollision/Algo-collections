#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll N, M; std::cin >> N >> M;
	vector<ll>s[N + 5], f[M + 5];
	vector<bool>vis(N + 5, 0);
	for (ll i = 1; i <= N; i++) {
		ll k; std::cin >> k;
		for (ll j = 1; j <= k; j++) {
			ll v; std::cin >> v;
			s[i].push_back(v);
			f[v].push_back(i);
		}
	}
	vector<ll>dis(M + 5, -1);
	vector<bool>vs(M + 5, 0);
	queue<ll>q; q.push(1); dis[1] = 0; vs[1] = 1;
	while (q.size()) {
		auto x = q.front(); q.pop();
		for (auto i : f[x]) {
			if (not vis[i]) { //还没有被合并过
				vis[i] = true;
				for (auto v : s[i]) {
					if (vs[v]) continue;
					vs[v] = 1;
					dis[v] = dis[x] + 1; q.push(v);
				}
			}
		}
	}
	ll ans = dis[M]; if (ans != -1)ans--;
	cout << ans << endl;
}
signed main() {
	solve();
}