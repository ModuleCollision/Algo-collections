#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll a, b;
vector dp(105, vector<ll>(10, 0));
void init() {
	for (ll i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (ll i = 2; i <= 15; i++) {
		for (ll j = 0; j <= 9; j++) {
			for (ll k = j; k <= 9; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
}
void solve() {
	//std::cin >> a >> b;

	//00..0 到 99..9 中 以 0 - 9结尾的递增序列

	auto cal = [&](ll x) {
		vector<ll>num;
		while (x) {
			num.push_back(x % 10); x /= 10;
		}
		ll res = 0; ll pre = 0; ll len = num.size() - 1;
		/*统计位数等于原数的答案数*/
		for (ll i = len; i >= 0; i--) {
			ll cur = num[i];
			for (ll j = (i == len); j < cur; j++) {
				if (j >= pre)res += dp[i + 1][j];
			}
			if (cur < pre)break;
			pre = cur;
			if (not i)res++;
		}
		/*统计位数小于原数的答案数*/
		for (ll i = 1; i <= len; i++) {
			for (ll j = 1; j <= 9; j++) {
				res += dp[i][j];
			}
		}
		return res;
	};
	ll ans =  cal(b) - cal(a - 1);
	cout << ans << endl;

}
signed main() {
	init();
	while (cin >> a >> b)
		solve();
}