#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	int n; std::cin >> n;
	string s; cin >> s;
	map<int, vector<int>>ks;
	for (int i = 0; i < n; i++) {
		ks[(int)(s[i] - 'a')].push_back(i);
	}
	vector<int>st(30, 0);
	for (int i = 0; i < 26; i++)st[i] = i;
	std::sort(st.begin(), st.begin() + 26, [&](int x, int y)->bool{
		return ks[x].size() > ks[y].size();
	});
	int mx = 0; string ans;
	for (int cnt = 1; cnt <= 26; cnt++) {
		if (n % cnt == 0) {
			int p = n / cnt; int tmp = 0;
			for (int i = 0; i < cnt; i++) {
				tmp += min(p, (int)ks[st[i]].size());
			}
			if (tmp >= mx) {
				mx = tmp; vector<ll>pp;
				string res(n + 5, ' ');
				for (int i = 0; i < cnt; i++) {
					for (int j = 0; j < p; j++) {
						if (j < (int)ks[st[i]].size()) {
							res[ks[st[i]][j]] = (char((int)st[i] + 'a'));
						} else {
							pp.push_back(st[i]);
						}
					}
				}
				for (int i = 0; i < n; i++) {
					if (res[i] == ' ') {
						res[i] = char(pp.back() + 'a');
						pp.pop_back();
					}
				}
				ans = res;
			}
		}
	}
	cout << n - mx << endl;
	for (int i = 0; i < n; i++) {
		putchar(ans[i]);
	}
	cout << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--) {
		solve();
	}
}