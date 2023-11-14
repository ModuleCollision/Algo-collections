#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
const db eps = 0.0000001;
void solve() {
	ll v0, x, y;
	std::cin >> v0 >> x >> y;
	auto f = [&](db t)->db{
		return (db)t + (db)y / ((db)v0 + t * x);
	};
	db l = 0, r = 1e9;
	while (r - l > eps) {
		db mid = (l + r) / 2;
		db lmid = mid - eps;
		db rmid = mid + eps;
		if (f(lmid) < f(rmid)) {
			r = mid;
		} else l = mid;
	}
	printf("%.8lf", f(l));
}
signed main() {
	solve();
}