#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, k; std::cin >> n >> k;
	vector<ll>A(n + 5, 0);
	ll ans = 0;
	for (ll i = 1; i <= n; i++)cin >> A[i], A[i] += A[i - 1];
	std::map<ll, ll>cnt; cnt[0]++;
	for (ll i = 1; i <= n; i++) {
		ans += cnt[A[i] - k]; cnt[A[i]]++;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}