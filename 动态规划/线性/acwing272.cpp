#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	int n; std::cin >> n;
	vector<ll>A(n + 5), B(n + 5);
	for (int i = 1; i <= n; i++)cin >> A[i];
	for (int i = 1; i <= n; i++)cin >> B[i];
	vector dp(n + 5, vector<int>(n + 5, 0));//以 i 结尾的与 j 的最长上升子序列
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (A[i] == B[j]) {
				dp[i][j] = 1;
				for (ll k = 1; k <= i - 1; k++) {
					if (A[k] < A[i]) {
						dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i][n]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}