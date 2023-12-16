/*字典树+拓扑排序*/
/*一个字符串用于确立大小关系,如果出现了环即为自相矛盾,这里采用拓扑排序判环*/
/*显然,字典树用于确立前缀关系*/
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


bool ed[maxn];
i64 tr[maxn][30], tot = 0;
i64 d[30]; vector<i64>G[30];
vector<string>ans;
bool top_sort() {
	i64 cnt = 0;
	queue<i64>q;
	for (i64 i = 0; i < 26; i++) {
		if (d[i] == 0) {
			q.push(i);
		}
	}
	while (q.size()) {
		auto cur = q.front(); q.pop();
		cnt++;
		for (auto c : G[cur]) {
			d[c]--;
			if (d[c] == 0) {
				q.push(c);
			}
		}
	}
	return cnt == 26;
}
void insert(string s) {
	i64 u = 0;
	for (auto c : s) {
		i64 cur = c - 'a';
		if (not tr[u][cur]) {
			tr[u][cur] = ++tot;
		}
		u = tr[u][cur];
	}
	ed[u] = true;
}
bool check(string s) {
	i64 u = 0;
	for (i64 i = 0; i < s.size(); i++) {
		for (i64 j = 0; j < 26; j++) {
			if (j == s[i] - 'a') {
				continue;
			}
			if (tr[u][j]) {
				G[s[i] - 'a'].push_back(j);
				d[j]++;
			}//同一前缀在本位的不同字母
		}
		/*字典序最小则说明对于这个字符串,对于任意重合前缀的字符串,我们的该位置字符字典序必然小*/
		u = tr[u][s[i] - 'a'];
		if (ed[u] and i != s.size() - 1)return false;
	}
	return top_sort();
}
i64 N; string s[maxn];
void solve() {
	std::cin >> N;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> s[i];
		insert(s[i]);
	}
	for (i64 i = 1; i <= N; i++) {
		memset(d, 0, sizeof(d));
		for (i64 j = 0; j < 26; j++)G[j].clear();
		if (check(s[i])) {
			ans.push_back(s[i]);
		}
	}
	cout << ans.size() << endl;
	for (auto v : ans) {
		cout << v << endl;
	}
}
signed main() {
	solve();
}