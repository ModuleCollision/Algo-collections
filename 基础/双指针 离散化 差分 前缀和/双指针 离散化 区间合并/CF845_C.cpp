/*双指针维护一个定值*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
int n, m;
void solve() {
	std::cin >> n >> m;
	vector<int>a(n + 5, 0), cnt(m + 5, 0);
	int sum = 0;
	auto add = [&](int a) {
		for (int i = 1; i * i <= a; i++) {
			if (a % i == 0) {
				if (i <= m) {
					++cnt[i];
				}
				if (cnt[i] == 1) {
					sum++;
				}
			}
			if (a / i <= m and i != a / i) {
				++cnt[a / i]; if (cnt[a / i] == 1) {
					sum++;
				}
			}
		}
	};
	auto del = [&](int a) {
		for (int i = 1; i * i <= a; i++) {
			if (a % i == 0) {
				if (i <= m) {
					--cnt[i];
					if (cnt[i] == 0) {
						sum--;
					}
				}
			} if (a / i <= m and i != a / i) {
				--cnt[a / i]; if (cnt[a / i] == 0) {
					sum--;
				}
			}
		}
	};
	int ans = inf; for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	std::sort(a.begin() + 1, a.begin() + 1 + n);
	for (int i = 1, j = 0; i <= n; i++) {
		del(a[i - 1]);
		while (j + 1 <= n and sum < m) {
			add(a[++j]);
		}
		if (sum == m) {
			ans = min(ans, a[j] - a[i]);
		}
	}
	if (ans == inf) {
		puts("-1");
	} else {
		cout << ans << endl;
	}
}
signed main() {
	int T; cin >> T;
	while (T--) {
		solve();
	}
}