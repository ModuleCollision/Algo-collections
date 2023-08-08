#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
ll N;
void solve() {
	std::cin >> N;
	vector<ll>A(N + 5), B(N + 5);
	for (ll i = 1; i <= N; i++) {
		std::cin >> A[i];
	}
	for (ll i = 1; i <= N; i++) {
		std::cin >> B[i];
	}
	vector<ll>C = A, D = B;
	std::sort(C.begin() + 1, C.begin() + 1 + N);
	std::sort(D.begin() + 1, D.begin() + 1 + N);
	if (C != D) {
		puts("No"); return;
	}
	for (ll i = 2; i <= N; i++) {
		if (C[i] == C[i - 1]) {
			puts("Yes"); return;
		}
	}
	vector<ll>tr1(maxn), tr2(maxn);
	auto add1 = [&](ll id, ll v) {
		for (; id <= 1e6; id += (id & -id)) {
			tr1[id] += v;
		}
	};
	auto query1 = [&](ll id, ll v) {
		ll ret = 0;
		for (; id >= 1; id -= (id & -id)) {
			ret += tr1[id];
		}
		return ret;
	};
	auto add2 = [&](ll id, ll v) {
		for (; id <= 1e6; id += (id & -id)) {
			tr2[id] += v;
		}
	};
	auto query2 = [&](ll id, ll v) {
		ll ret = 0;
		for (; id >= 1; id -= (id & -id)) {
			ret += tr2[id];
		}
		return ret;
	};
	ll ans = 0;
	for (ll i = N; i >= 1; i--) {
		ans += query1(A[i] - 1, 1);
		add1(A[i], 1);
	}
	for (ll i = N; i >= 1; i--) {
		ans += query2(B[i] - 1, 1);
		add2(B[i], 1);
	}
	puts(ans % 2 ? "No" : "Yes");
}
signed main() {
	solve();
}