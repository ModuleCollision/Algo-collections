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
	int n; cin >> n;
	vector<int>A(n + 5); vector<int>d(n + 5, 0);
	for (int i = 1; i <= n; i++) {
		cin >> A[i]; d[A[i]]++;
	}
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (not d[i]) {
			q.push(i);
		}
	}
	while (q.size()) {
		int cur = q.front(); q.pop();
		d[A[cur]]--;
		if (not d[A[cur]]) {
			q.push(A[cur]);
		}
	}
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i]) {
			cur = i; break;
		}
	}
	vector<int>ans = {cur}; int nxt = A[cur];
	while (nxt != cur) {
		ans.push_back(nxt);
		nxt = A[nxt];
	}
	cout << ans.size() << '\n';
	for (auto c : ans)cout << c << ' ';
	cout << '\n';
}
signed main() {
	solve();
}