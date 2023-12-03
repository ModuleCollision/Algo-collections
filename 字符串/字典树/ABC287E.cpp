#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
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
	for (ll i = 1; i <= N; i++) {
		cin >> p[i];
		insert(p[i], (int)p[i].length(), i);
	}
	for (ll i = 1; i <= N; i++) {
		cout << query(p[i], i) << endl;
	}
}
signed main() {
	solve();
}