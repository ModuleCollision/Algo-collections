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
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector<ll>pre1(33), pre2(33);//前缀为 0 的个数，前缀为1的个数
	vector<ll>cnt(33);
	for (ll i = 30; i >= 0; i--)pre1[i]++;
	vector<ll>w(n + 1);
	for (ll i = 1; i <= n; i++) {
		w[i] = w[i - 1] ^ A[i];
	}
	for (ll i = 1; i <= n; i++) {
		for (ll j = 30; j >= 0; j--) {
			if (((w[i] >> j) & 1)) {
				cnt[j] += pre1[j];
				pre2[j]++;
			} else {
				cnt[j] += pre2[j]; pre1[j]++;
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i <= 30; i++) {
		ans += (1 << i) * cnt[i];
	}
	cout << ans << endl;
}
signed main() {
	solve();
}