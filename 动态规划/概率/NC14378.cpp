/*dp求期望*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
ll n, m, a[maxn], pre[maxn], x;
double dp[maxn], f[maxn];
void solve() {
	cin >> n >> m; ll Max = 0;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		Max = max(Max, a[i]);
		pre[i] = pre[i - 1] + a[i];
	}
	while (m--) {
		std::cin >> x;
		if (x < Max) {
			puts("YNOI is good OI!");
			continue;
		}
		ll tot = a[n];
		dp[n] = 1.0; f[n] = 1.0;
		for (ll i = n - 1, j = n; i >= 1; i--) {
			tot += a[i];
			while (tot > x) {
				tot -= a[j];
				j--;
			}
			dp[i] = (f[i + 1] - f[j + 2]) / double (j - i + 1) + 1;
			f[i] = dp[i] + f[i + 1];
		}
		printf("%.2lf\n", dp[1]);
	}
}
signed main() {
	solve();
}