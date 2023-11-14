/*内向基环树*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
vector<ll>tr[maxn]; ll N;
void solve() {
	std::cin >> N; ll A;
	vector<ll>d(N + 5, 0);
	for (ll i = 1; i <= N; i++) {
		std::cin >> A; tr[i].push_back(A);
		d[A]++;
	}
	queue<ll>q; vector<bool>vis(N + 5);
	for (ll i = 1; i <= N; i++) {
		if (not d[i]) {
			q.push(i); vis[i] = 1;
		}
	}
	while (not q.empty()) {
		auto cur = q.front(); q.pop();
		for (auto v : tr[cur]) {
			d[v]--;
			if (not d[v]) {
				q.push(v); vis[v] = 1;
			}
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		if (not vis[i]) {
			ll t = i; ans++;
			vis[t] = 1;
			while (1) {
				bool f = 1;
				for (auto v : tr[t]) {
					if (not vis[v]) {
						f = 0; t = v; vis[t] = 1; ans++; break;
					}
				}
				if (f)break;
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}