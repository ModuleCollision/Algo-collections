#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector<ll>T(n + 5, 0), A(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		std::cin >> T[i];
	}
	for (ll i = 1; i <= n; i++) {
		cin >> A[i];
	}
	for (ll i = 1; i <= n; i++) {
		if ((T[i] > T[i - 1] or i == 1) and A[i] < T[i]) {
			puts("0"); return;
		}
	}
	for (ll i = n; i >= 1; i--) {
		if ((A[i] > A[i + 1] or i == n) and T[i] < A[i]) {
			puts("0"); return;
		}
	}
	auto ksm = [&](ll x, ll y)->bool{
		ll ret = 1;
		if (y & 1)ret = ret * x % mod;
		x = x * x % mod;
		y >>= 1;
		return ret % mod;
	}; ll ans = 1;
	for (ll i = 2; i <= n - 1; i++) {
		if (T[i] == T[i - 1] and A[i] == A[i + 1])ans = ans % mod * min(T[i], A[i]) % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}