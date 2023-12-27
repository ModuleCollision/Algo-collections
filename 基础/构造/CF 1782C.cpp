#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

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
				mx = tmp; vector<i64>pp;
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
	i64 T; std::cin >> T;
	while (T--) {
		solve();
	}
}