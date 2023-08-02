/*碰到此类题不要往高维的想,应该考虑第i位选,套用最长上升子序列的板子*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e4 + 5;
void solve() {
	ll n, k, a[maxn];
	std::cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	vector<ll>dp(maxn, 0);//维护在前i位中选第i位所能达到的最大值
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (i <= k + 1) {
			dp[i] = a[i];
		} else {
			for (ll j = 1; j < i - k; j++) {
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
			/*for (ll j = i - k ; j <= i - 1; j++) {
				dp[i] = max(dp[i], dp[j]);
			}*/
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
/*O(n)的做法*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e4 + 5;
void solve() {
	ll n, k, a[maxn];
	std::cin >> n >> k;
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	vector<ll>dp(maxn, 0);
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (i <= k + 1) {
			dp[i] = max(dp[i - 1], a[i]);
		} else {
			dp[i] = max(dp[i - 1], dp[i - k - 1] + a[i]);//选择or不选
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
