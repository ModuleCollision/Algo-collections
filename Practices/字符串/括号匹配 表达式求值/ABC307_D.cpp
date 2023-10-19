#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll N; std::string s;
	std::cin >> N >> s;
	s = " " + s;
	vector<char>ans; ll cnt = 0;
	for (ll i = 1; i <= N; i++) {
		if (s[i] == '(') {
			cnt++; ans.push_back(s[i]);
		} else if (s[i] == ')') {
			if (cnt) {
				cnt--;
				while (ans.back() != '(') {
					ans.pop_back();
				}
				ans.pop_back();
			} else {
				ans.push_back(s[i]);
			}
		} else {
			ans.push_back(s[i]);
		}
	}
	for (auto c : ans) {
		putchar(c);
	}
}
signed main() {
	solve();
}