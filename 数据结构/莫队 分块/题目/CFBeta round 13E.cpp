#include<bits/stdc++.h>
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
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 a[maxn], n, m, len, tot;
i64 nxt[maxn], be[maxn], L[maxn], R[maxn], dp[maxn];
void build() {
  len = sqrt(n); tot = (n + len - 1) / len;
  for (i64 i = 1; i <= tot; i++) {
    L[i] = (i - 1) * len + 1, R[i] = (i) * len;
  }
  R[tot] = n;
  for (i64 i = 1; i <= n; i++) {
    be[i] = (i + len - 1) / len;
  }
}
void update(i64 i) {
  if (i + a[i] > n or be[i] != be[i + a[i]]) {
    nxt[i] = i; dp[i] = 0;
  } else {
    nxt[i] = nxt[i + a[i]];
    dp[i] = dp[i + a[i]] + 1;
  }
}
void solve() {
  cin >> n >> m;
  for (i64 i = 1; i <= n; i++) {
    cin >> a[i];
  }
  build();
  for (i64 i = n; i >= 1; i--)update(i);
  /*for (int i = 1; i <= n; i++) {
    cout << nxt[i] << " \n"[i == n];
  }*/
  while (m--) {
    i64 op, p; cin >> op >> p;
    if (op == 0) {
      i64 v; cin >> v; a[p] = v;
      for (i64 i = p; i >= L[be[p]]; i--) {
        update(i);
      }
    } else {
      i64 ans = 0; i64 nx = 0;
      for (; p <= n; p = nx + a[nx]) {
        ans += dp[p] + 1;
        nx = nxt[p];
        //  cout << "#" << nx << endl;
      }
      cout << nx << " " << ans << "\n";
    }
  }
}
signed main() {
  solve();
}