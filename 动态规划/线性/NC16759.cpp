#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll dp[35][35][35][35];
vector<array<ll, 2>>dir = {{ -1, 0}, {0, -1}};
void solve() {
  ll n; std::cin >> n;
  vector A(n + 1, vector<ll>(n + 1, 0));
  ll x, y, z;
  while (cin >> x >> y >> z and (x and y and z)) {
    A[x][y] = z;
  }
  dp[1][1][1][1] = A[1][1];
  auto check = [&](ll x, ll y) {
    return x >= 1 and x <= n and y >= 1 and y <= n;
  };
  for (ll x1 = 1; x1 <= n; x1++) {
    for (ll y1 = 1; y1 <= n; y1++) {
      for (ll x2 = 1; x2 <= n; x2++) {
        for (ll y2 = 1; y2 <= n; y2++) {
          if (x1 == 1 and x2 == 1 and y1 == 1 and y2 == 1)continue;
          for (ll i = 0; i < 2; i++) {
            for (ll j = 0; j < 2; j++) {
              ll xx1 = x1 + dir[i][0], yy1 = y1 + dir[i][1];
              ll xx2 = x2 + dir[j][0], yy2 = y2 + dir[j][1];
              if (check(xx1, yy1) and check(xx2, yy2)) {
                dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[xx1][yy1][xx2][yy2] + A[x1][y1] + ((x1 != x2 or y1 != y2) ? A[x2][y2] : 0));
              }
            }
          }
        }
      }
    }
  }
  cout << dp[n][n][n][n] << endl;
}
signed main() {
  solve();
}