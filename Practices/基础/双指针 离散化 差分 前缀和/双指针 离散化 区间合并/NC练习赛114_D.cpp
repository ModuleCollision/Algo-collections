#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	std::map<ll, ll>cnt;
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		ll v; std::cin >> v; cnt[v]++;
	}
	ll tot = 0;
	for (auto [x, y] : cnt)A[++tot] = x;
	for (ll i = 1; i <= n; i++) {
		while (cnt[A[i]] > 0) {
			ll j = A[i];
			while (cnt[j + 1] >= cnt[j] and j <= n and cnt[j + 1] > 0) {
				cnt[j]--; j++;
			}
			cnt[j]--;
			if (j - A[i] + 1 < 5) {
				puts("NO"); return;
			}
		}
	}
	puts("YES"); return;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}