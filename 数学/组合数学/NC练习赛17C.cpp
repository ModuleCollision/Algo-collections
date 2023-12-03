#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
//矩阵快速幂
void solve() {
	ll n, k; std::cin >> n >> k;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector ans(n + 5, vector<ll>(n + 5, 0));
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= i; j++)ans[i][j] = 1;
	}
	auto mul = [&](vector<vector<ll>>x, vector<vector<ll>>y) {
		vector ret(n + 5, vector<ll>(n + 5, 0));
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= n; j++) {
				for (ll k = 1; k <= n; k++) {
					ret[i][j] = (ret[i][j] % mod + x[i][k] % mod * y[k][j]) % mod;
				}
			}
		}
		return ret;
	};
	vector ff(n + 5, vector<ll>(n + 5, 0));
	for (ll i = 1; i <= n; i++)ff[i][i] = 1;
	auto mat_ksm = [&](ll b) {
		while (b) {
			if (b & 1)ff = mul(ff, ans);
			ans = mul(ans, ans);
			b >>= 1;
		}
	};
	mat_ksm(k);
	vector<ll>res(n + 5);
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= i; j++) {
			res[i] = (res[i] % mod + ff[i][j] % mod * A[j] % mod) % mod;
		}
	}
	for (ll i = 1; i <= n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;
}
signed main() {
	solve();
}