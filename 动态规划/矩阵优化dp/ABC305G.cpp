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

i64 fail[maxn]; bool idx[maxn];
i64 tr[maxn][2]; i64 tot = 0;
void insert(string s) {
  i64 u = 0; idx[u] = 0;
  for (i64 i = 0; i < s.size(); i++) {
    if (not tr[u][s[i] - 'a']) {
      tr[u][s[i] - 'a'] = ++tot;
      idx[tot] = 0;
    }
    u = tr[u][s[i] - 'a'];
  }
  idx[u] = 1;
}
void build() {
  queue<i64>q;
  for (i64 i = 0; i <= 1; i++) {
    if (tr[0][i])q.push(tr[0][i]);
  }
  while (q.size()) {
    i64 u = q.front(); q.pop();
    for (i64 i = 0; i <= 1; i++) {
      if (tr[u][i]) {
        fail[tr[u][i]] = tr[fail[u]][i];
        q.push(tr[u][i]);
      } else {
        tr[u][i] = tr[fail[u]][i];
      }
      idx[tr[u][i]] |= idx[fail[tr[u][i]]];
    }
  }
}
struct mat {
public:
  i64 n; i64 a[300][300];
  mat(i64 t) {
    n = t; for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < n; j++) {
        a[i][j] = 0;
      }
    }
  }
  mat operator*(const mat&b) {
    mat tmp(n);
    for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < n; j++) {
        for (i64 k = 0; k < n; k++) {
          tmp.a[i][j] = (tmp.a[i][j] % mod + a[i][k] % mod * b.a[k][j]) % mod;
        }
      }
    }
    return tmp;
  }
};
mat ksm(mat a, i64 b) {
  mat tmp(a.n);
  for (i64 i = 0; i < a.n; i++) {
    tmp.a[i][i] = 1;
  }
  while (b) {
    if (b & 1)tmp = tmp * a;
    a = a * a;
    b >>= 1;
  }
  return tmp;
}
void solve() {
  i64 n, m; string s;
  cin >> n >> m;
  for (i64 i = 0; i < m; i++) {
    cin >> s; insert(s);
  }
  build();
  mat ma(tot + 1);
  for (i64 i = 0; i <= tot; i++) {
    for (i64 j = 0; j <= 1; j++)
      ++ma.a[i][tr[i][j]];
  }
  i64 cnt = 0;
  for (i64 i = 0; i <= tot; i++)if (not idx[i])++cnt;
  mat tmp(cnt);
  i64 x = -1, y = 0;
  for (i64 i = 0; i <= tot; i++) {
    if (idx[i])continue;
    y = 0; x++;
    for (i64 j = 0; j <= tot; j++) {
      if (idx[j])continue;
      tmp.a[x][y] = ma.a[i][j];
      y++;
    }
  }
  auto res = ksm(tmp, n);
  i64 ans = 0;
  for (i64 i = 0; i < cnt; i++) {
    ans = (ans % mod + res.a[0][i]) % mod;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}