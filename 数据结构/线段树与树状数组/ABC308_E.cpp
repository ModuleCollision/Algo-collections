#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll N; std::cin >> N;
	vector<ll>A(N + 5, 0);
	for (ll i = 1; i <= N; i++)std::cin >> A[i];
	string s; std::cin >> s;
	s = " " + s;
	std::map<pair<char, ll>, vector<ll>>st;
	for (ll i = 0; i < 3; i++) {
		st[ {'M', i}] = vector<ll>(N + 5, 0);
		st[ {'X', i}] = vector<ll>(N + 5, 0);
	}
	auto add = [&](char c, ll f, ll idx, ll v) {
		for (; idx <= N; idx += (idx & -idx)) {
			st[ {c, f}][idx] += v;
		}
	};
	auto query = [&](char c, ll f, ll l, ll r)->ll {
		ll v1 = 0, v2 = 0;
		l--;
		for (; r >= 1; r -= (r & -r)) {
			v1 += st[ {c, f}][r];
		}
		for (; l >= 1; l -= (l & -l)) {
			v2 += st[ {c, f}][l];
		}
		return v1 - v2;
	};
	for (ll i = 1; i <= N; i++) {
		if (s[i] == 'M' or s[i] == 'X') {
			add(s[i], A[i], i, 1);
		}
	}
	auto cal = [&](set<ll>t)->ll {
		vector<ll>tt;
		for (auto c : t)tt.push_back(c);
		for (ll i = 0; i < tt.size(); i++) {
			if (tt[i] != i)return i;
		}
		return tt.size();
	};
	ll ans = 0;
	for (ll i = 1; i <= N; i++) {
		if (s[i] == 'E') {
			for (ll j = 0; j < 3; j++) {
				for (ll k = 0; k < 3; k++) {
					std::set<ll>f;
					f.insert(A[i]); f.insert(j); f.insert(k);
					auto h1 = query('M', j, 1, i - 1);
					auto h2 = query('X', k, i + 1, N);
					ans += (h1 * h2) * cal(f);
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}