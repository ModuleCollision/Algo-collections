#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n;
struct sq {
	ll v; ll k; ll id;
} q[maxn];
void solve() {
	std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		std::cin >> q[i].v;
		q[i].v ++;
		q[i].id = i;
	}
	vector<ll>tr(n + 5, 0);
	std::sort(q + 1, q + 1 + n, [&](sq x, sq y)->bool{
		return x.v < y.v;
	});
	q[1].k = 1;
	for (ll i = 2; i <= n; i++) {
		if (q[i].v == q[i - 1].v) {
			q[i].k = q[i - 1].k;
		} else {
			q[i].k = q[i - 1].k + 1;
		}
	}
	ll tot = q[n].k;
	std::sort(q + 1, q + 1 + n, [&](sq x, sq y)->bool{
		return x.id < y.id;
	});//离散化
	ll ans = 0;
	auto lowbit = [&](ll x) ->ll {
		return x & -x;
	};
	auto add = [&](ll idx, ll v)->void {
		for (; idx <= tot; idx += lowbit(idx)) {
			tr[idx] += v;
		}
	};
	auto query = [&](ll idx) -> ll{
		ll ret = 0;
		for (; idx >= 1; idx -= lowbit(idx))ret += tr[idx];
		return ret;
	};

	for (ll i = n; i >= 1; i--) {
		ans += query(q[i].k - 1) * i;
		add(q[i].k, n - i + 1);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


/*第二种离散化方式*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n; std::map<ll, ll>sk;
void solve() {
	std::cin >> n;
	vector<ll>q(n + 5, 0), s(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		std::cin >> q[i];
		s[i] = q[i];
	}
	std::sort(s.begin() + 1, s.begin() + 1 + n);
	ll len = unique(s.begin() + 1, s.begin() + 1 + n) - s.begin();
	len--;
	for (ll i = 1; i <= len; i++) {
		sk[s[i]] = i;
	}
	vector<ll>tr(n + 5, 0);
	auto lowbit = [&](ll x) ->ll {
		return x & -x;
	};
	auto add = [&](ll idx, ll v)->void {
		for (; idx <= n; idx += lowbit(idx)) {
			tr[idx] += v;
		}
	};
	auto query = [&](ll idx) -> ll{
		ll ret = 0;
		for (; idx >= 1; idx -= lowbit(idx))ret += tr[idx];
		return ret;
	};
	ll ans = 0;
	for (ll i = n; i >= 1; i--) {
		ans += query(sk[q[i]] - 1) * i;
		add(sk[q[i]], n - i + 1);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


