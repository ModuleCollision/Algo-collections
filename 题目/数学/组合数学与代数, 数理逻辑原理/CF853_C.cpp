#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
char s[maxn];
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>p(m + 5, 0), v(m + 5, 0);
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll i = 1; i <= m; i++)cin >> p[i] >> v[i];
	vector<ll>cnt(n + m + 5, 0), pos(n + m + 5, 0);//维护某数在数列中的总出现次数
	//维护某个位的上一次修改
	ll ans = 0;
	for (ll i = 1; i <= m; i++) {
		if (A[p[i]] != v[i]) {
			cnt[A[p[i]]] += i - pos[p[i]];
			pos[p[i]] = i;
		}//每次修改后统计该位修改前对该数出现总次数的贡献
		A[p[i]] = v[i];
	}
	for (ll i = 1; i <= n; i++) {
		cnt[A[i]] += m - pos[i] + 1;
	}
	for (ll i = 1; i <= n + m; i++) {
		ans += cnt[i] * (m + 1 - cnt[i]);//考虑两数不同的贡献
		ans += cnt[i] * (cnt[i] - 1) / 2;//组合数
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}