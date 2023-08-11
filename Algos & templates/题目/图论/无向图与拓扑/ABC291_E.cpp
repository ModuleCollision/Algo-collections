/*仍然需要用到拓扑排序*/
/*根据大小关系建立起来的拓扑图是不能存在环的,意味着矛盾*/
/*只能有一个最大值,这意味着入度为零的点唯一*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
vector<ll>tr[maxn];
queue<ll>q; ll n, m, u, v;
void solve() {
	std::cin >> n >> m;
	vector<ll>d(n + 5, 0);
	std::vector<std::set<ll>>st(n + 5);
	vector<vector<ll>>tr(n + 5);
	for (ll i = 1; i <= m; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
		st[u].insert(v); d[v]++;
	}
	for (ll i = 1; i <= n; i++) {
		if (not d[i]) {
			q.push(i);
		}
	}
	vector<ll>ans;
	while (not q.empty()) {
		ll cur = q.front();
		q.pop();
		ans.push_back(cur);
		for (auto x : tr[cur]) {
			d[x]--;
			if (not d[x]) {
				q.push(x);
			}
		}
	}
	if (ans.size() != n) {
		puts("No"); return;
	}
	for (ll i = 0; i < n - 1; i++) {
		if (not st[ans[i]].count(ans[i + 1])) {
			puts("No"); return;
		}
	}
	vector<ll>w(n + 5);
	for (ll i = 0; i < n; i++) {
		w[ans[i]] = i + 1;
	}
	puts("Yes");
	for (ll i = 1; i <= n; i++)cout << w[i] << " ";
	cout << endl;
}
signed main() {
	solve();
}