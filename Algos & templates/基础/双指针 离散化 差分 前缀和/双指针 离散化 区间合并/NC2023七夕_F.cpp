#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 1e15;
const ll mod = 1e9 + 7;
void solve() {
	ll n; cin >> n;
	vector<ll>A(n + 5, 0), pre(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		cin >> A[i];
		A[i] ^= 13543;
		A[i] *= 2233;
		A[i] *= 1133;
		A[i] ^= 458646541;
		pre[i] = pre[i - 1] ^ A[i];
	}
	ll ans = 0;
	std::map<ll, ll>cnt1, cnt2; cnt2[0]++;
	for (ll r = 1, l = 1; r <= n; r++) {
		cnt1[A[r]]++;
		while (cnt1[A[r]] == 3) {
			cnt1[A[l]]--;
			cnt2[pre[l - 1]]--;
			l++;
		}
		ans += cnt2[pre[r]];
		cnt2[pre[r]]++;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}
