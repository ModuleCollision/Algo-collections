/*并查集+哈希表*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
struct dsu {
	vector<int>fa;
	void init(int n) {
		fa.reserve(n + 5);
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	int find(int x) {
		while (fa[x] != x) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}
	void merge(int x, int y) {
		int x_ = find(x);
		int y_ = find(y);
		fa[x_] = y_;
		return;
	}
} dsu;
int cn[maxn];
bool vis[maxn]; int prime[maxn], cnt = 0;
void seieve() {
	for (int i = 2; i <= 1e6; i++) {
		if (!vis[i]) {
			prime[++cnt] = i;
		}
		for (int j = 1; j <= cnt and prime[j]*i <= 1e6; j++) {
			vis[prime[j]*i] = 1;
			if (i % prime[j] == 0) {
				break;
			}
		}
	}
}
int n, w[maxn];
int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}
signed main() {
	seieve();
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	dsu.init(n);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; std::cin >> x >> y;
		if (vis[gcd(w[x],w[y])]) {
			dsu.merge(x, y);
		}
	}
	int ans = -0x3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		dsu.fa[i] = dsu.find(i);
		cn[dsu.fa[i]]++;
		ans = max(ans, cn[dsu.fa[i]]);
	}
	cout << ans << endl;
}


