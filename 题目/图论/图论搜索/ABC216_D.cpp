#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e3 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
//可根据题意模拟bfs
void solve() {
	int n, m; cin >> n >> m;
	vector<int>e[n + 5];
	vector<queue<int>>a(m + 5);
	for (int i = 0; i < m; i++) {
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			a[i].push(x);
			if (j == 0) {
				e[x].push_back(i);
			}
		}
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (e[i].size() == 2) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : e[u]) {
			a[v].pop();
			if (not a[v].empty()) {
				e[a[v].front()].push_back(v);
				if (e[a[v].front()].size() == 2) {
					q.push(a[v].front());
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		if (a[i].size()) {
			puts("No");
			return;
		}
	}
	puts("Yes");
}
signed main() {
	solve();
}