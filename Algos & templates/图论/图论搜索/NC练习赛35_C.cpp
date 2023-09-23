#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
ll A, B; std::map<ll, ll>dis;
void solve() {
	std::cin >> A >> B;
	dis.clear();
	queue<ll>q;
	dis[A] = 0;
	auto f = [&](ll x) {
		return (x % mod * x % mod * x % mod + x % mod * x) % mod;
	};
	auto g = [&](ll x) {
		return (((x % mod * x % mod * x) % mod - (x * x) % mod) % mod + mod) % mod;
	};
	q.push(A);
	while (not q.empty()) {
		auto cur = q.front(); q.pop();
		if (cur == B) {
			cout << dis[cur] << endl;
			return;
		}
		ll nxt = f(cur);
		if (dis.count(nxt))continue;
		dis[nxt] = dis[cur] + 1;
		q.push(nxt);
		nxt = g(cur);
		if (dis.count(nxt))continue;
		dis[nxt] = dis[cur] + 1;
		q.push(nxt);
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}