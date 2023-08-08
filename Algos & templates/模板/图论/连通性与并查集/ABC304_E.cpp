#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll N, M; std::cin >> N >> M;
	vector<ll>fa(N + 5, 0);
	for (ll i = 1; i <= N; i++)fa[i] = i;
	auto find = [&](ll x)->ll{
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	};
	auto merge = [&](ll x, ll y) {
		ll a = find(x), b = find(y);
		if (a == b)return;
		fa[a] = b;
	};
	auto same = [&](ll x, ll y)->bool {
		return find(x) == find(y);
	};
	for (ll i = 1; i <= M; i++) {
		ll u, v; std::cin >> u >> v;
		merge(u, v);
	}
	ll K; std::cin >> K;
	vector<pair<ll, ll>>s(K + 5);
	std::set<pair<ll, ll>>w;
	for (ll i = 1; i <= K; i++) {
		std::cin >> s[i].first >> s[i].second;
		ll a = find(s[i].first), b = find(s[i].second);
		if (a > b)swap(a, b);
		w.insert({a, b});
	}
	ll Q; std::cin >> Q;
	while (Q--) {
		ll p, q; std::cin >> p >> q;
		ll a = find(p), b = find(q);
		if (a > b)swap(a, b);
		if (w.count({a, b}))puts("No");
		else puts("Yes");
	}
}
signed main() {
	solve();
}