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
	for (ll i = 1; i <= m; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v);
		d[v]++;
	}
	for (ll i = 1; i <= n; i++) {
		if (not d[i]) {
			q.push(i);
		}
	}
	vector<ll>ans;
	while (not q.empty()) {
		if (q.size() != 1) {
			puts("No");
			return;
		}
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
	puts("Yes");
	for (auto c : ans) {
		cout << c << " ";
	}
}
signed main() {
	solve();
}