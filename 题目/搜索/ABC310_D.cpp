#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll N, T, M; std::cin >> N >> T >> M;
	vector<set<ll>>k(T + 5);
	vector<set<ll>>tr(N + 5);
	for (ll i = 1; i <= M; i++) {
		ll A, B; std::cin >> A >> B;
		tr[A].insert(B); tr[B].insert(A);
	}
	ll cur = 0; ll ans = 0;
	function<void(ll)>dfs = [&](ll idx) {
		if (idx >= N + 1) {
			if (cur == T)ans++;
			return;
		}
		for (ll i = 1; i <= cur; i++) {
			bool f = 1;
			if (k[i].count(idx))continue;
			for (auto c : k[i]) {
				if (tr[c].count(idx)) {
					f = 0; break;
				}
			}
			if (not f)continue;
			k[i].insert(idx);
			dfs(idx + 1);
			k[i].erase(idx);
		}
		if (cur < T) {
			cur++;
			k[cur].insert(idx);
			dfs(idx + 1);
			k[cur].clear();
			cur--;
		}
	};
	dfs(1);
	cout << ans << endl;
}
signed main() {
	solve();
}