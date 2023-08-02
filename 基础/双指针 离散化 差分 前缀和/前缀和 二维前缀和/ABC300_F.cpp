/*枚举 + 前缀和*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, M, K;
string s;
void solve() {
	std::cin >> N >> M >> K >> s;
	vector<ll>idx;
	for (ll i = 0; i < N; i++) {
		if (s[i] == 'x')idx.push_back(i);
	}
	ll sz = idx.size();
	ll res = inf;
	auto get = [&](ll i) {
		ll ans = 0, tmp = K;
		ans += N - 1 - idx[i] + 1;
		tmp -= sz - 1 - i + 1;
		ans += tmp / sz * N;
		tmp %= sz;
		tmp--;
		if (tmp >= 0) ans += idx[tmp] + 1;
		return min(ans, N * M);
	};
	for (ll i = 0; i < sz; i++) {
		res = min(res, get(i));
	}
	cout << res << endl;
}
signed main() {
	solve();
}