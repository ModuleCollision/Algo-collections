#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  int n, k; std::cin >> n >> k;
  vector<int>ve(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> ve[i];
  }
  if (ve[1] != 1) {
    puts("1"); return;
  }
  ve[n + 1] = 1e18;
  int cnt = 1; vector<int>ans;
  int d = 1;
  for (int i = 2; i <= n + 1; i++) {
    while (cnt + d < ve[i]) {
      cnt += d;
      ans.push_back(cnt);
      if (ans.size() > k + 1) {
        break;
      }
    }
    if (ans.size() > k + 1) {
      break;
    }
    d = i;
  }
  cout << ans[k - 1] << endl;
}
signed main() {
  solve();
}