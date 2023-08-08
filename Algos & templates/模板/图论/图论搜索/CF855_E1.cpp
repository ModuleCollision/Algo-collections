#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	string t; cin >> t;
	if (n <= 7) {
		set<string> was;
		queue<string> q; q.push(s);
		was.insert(s);
		auto add = [&](string  s, int i, int j) {
			if (i >= 0 and i < j and j < n) {
				swap(s[i], s[j]);
				if (!was.count(s)) {
					was.insert(s);
					q.push(s);
				}
				swap(s[i], s[j]);
			}

		};

		while (!q.empty()) {
			s = q.front(); q.pop();
			for (int i = 0; i < n; ++i) {
				add(s, i, i + k);
				add(s, i, i + k + 1);
				add(s, i - k, i);
				add(s, i - k - 1, i);
			}
		}
		puts(was.count(t) ? "Yes" : "No");
		return;
	}
	map<char, int> cnt;
	for (char c : s) {
		cnt[c]++;
	}

	for (char c : t) {
		cnt[c]--;
	}
	bool f = true;
	for (auto [c, x] : cnt) {
		f &= (x == 0);
	}
	puts(f ? "Yes" : "No");
}

signed main() {
	int T; std::cin >> T;
	while (T--) {
		solve();
	}
}