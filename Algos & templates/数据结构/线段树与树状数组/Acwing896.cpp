#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll N; std::cin >> N;
	vector<ll>A(N + 5), p(N + 5);
	for (ll i = 1; i <= N; i++) {
		std::cin >> A[i]; p[i] = A[i];
	}
	std::sort(p.begin() + 1, p.begin() + 1 + N);
	ll cnt = unique(p.begin() + 1, p.begin() + 1 + N) - p.begin() - 1;
	std::map<ll, ll>sk, ks;
	for (ll i = 1; i <= cnt; i++) {
		sk[i] = p[i]; ks[p[i]] = i;
	}
	vector<ll>dp(N + 5);
	for (ll i = 1; i <= N; i++)dp[1] = 1;
	vector<ll>tr(cnt + 5);
	auto add = [&](ll idx, ll v) {
		for (; idx <= cnt; idx += (idx & -idx)) {
			tr[idx] = max(tr[idx], v);
		}
	};
	auto query = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret = max(ret, tr[idx]);
		}
		return ret;
	};
	add(ks[A[1]], dp[1]);
	for (ll i = 2; i <= N; i++) {
		dp[i] = max(dp[i], query(ks[A[i]] - 1) + 1);
		add(ks[A[i]], dp[i]);
	}
	ll ans = 0; for (ll i = 1; i <= N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
/*树状数组维护前缀最大最小值*/