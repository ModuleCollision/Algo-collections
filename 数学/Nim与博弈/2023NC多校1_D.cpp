#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, m; std::cin >> n >> m;
	ll a = max(n, m), b = min(n, m);
	if (b == 1 and a == 1) {
		puts("Walk Alone");
	} else {
		puts("Kelin");
	}
}
signed main() {
	solve();
}