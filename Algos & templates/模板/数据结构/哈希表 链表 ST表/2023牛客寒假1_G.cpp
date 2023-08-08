/*链表+set*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
	int nx; int pre;
} p[maxn];
set<int>st; int a[maxn];
void solve() {
	int n, m; ll ans = 0;
	cin >> n >> m;
	vector<int>cnt(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; ans += a[i];
		p[i].pre = i - 1;
		p[i].nx = i + 1;
		cnt[i] = 15;
		st.insert(i);
	}
	auto del = [&](int x) {
		p[p[x].nx].pre = p[x].pre;
		p[p[x].pre].nx = p[x].nx;
		st.erase(x);
	};
	auto f = [&](int x) {
		return round(10 * sqrt(x));
	};
	p[n].nx = 0;
	st.insert(maxn + 5);
	for (int i = 1; i <= m; i++) {
		int op; std::cin >> op;
		if (op == 1) {
			int l, r, k;
			std::cin >> l >> r >> k;
			int e = *st.lower_bound(l);
			for (int j = e; j and j <= r; j = p[j].nx) {
				if (cnt[j] <= 0)continue;
				int ned = min(k, cnt[j]);
				for (int kk = 1; kk <= ned; kk++) {
					cnt[j]--;
					ans -= a[j];
					a[j] = f(a[j]);
					ans += a[j];
				}
				if (cnt[j] <= 0)del(j);
			}
		} else {
			cout << ans << endl;
		}
	}
}
signed main() {
	solve();
}