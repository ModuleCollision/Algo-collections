#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct edge {
	ll v; ll w; ll nx;
} e[maxn];
ll head[maxn]; bool vis[maxn]; ll tot[maxn], cnt = 0;
ll ans, dis[maxn];

void add(ll u, ll v, ll w) {
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].nx = head[u]; head[u] = cnt++;
}
void solve() {
	queue<ll>q;
	ll n, m; std::cin >> n >> m; std::fill(head, head + 1 + n, -1);
	std::fill(dis, dis + 1 + n, -inf);
	for (ll i = 1; i <= m; i++) {
		ll op, x, y, z; std::cin >> op;
		if (op == 1) {
			cin >> x >> y >> z;
			add(y, x, z);
		} else if (op == 2) {
			cin >> x >> y >> z;
			add(x, y, -z);
		} else {
			cin >> x >> y;
			add(x, y, 0); add(y, x, 0);
		}
	}
	vector<ll>tot(n + 5, 0);
	for (ll i = 1; i <= n; i++)add(0, i, 0);
	dis[0] = 0; vis[0] = 1;
	q.push(0);
	while (q.size()) {
		auto u = q.front(); q.pop();
		vis[u] = 0;
		for (ll j = head[u]; j != -1; j = e[j].nx) {
			ll v = e[j].v, w = e[j].w;
			if (dis[u] + w > dis[v]) {
				dis[v] = dis[u] + w;
				if (not vis[v]) {
					vis[v] = 1; q.push(v); tot[v]++;
					if (tot[v] >= n) {
						puts("No"); return;
					}
				}
			}
		}
	}
	puts("Yes");
}
signed main() {

	solve();
}