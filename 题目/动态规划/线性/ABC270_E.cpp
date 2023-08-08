#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll dp[maxn], K, A[maxn], N;
void solve() {
	std::cin >> N >> K;
	for (ll i = 0; i < K; i++) {
		std::cin >> A[i];
	}
	for (ll i = 0; i <= N; i++) {
		for (ll j = 0; j < K; j++) {
			if (i - A[j] >= 0)
				dp[i] = max(dp[i], i - dp[i - A[j]]);

		}
	}
	cout << dp[N] << endl;
}
signed main() {
	solve();
}