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

i64 n;
struct sq {
	i64 v; i64 k; i64 id;
} q[maxn];
void solve() {
	std::cin >> n;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> q[i].v;
		q[i].v ++;
		q[i].id = i;
	}
	vector<i64>tr(n + 5, 0);
	std::sort(q + 1, q + 1 + n, [&](sq x, sq y)->bool{
		return x.v < y.v;
	});
	q[1].k = 1;
	for (i64 i = 2; i <= n; i++) {
		if (q[i].v == q[i - 1].v) {
			q[i].k = q[i - 1].k;
		} else {
			q[i].k = q[i - 1].k + 1;
		}
	}
	i64 tot = q[n].k;
	std::sort(q + 1, q + 1 + n, [&](sq x, sq y)->bool{
		return x.id < y.id;
	});//离散化
	i64 ans = 0;
	auto lowbit = [&](i64 x) ->i64 {
		return x & -x;
	};
	auto add = [&](i64 idx, i64 v)->void {
		for (; idx <= tot; idx += lowbit(idx)) {
			tr[idx] += v;
		}
	};
	auto query = [&](i64 idx) -> i64{
		i64 ret = 0;
		for (; idx >= 1; idx -= lowbit(idx))ret += tr[idx];
		return ret;
	};

	for (i64 i = n; i >= 1; i--) {
		ans += query(q[i].k - 1) * i;
		add(q[i].k, n - i + 1);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


/*第二种离散化方式*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long i64;
typedef long double lb;
const i64 maxn = 2e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
const i64 mod = 998244353;
i64 n; std::map<i64, i64>sk;
void solve() {
	std::cin >> n;
	vector<i64>q(n + 5, 0), s(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> q[i];
		s[i] = q[i];
	}
	std::sort(s.begin() + 1, s.begin() + 1 + n);
	i64 len = unique(s.begin() + 1, s.begin() + 1 + n) - s.begin();
	len--;
	for (i64 i = 1; i <= len; i++) {
		sk[s[i]] = i;
	}
	vector<i64>tr(n + 5, 0);
	auto lowbit = [&](i64 x) ->i64 {
		return x & -x;
	};
	auto add = [&](i64 idx, i64 v)->void {
		for (; idx <= n; idx += lowbit(idx)) {
			tr[idx] += v;
		}
	};
	auto query = [&](i64 idx) -> i64{
		i64 ret = 0;
		for (; idx >= 1; idx -= lowbit(idx))ret += tr[idx];
		return ret;
	};
	i64 ans = 0;
	for (i64 i = n; i >= 1; i--) {
		ans += query(sk[q[i]] - 1) * i;
		add(sk[q[i]], n - i + 1);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


