#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 10005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll v[maxn], w[maxn]; ll dp[maxn];
/*完全背包的一维写法*/
void solve() {
  ll N, V; std::cin >> N >> V;
  for (ll i = 1; i <= N; i++)cin >> v[i] >> w[i];
  //只能这种枚举次序，相反则变成排列数了
  for (ll i = 1; i <= N; i++) {
    for (ll j = v[i]; j <= V; j++) {
      dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }
  }
  cout << dp[V] << endl;
}
signed main() {
  solve();
}
/*完全背包二维*/
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll v[maxn], w[maxn]; ll dp[1001][maxn];
void solve() {
  ll N, V; std::cin >> N >> V;
  for (ll i = 1; i <= N; i++)cin >> v[i] >> w[i];
  for (ll i = 1; i <= N; i++) {
    for (ll j = 0; j <= V; j++) {
      for (ll k = 0; k * v[i] <= j; k++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
      }
    }
  }
  cout << dp[N][V] << endl;
}
signed main() {
  solve();
}