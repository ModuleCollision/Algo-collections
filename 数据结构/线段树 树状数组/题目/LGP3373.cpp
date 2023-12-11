#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll mul = 1; ll add; ll sum;
	ll l; ll r;
} tr[maxn * 4];
ll n, q, m;
ll a[maxn];
void pushup(ll u) {
	tr[u].sum = (tr[u << 1].sum % m + tr[u << 1 | 1].sum) % m;
	return;
}
void build(ll u, ll l, ll r) {
	tr[u].l = l; tr[u].r = r;
	if (l == r) {
		tr[u].mul = 1; tr[u].add = 0;
		tr[u].sum = a[l]; return;
	}
	ll mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(ll u) {
	if (tr[u].mul != 1) {
		ll mu = tr[u].mul;
		tr[u].mul = 1;
		tr[u << 1].mul = tr[u << 1].mul % m * mu % m; tr[u << 1 | 1].mul = tr[u << 1 | 1].mul % m * mu % m;
		tr[u << 1].sum = (tr[u << 1].sum % m * mu) % m;
		tr[u << 1 | 1].sum = (tr[u << 1 | 1].sum % m * mu) % m;
		tr[u << 1].add = (tr[u << 1].add % m * mu) % m;
		tr[u << 1 | 1].add = (tr[u << 1 | 1].add % m * mu) % m;
	}
	if (tr[u].add) {
		ll ad = tr[u].add;
		tr[u].add = 0;
		tr[u << 1].add = (tr[u << 1].add + ad) % m;
		tr[u << 1 | 1].add = (tr[u << 1 | 1].add % m + ad) % m;
		ll len1 = (tr[u << 1].r - tr[u << 1].l + 1);
		ll len2 = (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
		tr[u << 1].sum = (tr[u << 1].sum % m + len1 % m * ad) % m;
		tr[u << 1 | 1].sum = (tr[u << 1 | 1].sum % m + len2 % m * ad) % m;
	}
}
void multiply(ll u, ll l, ll r, ll v) {
	if (tr[u].l >= l and tr[u].r <= r) {
		tr[u].mul = (tr[u].mul % m * v) % m;
		tr[u].add = (tr[u].add % m * v) % m;
		tr[u].sum = (tr[u].sum % m * v) % m;
		return;
	}
	pushdown(u);
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)multiply(u << 1, l, r, v);
	if (r > mid)multiply(u << 1 | 1, l, r, v);
	pushup(u);
}
void plu(ll u, ll l, ll r, ll v) {
	if (tr[u].l >= l and tr[u].r <= r) {
		tr[u].add = (tr[u].add % m + v) % m;
		tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) % m * v) % m;
		return;
	}
	pushdown(u);
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)plu(u << 1, l, r, v);
	if (r > mid)plu(u << 1 | 1, l, r, v);
	pushup(u);
}
ll query_sum(ll u, ll l, ll r) {
	if (tr[u].l >= l and tr[u].r <= r) {
		return tr[u].sum % m;
	}
	pushdown(u);
	ll ret = 0;
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)ret = (ret % m + query_sum(u << 1, l, r)) % m;
	if (r > mid)ret = (ret % m + query_sum(u << 1 | 1, l, r)) % m;
	return ret % m;
}
void solve() {
	std::cin >> n >> q >> m;
	for (ll i = 1; i <= n; i++)cin >> a[i];
	build(1, 1, n);
	while (q--) {
		ll opt; std::cin >> opt;
		if (opt == 1) {
			ll x, y, k; std::cin >> x >> y >> k;
			multiply(1, x, y, k);
		} else if (opt == 2) {
			ll x, y, k; std::cin >> x >> y >> k;
			plu(1, x, y, k);
		} else {
			ll x, y; cin >> x >> y;
			cout << query_sum(1, x, y) % m << endl;
		}
	}
}
signed main() {
	solve();
}




/*多组Test下使用封装数据结构, 在函数中开对象,避免暴力清空数组造成时间浪费*/

/*STL: 数据结构 cin cout function类 lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std,避免命名空间污染*/

/*数学先打表, 后对拍, 图论只会暴力就bitset搞*/

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

