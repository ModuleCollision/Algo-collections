#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  int n, ans = 0; cin >> n;
  vector<int>a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; b[i] = a[i];
  }
  sort(b.begin() + 1, b.begin() + 1 + n);
  vector tr(5, vector<int>(5, 0));
  for (int i = 1; i <= n; i++) {
    tr[a[i]][b[i]] += 1;
  }
  for (int i = 1; i <= 4; i++) {
    for (int j = i + 1; j <= 4; j++) {
      int x = min({tr[i][j], tr[j][i]});
      ans += x;
      tr[i][j] -= x; tr[j][i] -= x;
    }
  }/*环长为2*/
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = 1; k <= 4; k++) {
        if (i != j and j != k and i != k) {
          int x = min({tr[i][j], tr[j][k], tr[k][i]});
          ans += 2 * x;
          tr[i][j] -= x; tr[j][k] -= x; tr[k][i] -= x;
        }
      }
    }
  }
  vector<int>p(3);
  for (int i = 0; i <= 2; i++)p[i] = i + 2;
  do {
    int x = min({tr[1][p[0]], tr[p[0]][p[1]], tr[p[1]][p[2]], tr[p[2]][1]});
    ans += 3 * x;
  } while (next_permutation(p.begin(), p.end()));
  cout << ans << endl;
}
signed main() {

  solve();
}