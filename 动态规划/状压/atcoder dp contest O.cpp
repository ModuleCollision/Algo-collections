#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 22 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
/*定义dp[mask]为前num(i)个男生与状态为j的女生配对的方案数*/
/*mask有i个1,为前i个男人,第j位表示第j个女人*/
ll d[maxn][maxn]; ll N;
ll dp[1 << maxn];
void solve() {
	std::cin >> N;
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= N; j++) {
			std::cin >> d[i][j];
		}
	}
	dp[0] = 1;
	for (ll i = 0; i < (1 << N); i++) {
		ll cnt = 0;
		for (ll j = 0; j < N; j++) {
			if ((i >> j) & 1) {
				cnt++;
			}
		}
		for (ll j = 0; j < N; j++) {
			if (((i >> j) & 1) and d[cnt][j + 1]) {
				dp[i] = (dp[i] % mod + dp[i ^ (1 << j)]) % mod;//前 i - 1个人与 状态为 (i ^ (1 << j))配好了对
			}
		}
	}
	cout << (dp[(1 << N) - 1]) << endl;
}
signed main() {
	solve();
}