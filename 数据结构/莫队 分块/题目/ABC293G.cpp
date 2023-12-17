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

struct query {
  i64 l; i64 r; i64 idx;
};
i64 cnt[maxn];
void solve() {
  i64 n, q; cin >> n >> q;
  vector<i64>A(n + 1, 0);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  vector<query>qs(q + 1);
  for (i64 i = 1; i <= q; i++) {
    cin >> qs[i].l >> qs[i].r;
    qs[i].idx = i;
  }
  i64 k = sqrt(n); vector<i64>ans(q + 1);
  sort(qs.begin() + 1, qs.begin() + 1 + q, [&](auto a, auto b)->bool{
    i64 x = (a.l - 1) / k + 1; i64 y = (b.l - 1) / k + 1;
    if (x == y)return a.r < b.r;
    return a.l < b.l;
  });
  i64 cur = 0;
  auto add = [&](i64 i) {
    cur += (cnt[A[i]] * (cnt[A[i]] - 1)) / 2;
    cnt[A[i]]++;
  };
  auto del = [&](i64 i) {
    cur -= ((cnt[A[i]] - 1) * (cnt[A[i]] - 2)) / 2;
    cnt[A[i]]--;
  };
  for (i64 i = 1, L = 1, R = 0; i <= q; i++) {
    while (R < qs[i].r) {
      add(++R);
    }
    while (L > qs[i].l) {
      add(--L);
    }
    while (R > qs[i].r) {
      del(R--);
    }
    while (L < qs[i].l) {
      del(L++);
    }
    ans[qs[i].idx] = cur;
  }
  for (i64 i = 1; i <= q; i++)cout << ans[i] << endl;

}
signed main() {

  solve();
}