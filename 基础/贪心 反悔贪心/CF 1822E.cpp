/*也可以通过模拟 + 贪心解决*/
/*每次拿出最大的重合对数最大的两个字母*/
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

i64 n; char s[maxn];
struct sq {
	i64 v; i64 idx;
	bool operator<(const sq &b)const {
		return v < b.v;
	}
};
void solve() {
	std::cin >> n >> (s + 1);
	vector<i64>cnt(30, 0); i64 k[30][30];
	memset(k, 0, sizeof(k));
	if (n & 1) {
		puts("-1"); return;
	}
	for (i64 i = 1; i <= n / 2; i++) {
		i64 l = s[i] - 'a' + 1, r = s[n - i + 1] - 'a' + 1;
		k[l][r]++;
		if (l == r) {
			cnt[l]++;
		}
	}
	priority_queue<sq>q;
	for (i64 i = 0; i < 26; i++) {
		if (cnt[i])
			q.push({cnt[i], i});
	}
	i64 ans = 0;
	while (q.size() >= 2) {
		auto it1 = q.top(); q.pop();
		auto it2 = q.top(); q.pop();
		i64 v1 = it1.v, idx1 = it1.idx;
		i64 v2 = it2.v, idx2 = it2.idx;
		it1.v--; it2.v--;
		ans++;
		k[idx1][idx2]++;
		k[idx2][idx1]++;
		if (it1.v)q.push(it1);
		if (it2.v)q.push(it2);
	}
	if (not q.size()) {
		cout << ans << endl;
		return;
	}
	i64 v = q.top().v, idx = q.top().idx;
	for (i64 i = 0; i < 26; i++) {
		for (i64 j = 0; j < 26; j++) {
			if (i == idx or j == idx or i == j)continue;
			i64 ks = min(v, k[i][j]);
			k[i][j] -= ks; v -= ks;
			ans += ks;
			if (not v) {
				cout << ans << endl; return;
			}
		}
	}
	puts("-1"); return;
}
i64 T;
signed main() {
	std::cin >> T;
	while (T--)
		solve();
}
