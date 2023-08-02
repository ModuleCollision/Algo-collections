#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const int maxn = 4e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	int n, r, g, b;
	cin >> n >> r >> g >> b;
	if ((n & 1) && (r + g + b) & 1) cout << "Bob" << endl;
	else cout << "Alice" << endl;
	return ;
}
signed main() {
	int T; cin >> T;
	while (T--) {
		solve();
	}
}