constexpr i64 mod = 998244353;
constexpr i64 maxn = 1e5 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct Node {
  i64 l, r; // 所维护的区间范围
  i64 ls, rs;// 左右孩子
  i64 mul, add, sum;

} tr[maxn * 2 + 5]; i64 n, q, m, tot = 1, a[maxn];
/*动态开点只需开 2 * n 的空间*/
void pushup(i64 p) {
  tr[p].sum = (tr[tr[p].ls].sum % m + tr[tr[p].rs].sum) % m;
  return;
}
void pushdown(i64 p) {
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  if (not tr[p].ls) {
    tr[p].ls = ++tot;
    tr[tot].l = tr[p].l;
    tr[tot].r = mid;
    tr[tr[p].ls].mul = 1;
  }
  if (not tr[p].rs) {
    tr[p].rs = ++tot;
    tr[tot].l = mid + 1;
    tr[tot].r = tr[p].r;
    tr[tr[p].rs].mul = 1;
  }
  if (tr[p].mul != 1) {
    i64 mu = tr[p].mul;
    tr[p].mul = 1;
    tr[tr[p].ls].mul = tr[tr[p].ls].mul * mu % m;
    tr[tr[p].rs].mul = (tr[tr[p].rs].mul * mu % m);
    tr[tr[p].ls].sum = (tr[tr[p].ls].sum % m * mu) % m;
    tr[tr[p].rs].sum = (tr[tr[p].rs].sum % m * mu) % m;
    tr[tr[p].ls].add = (tr[tr[p].ls].add % m * mu) % m;
    tr[tr[p].rs].add = (tr[tr[p].rs].add % m * mu) % m;
  }
  if (tr[p].add) {
    i64 ad = tr[p].add;
    tr[p].add = 0;
    tr[tr[p].ls].add = (tr[tr[p].ls].add + ad) % m;
    tr[tr[p].rs].add = (tr[tr[p].rs].add + ad) % m;
    i64 mid = (tr[p].l + tr[p].r) >> 1;
    i64 len1 = mid - tr[p].l + 1; i64 len2 = tr[p].r - mid;
    tr[tr[p].ls].sum = (tr[tr[p].ls].sum % m + len1 % m * ad) % m;
    tr[tr[p].rs].sum = (tr[tr[p].rs].sum % m + len2 % m * ad) % m;
  }
}
void modify1(i64 p, i64 l, i64 r, i64 v) {
  if (tr[p].l >= l and tr[p].r <= r) {
    tr[p].mul = (tr[p].mul % m * v) % m;
    tr[p].add = (tr[p].add % m * v) % m;
    tr[p].sum = (tr[p].sum % m * v) % m;
    return;
  }
  pushdown(p);
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)modify1(tr[p].ls, l, r, v);
  if (r > mid)modify1(tr[p].rs, l, r, v);
  pushup(p);
}

void modify2(i64 p, i64 l, i64 r, i64 v) {
  if (tr[p].l >= l and tr[p].r <= r) {
    tr[p].add = (tr[p].add % m + v) % m;
    tr[p].sum = (tr[p].sum + (tr[p].r - tr[p].l + 1) % m * v) % m;
    return;
  }
  pushdown(p);
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)modify2(tr[p].ls, l, r, v);
  if (r > mid)modify2(tr[p].rs, l, r, v);
  pushup(p);
}

i64 query(i64 u, i64 l, i64 r) {
  if (tr[u].l >= l and tr[u].r <= r) {
    return tr[u].sum % m;
  }
  pushdown(u);
  i64 ret = 0;
  i64 mid = (tr[u].l + tr[u].r) >> 1;
  if (l <= mid)ret = (ret % m + query(tr[u].ls, l, r)) % m;
  if (r > mid)ret = (ret % m + query(tr[u].rs, l, r)) % m;
  return ret % m;
}
/*动态开点线段树*/
int main() {
  std::cin >> n >> q >> m;
  tr[1].l = 1, tr[1].r = n;
  tr[1].add = 0 , tr[1].mul = 1;
  /*建树利用单点修改的方式*/
  for (i64 i = 1; i <= n; i++)std::cin >> a[i], modify2(1, i, i, a[i]);
  while (q--) {
    i64 opt; std::cin >> opt;
    if (opt == 1) {
      i64 x, y, k; std::cin >> x >> y >> k;
      modify1(1, x, y, k);
    } else if (opt == 2) {
      i64 x, y, k; std::cin >> x >> y >> k;
      modify2(1, x, y, k);
    } else {
      i64 x, y; std::cin >> x >> y;
      std::cout << query(1, x, y) % m << "\n";
    }
  }
  return 0;
}
