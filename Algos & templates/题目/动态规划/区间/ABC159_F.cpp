#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll dp[1005][1005][105];
void solve() {
	ll n, s; std::cin >> n >> s;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll i = 1; i <= n + 1; i++)dp[i][i - 1][0] = 1;
	//背包类型的计数dp : 初始化第0维
	ll ans = 0;
	for (ll len = 1; len <= n; len++) {
		for (ll l = 1; l + len - 1 <= n; l++) {
			ll r = l + len - 1;
			for (ll k = 0; k <= s; k++) {
				dp[l][r][k] = (dp[l][r][k] % mod + dp[l][r - 1][k]) % mod;
				if (k >= A[r])dp[l][r][k] = (dp[l][r][k] % mod + dp[l][r - 1][k - A[r]]) % mod;
				//避免重复计算
			}
		}
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = i; j <= n; j++) {
			ans = (ans % mod + dp[i][j][s]) % mod;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}

#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll dp[maxn][maxn];
void solve() {
	ll n, s; std::cin >> n >> s;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	ll ans = 0;
	for (ll i = 0; i <= n; i++)dp[i][0] = i + 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= s; j++) {
			dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
			if (j >= A[i]) {
				dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - A[i]]) % mod;
			}
		}
		//所有以i结尾的区间的方案数
		ans = (ans % mod + dp[i][s]) % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}

