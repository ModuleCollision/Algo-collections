#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 60010;
const ll inf = 2e9;
const ll mod = 998244353;
void solve() {
	ll W, H, N;
	std::cin >> W >> H >> N;
	vector<pair<ll, ll>>k(N + 5);
	for (ll i = 1; i <= N; i++) {
		std::cin >> k[i].first >> k[i].second;
	}
	ll x, y; std::cin >> x;
	vector<ll>A(x + 5);
	for (ll i = 1; i <= x; i++) {
		std::cin >> A[i];
	}
	A[x + 1] = W;
	std::cin >> y;
	vector<ll>B(y + 5);
	for (ll i = 1; i <= y; i++)std::cin >> B[i];
	B[y + 1] = H; std::map<pair<ll, ll>, ll>cnt;
	for (ll i = 1; i <= N; i++) {
		ll t1 = *lower_bound(A.begin() + 1, A.begin() + 2 + x, k[i].first);
		ll t2 = *lower_bound(B.begin() + 1, B.begin() + 2 + y, k[i].second);
		cnt[ {t1, t2}]++;
	}
	ll mx = -inf, mn = inf;
	for (auto [x, y] : cnt) {
		mx = max(mx, y);
		mn = min(mn, y);
	}
	if (cnt.size() < (x + 1) * (y + 1)) {
		cout << 0 << " " << mx << endl;
	} else {
		cout << mn << " " << mx << endl;
	}
}
signed main() {
	solve();
}