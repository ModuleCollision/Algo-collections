/*与概率递推不同,本题应当先算出各种情况的种数量,结合古典概型进行运算*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, d; std::cin >> n >> d;
	vector<ll>A(n + 5, 0);
	vector<ll>p(n + 5, 0);
	p[0] = 1;
	for (ll i = 1; i <= n; i++) {
		p[i] = p[i - 1] % mod * i % mod;
	}
	for (ll i = 1; i <= n; i++)cin >> A[i];
	auto inv = [&](ll x) {
		ll ret = 1, b = mod - 2;
		while (b) {
			if (b & 1) {
				ret = ret * x % mod;
			}
			x = x * x % mod;
			b >>= 1;
		}
		return ret;
	};
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	auto C = [&](ll n, ll m) {
		return p[n] % mod * inv(p[n - m] % mod) % mod * inv(p[m] % mod) % mod % mod;
	};
	vector<vector<vector<ll>>>dp(n + 3, vector<vector<ll>>(n + 3, vector<ll>(2, 0)));
	dp[0][0][0] = 1;
	//dp[1][1][1] = dp[1][0][0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= i; j++) {
			dp[i][j][0] = (dp[i][j][0] % mod + dp[i - 1][j][0]) % mod;
			dp[i][j][0] = (dp[i][j][0] % mod + dp[i - 1][j][1]) % mod;
			if (j and A[i] - d > A[i - 1])
				dp[i][j][1] = (dp[i][j][1] % mod + dp[i - 1][j - 1][0]) % mod;
			if (j)
				dp[i][j][1] = (dp[i][j][1] % mod + dp[i - 1][j - 1][1]) % mod;
		}
	}
	for (ll i = 1; i <= n; i++) {
		cout << (dp[n][i][1] % mod + dp[n][i][0]) % mod*inv(C(n, i)) % mod << endl;
	}
}
signed  main() {
	solve();
}