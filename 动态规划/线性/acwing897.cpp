#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3 + 5;
const ll inf = 1e6 + 5;
ll N, M; string A, B;
ll dp[maxn][maxn];
void solve() {
	std::cin >> N >> M;
	std::cin >> A >> B;//最长公共子序列
	A = ' ' + A, B = ' ' + B;
	for (ll i = 1; i <= N; i++) {
		for (ll j = 1; j <= M; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			} else {
				dp[i][j] = max({dp[i][j], dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
			}
		}
	}
	cout << dp[N][M] << endl;
}
signed main() {
	solve();
}