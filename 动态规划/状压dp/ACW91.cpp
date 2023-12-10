#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 25;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll w[maxn][maxn], N;//将前 i 位 与
void solve() {
	std::cin >> N;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			std::cin >> w[i][j];
		}
	}
	vector dp(((1 << N) + 5), vector<ll>(N + 5, inf));
	dp[1][0] = 0;
	for (ll i = 0; i < (1 << N); i++) {
		for (ll j = 0; j < N; j++) {
			if ((i >> j) & 1) {
				for (ll k = 0; k < N; k++) {
					if ((i >> k) & 1) { // 哈密顿图不允许重复访问
						dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + w[k][j]);
					}
				}
			}
		}
	}
	//遍历过某个状态, 停留在某点的最短路径
	cout << dp[(1 << N) - 1][N - 1] << endl;
}
signed main() {
	solve();
}


/*写法二*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 25;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll w[maxn][maxn], N;//将前 i 位 与
void solve() {
	std::cin >> N;
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			std::cin >> w[i][j];
		}
	}
	vector dp(((1 << N) + 5), vector<ll>(N + 5, inf));
	dp[1][0] = 0;
	for (ll i = 0; i < N; i++) {
		dp[(1 << i)][i] = w[0][i];
	}
	for (ll i = 1; i < (1 << N); i++) {
		for (ll j = 0; j < N; j++) {
			if ((i >> j) & 1) {
				for (ll k = 0; k < N; k++) {
					if (((i >> k) & 1) == 0) {
						dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + w[j][k]);
					}
				}
			}
		}
	}
	//遍历过某个状态, 停留在某点的最短路径
	cout << dp[(1 << N) - 1][N - 1] << endl;
}
signed main() {
	solve();
}
