#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	int n; cin >> n;
	vector<int>A(n + 5); vector<int>d(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		cin >> A[i]; d[A[i]]++;
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (not d[i]) {
			q.push(i);
		}
	}
	while (q.size()) {
		int cur = q.front(); q.pop();
		d[A[cur]]--;
		if (not d[A[cur]]) {
			q.push(A[cur]);
		}
	}
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i]) {
			cur = i; break;
		}
	}
	vector<int>ans = {cur}; int nxt = A[cur];
	while (nxt != cur) {
		ans.push_back(nxt);
		nxt = A[nxt];
	}
	cout << ans.size() << '\n';
	for (auto c : ans)cout << c << ' ';
	cout << '\n';
}
signed main() {
	solve();
}