#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n;
db dp[maxn];
//期望递推
void solve() {
	std::cin >> n;
	dp[0] = 1;
	for (ll i = 1; i <= n; i++) {
		db p = dp[i - 1] / (i - 1 + 2);
		dp[i] = (dp[i - 1] * (1 - p)) + (dp[i - 1] + 1) * p;
	}
	printf("%.7lf", dp[n]);
}
signed main(){
	solve();
}