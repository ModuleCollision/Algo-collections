#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll p[maxn], A[maxn];
/*线性基维护重复数最大异或和*/
void solve() {
	auto insert = [&](ll u) {
		for (ll i = 33; i >= 0; i--) {
			if ((u >> i) & 1) {
				if (not p[i]) {
					p[i] = u;
					break;
				} else {
					u ^= p[i];
				}
			}
		}
	};
	ll N, M; std::cin >> N;
	for (ll i = 1; i <= N; i++) {
		std::cin >> A[i];
		insert(A[i]);
	}
	std::cin >> M;
	while (M--) {
		bool f = 1;
		ll x, y; std::cin >> x >> y; ll tmp = x ^ y;
		for (ll i = 33; i >= 0; i--) {
			if ((tmp >> i) & 1) {
				if (not p[i]) {
					f = 0; break;
				} else tmp ^= p[i];
			}
		}
		if (not f)puts("NO");
		else puts("YES");
	}
}
signed main() {
	solve();
}