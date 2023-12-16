/*300兆字节 1- 2 秒*/

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

int nex[maxn][26], cnt = 0;
bool exist[maxn];
set<int>w[maxn];
void insert(string s, int l, int id) {
	int p = 0;
	for (int i = 0; i < l; i++) {
		int c = s[i] - 'a';
		if (!nex[p][c]) {
			nex[p][c] = ++cnt;

		}
		w[nex[p][c]].insert(id);
		p = nex[p][c];
	}
	exist[p] = 1;
}
int query(string s, int id) {
	int len = (int)s.length(), ret = 0, p = 0;
	for (int i = 0; i < len; i++) {
		int c = s[i] - 'a';
		if (nex[p][c] and not(w[nex[p][c]].count(id) and w[nex[p][c]].size() == 1)) {
			ret++;
			p = nex[p][c];
		} else {
			break;
		}
	}
	return ret;
}
void solve() {
	int N; cin >> N;
	vector<string>p(N + 5);
	for (i64 i = 1; i <= N; i++) {
		cin >> p[i];
		insert(p[i], (int)p[i].length(), i);
	}
	for (i64 i = 1; i <= N; i++) {
		cout << query(p[i], i) << endl;
	}
}
signed main() {
	solve();
}