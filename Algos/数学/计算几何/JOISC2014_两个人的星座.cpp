#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const db pi = acos(-1);
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
struct sq {
	db x, y; ll c;
	db k;
};
void solve() {
	auto angle = [&](sq w) {
		return atan(w.y / w.x);
	};
	ll n; std::cin >> n;
	vector<sq>a(n + 5);
	for (ll i = 1; i <= n; i++) {
		cin >> a[i].x >> a[i].y >> a[i].c;
	}

	auto eq = [&](db x, db y)->bool{
		return abs(x - y) < 1e-10;
	};
	ll ans = 0;
	auto s = [&](ll u) {//以一个点为极点将所有点按照极轴分为两部分
		vector<sq>b;
		vector cnt(5, vector<ll>(3, 0));//在某侧某颜色的点的个数
		auto cal = [&](ll k, ll x) {
			ll ret = 1;
			for (ll i = 0; i < 3; i++) {
				if (i != x)ret *= cnt[k][i];
			}
			return ret;
		};
		for (ll i = 1; i <= n; i++) {
			if (i == u)continue;
			b.push_back(a[i]);
		}
		vector<ll>bl(n + 5, 0);//枚举每一次内切线时该点在线的哪一侧
		ll m = b.size();
		for (ll i = 0; i < m; i++) {
			b[i].x -= a[u].x; b[i].y -= a[u].y;
			b[i].k = angle(b[i]);
			if (b[i].k <= 0)b[i].k += pi;
		}
		std::sort(b.begin(), b.end(), [&](sq t1, sq t2)->bool{
			return t1.k < t2.k;
		});
		for (ll i = 0; i <= 1; i++) {
			std::fill(cnt[i].begin(), cnt[i].end(), 0);
		}
		for (ll i = 0; i < m; i++) {
			if (b[i].y < 0 or (eq(b[i].y, 0.0) and b[i].x > 0)) {
				bl[i] = 0;
			} else {
				bl[i] = 1;
			}
			cnt[bl[i]][b[i].c]++;
		}
		for (ll i = 0; i < m; i++) {
			cnt[bl[i]][b[i].c]--;
			ans += cal(0, b[i].c) * cal(1, a[u].c);
			ans += cal(1, b[i].c) * cal(0, a[u].c);
			cnt[bl[i] ^= 1][b[i].c]++;
		}
	};
	for (ll i = 1; i <= n; i++)s(i);
	cout << ans / 4 << endl;
}
signed main() {
	solve();
}