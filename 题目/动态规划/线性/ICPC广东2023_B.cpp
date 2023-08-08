#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
//单调队列用于维护一定连续区间范围内的最值
void solve() {//优化方式, 单调队列优化dp
	ll n, m; std::cin >> n;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	ll l, r;
	std::cin >> m;
	vector<vector<ll>>p(n + 5), f(n + 5);
	for (ll i = 1; i <= m; i++) {
		std::cin >> l >> r;
		p[l].push_back(r);
		f[r].push_back(l);
	}
	p[n].push_back(n); f[n].push_back(n);
	vector<ll>lim(n + 5, 0);
	for (ll i = 1, j = 1, cur = 0; i <= n; i++) {
		for (auto x : f[i]) {
			if (x >= j) {
				cur++;
			}
		}
		while (cur > 0 and j <= i) {
			for (auto x : p[j]) {
				if (x <= i) {
					cur--;
				}
			}
			j++;
		}
		lim[i] = j;
	}
	vector<ll>q(n + 5, 0);
	ll head = 1, tail = 0;
	vector<ll>dp(n + 5, 0);
	dp[0] = 0;//初始化为空队列
	for (ll i = 1; i <= n; i++) {//从1开始维护
		ll ls = lim[i - 1] - 1;
		while (head <= tail and dp[q[tail]] >= dp[i - 1]) {
			tail--;
		}
		q[++tail] = i - 1;//i = 1时, 前置序列最小值就是dp[0]
		while (q[head] < ls) {
			head++;
		}//维护dp前置序列中 下标为 lim[i - 1] - 1到i - 1范围的最小值
		dp[i] = dp[q[head]] + A[i];//查询前置dp序列的最小值,用单调队列实现

	}
	cout << dp[n] << endl;
}
signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cout.tie(nullptr);
	ll T; cin >> T;
	while (T--) {
		solve();
	}
}
