#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
	string s; cin >> s;
	ll fp = 0; std::map<ll, std::set<ll>>st;
	std::set<ll>ts;
	for (auto c : s) {
		if (c == '(') {
			fp++;
		} else if (isalpha(c)) {
			ll cur = c - 'a';
			if (ts.count(cur)) {
				puts("No"); return;
			} else {
				st[fp].insert(cur);
				ts.insert(cur);
			}
		} else {
			for (auto c : st[fp]) {
				ts.erase(c);
			}
			fp--;
		}
	}
	puts("Yes");
}
signed main() {
	solve();
}