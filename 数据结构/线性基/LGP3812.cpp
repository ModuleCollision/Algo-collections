#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lb;
const ll maxn = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ull p[maxn], A[maxn];
/*线性基求出向量组最小/最大异或和*/
void insert(ull x) {
	for (ll i = 51; i >= 0; i--) {
		if (((x >> i) & 1)) {
			if (not p[i]) {
				p[i] = x; break;
			} else {
				x ^= p[i];
			}
		}
	}
}
void solve() {
	ll n; std::cin >> n; ull ans = 0;
	for (ll i = 1; i <= n; i++)
		cin >> A[i], insert(A[i]);
	for (ll i = 51; i >= 0; i--) {
		ans = max(ans, ans ^ p[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}