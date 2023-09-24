#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	auto ch = [&]() {
		vector<bool>dp((1 << 6) + 5, false);
		for (ll i = 0; i < (1 << 6); i++) {
			ll x = -1; bool f = false;
			for (ll j = 0; j <= 5; j++) {
				if ((i >> j) & 1)x = j;
			}
			for (ll j = 0; j < x; j++) {
				if (((i >> j) & 1) == 0) {
					dp[i] = dp[i] | (not (dp[i - (1 << x) + (1 << j)]));
					if (dp[i])break;
				}
			}
			if (not dp[i]) {
				for (ll j = 0; j <= 5; j++) {
					if ((i >> j) & 1)cout << " " << j;
				}
				cout << endl;
			}
		}
	};
	//ch();
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	if (A[n] - A[n - 1] == 1 and (((n - 2) & 1) ^ (A[n - 1] & 1)) == 0)puts("Bob");
	else puts("Alice");
}
signed main() {
	solve();
}