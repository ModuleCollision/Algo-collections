#include <bits/extc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 4e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct Node {
	ll l; ll r; ll sum; ll add;
} tr[2050000];
void pushup(ll p) {
	tr[p].sum = (tr[p << 1].sum + tr[p << 1 | 1].sum);
}
void build(ll p, ll l, ll r) {
	tr[p].l = l; tr[p].r = r;
	if (l == r) {
		tr[p].sum = tr[p].add = 0;
		return;
	}
	ll mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
void pushdown(ll p) {
	ll l = tr[p].l, r = tr[p].r;
	ll mid = (l + r) >> 1;
	ll add = tr[p].add;
	tr[p << 1].sum += add * (mid - l + 1);
	tr[p << 1 | 1].sum += add * (r - mid);
	tr[p << 1].add += add;
	tr[p << 1 | 1].add += add;
	tr[p].add = 0;
}

void modify(ll p, ll l, ll r, ll val) {
	if (tr[p].l >= l and tr[p].r <= r) {
		tr[p].sum += (tr[p].r - tr[p].l + 1) * val;
		tr[p].add = (tr[p].add + val);
		return;
	}
	pushdown(p);
	ll mid = (tr[p].l + tr[p].r) >> 1;
	if (r > mid) {
		modify(p << 1 | 1, l, r, val);
	}
	if (l <= mid) {
		modify(p << 1, l, r, val);
	}
	pushup(p);
}
ll query(ll p, ll l, ll r) {
	if (tr[p].l >= l and tr[p].r <= r) {
		return tr[p].sum;
	}
	pushdown(p);
	ll ret = 0, mid = (tr[p].l + tr[p].r) >> 1;
	if (r > mid) {
		ret = (ret + query(p << 1 | 1, l, r));
	}
	if (l <= mid) {
		ret = (ret + query(p << 1, l, r));
	}
	return ret;
}
pair<ll, ll> s[maxn]; ll n, m;
void solve() {
	std::cin >> n >> m;
	build(1, 1, maxn); ll ans = 0;
	for (ll i = 1; i <= m; i++) {
		cin >> s[i].first >> s[i].second;
	}
	std::sort(s + 1, s + 1 + m, [&](pair<ll, ll>x, pair<ll, ll>y)->bool{
		if (x.second != y.second)return x.second < y.second;
		else return x.first < y.first;
	});
	modify(1, s[1].first, s[1].second, 1);
	for (ll i = 2; i <= m; i++) {
		ll tmp = 0;
		ll mn = n - s[i].second, mx = n - s[i].first;
		mn = max(mn, 1ll);
		if (mx <= 0) {
			modify(1, s[i].first, s[i].second, 1); continue;
		}
		tmp = query(1, mn, mx) % mod;
		ans = (ans  + tmp) % mod;
		modify(1, s[i].first, s[i].second, 1);
	}
	cout << ans * 2 % mod << endl;
}
signed main() {
	solve();
}