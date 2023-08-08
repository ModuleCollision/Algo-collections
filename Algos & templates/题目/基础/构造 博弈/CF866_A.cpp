#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0);
	map<ll, ll>R, L;
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i];
		R[A[i]] = i; if (not L.count(A[i]))L[A[i]] = i;
	}
	auto cal = [&]() {
		vector<ll>s(A);
		std::sort(s.begin() + 1, s.begin() + 1 + n);
		ll len = unique(s.begin() + 1, s.begin() + 1 + n) - s.begin() - 1;
		for (ll i = 1; i <= len; i++) {
			if (s[i] != i - 1)return i - 1;
		}
		return len;
	};
	ll mex = cal();
	if (L.count(mex + 1)) {
		ll l = L[mex + 1], r = R[mex + 1];
		for (ll i = l; i <= r; i++) {
			A[i] = mex;
		}
		ll mx = cal();
		if (mx == mex + 1) {
			puts("YES"); return;
		}
		puts("NO");
	} else {
		for (ll i = 1; i <= n; i++) {
			if (A[i] > mex or L[A[i]] != R[A[i]]) {
				puts("YES"); return;
			}
		}
		puts("NO");
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}