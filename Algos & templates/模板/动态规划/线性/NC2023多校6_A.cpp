#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector<ll>fa(n + 5, 0), sz(n + 5, 0);
	vector<array<ll, 3>>e(n + 5);
	vector<ll>A(n + 5, 0);
	vector<ll>c(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> A[i]; fa[i] = i;
		sz[i] = 1;
	}
	for (ll i = 1; i <= n; i++) {
		std::cin >> c[i];
	}
	vector dp(n + 5, vector<ll>(n + 5, 0));//某点子树下有几个黑子/白子所需的earning-cost最小值
	for (ll i = 1; i <= n - 1; i++) {
		std::cin >> e[i][0] >> e[i][1] >> e[i][2];
	}
	std::sort(e.begin() + 1, e.begin() + n, [&](array<ll, 3>x, array<ll, 3>y)->bool{
		return x[2] < y[2];
	});
	auto find = [&](ll x) {
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	};
	for (ll i = 1; i <= n; i++) {
		dp[i][A[i]] = 0;
		dp[i][A[i] ^ 1] = -c[i];
	}
	for (ll s = 1;  s < n; s++) {
		auto [u, v, w] = e[s];
		u = find(u), v = find(v);
		vector<ll>tmp(sz[u] + sz[v] + 5, -inf);
		for (ll i = 0; i <= sz[u]; i++) {
			for (ll j = 0; j <= sz[v]; j++) {
				tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j] + (sz[u] - i) * j * w + (sz[v] - j) * i * w);
			}
		}
		fa[v] = u;
		sz[u] += sz[v];
		for (ll j = 0; j <= sz[u]; j++)dp[u][j] = tmp[j];
	}
	ll cur = find(1); ll ans = 0;
	for (ll i = 0; i <= n; i++)ans = max(ans, dp[cur][i]);
	cout << ans << endl;
}
signed main() {
	solve();
}