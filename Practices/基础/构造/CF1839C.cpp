#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n; ll tot = 0;
	vector<ll>A(n + 5, 0), B(n + 5, 0);
	for (ll i = 1; i <= n; i++)std::cin >> A[i];
	for (ll l = 0, r = 1; r <= n; r++) {
		if (not A[r]) {
			B[++tot] = r - l - 1;
			for (ll k = l + 1; k < r; k++) {
				B[++tot] = 0;
			}
			r = l;
		}
	}
	if (A[n] == 1) {
		puts("NO");
	} else {
		puts("YES");
		for (ll i = 1; i <= tot; i++) {
			cout << B[i] << " ";
		}
		cout << endl;
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}