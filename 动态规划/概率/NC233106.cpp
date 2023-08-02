/*dp求期望*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e2 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
double dp[1010][1010];

signed main() {
  scanf("%d %d", &n, &s);
  dp[n][s] = 0;
  for (int i = n; i >= 0; i--) {
    for (int j = s; j >= 0; j--) {
      if (i == n && s == j) continue;
      dp[i][j] = (dp[i][j + 1] * i * (s - j) + dp[i + 1][j] * (n - i) * j +
                  dp[i + 1][j + 1] * (n - i) * (s - j) + n * s) /
                 (n * s - i * j);  // 期望递推
    }
  }
  printf("%.4lf\n", dp[0][0]);
  return 0;
}