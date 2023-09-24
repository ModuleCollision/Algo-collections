#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll w; ll id;
} A[maxn];
void solve() {
	auto inv = [&](ll x) {
		ll b = mod - 2, a = x; ll ret = 1;
		while (b) {
			if (b & 1) {
				ret = ret * a % mod;
			}
			a = a * a % mod;
			b >>= 1;
		}
		return ret;
	};
	ll N, M, K; std::cin >> N >> M >> K;
	vector<ll>idx;
	for (ll i = 1; i <= N; i++) {
		std::cin >> A[i].w;
		A[i].id = i;
		if (not A[i].w)idx.push_back(i);
	}
	std::map<ll, ll>tot;
	for (ll i = 1; i <= M; i++) {
		for (auto c : idx) {
			A[c].w = i;
		}
		std::sort(A + 1, A + 1 + N, [&](sq x, sq y)->bool{
			return x.w < y.w;
		});
		tot[A[K].w]++;
		std::sort(A + 1, A + 1 + N, [&](sq x, sq y)->bool{
			return x.id < y.id;
		});
	}
	ll ans = 0;
	for (auto s : tot) {
		ll v = s.first, cnt = s.second;
		ans += v % mod * cnt % mod * inv(M) % mod;
	}
	cout << ans % mod << endl;
}
signed main() {
	solve();
}