#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll n, k; char s[maxn];
ll pre[30];
ll dp[maxn][maxn];//以i结尾长度为k的序列总数
void solve() {
	std::cin >> n >> k;
	std::cin >> (s + 1);
	dp[0][0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j <= k; j++) {
			//老套路,先加上前几位的贡献,再考虑当前位的贡献
			dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
			if (j) {
				dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - 1]) % mod;
			}
			if (pre[s[i] - 'a']) {
				//将第i位重复计算的部分去掉
				dp[i][j] = ((dp[i][j] - dp[pre[s[i] - 'a'] - 1][j - 1]) % mod + mod) % mod;//这一部分做了重复贡献
			}
		}
		pre[s[i] - 'a'] = i;
	}
	cout << dp[n][k] % mod << endl;
}
signed main() {
	solve();
}