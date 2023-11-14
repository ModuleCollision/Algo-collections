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
  ll n; cin >> n;
  string r, c; cin >> r >> c;
  vector ans(n, string(n, '.'));
  auto check = [&](vector<string>s) {
    string t = ""; bool f1 = false;
    for (ll i = 0; i < n; i++) {
      ll q = 0;
      while (q < n and not isalpha(s[q][i]))q++;
      if (q == n)break;
      t += s[q][i];
    }
    f1 = (t == c);
    bool f2 = true;
    vector cnt(n + 1, vector<ll>(3, 0));
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
        if (isalpha(s[j][i]))cnt[i][s[j][i] - 'A']++;
      }
      for (ll j = 0; j < 3; j++) {
        if (cnt[i][j] != 1)f2 = false;
      }
      if (not f2)break;
    }
    return (f1 and f2);
  };
  vector<string>res;
  function<bool(ll)>dfs = [&](ll idx) {
    if (idx == n) {
      if (check(ans)) {
        res = ans; return true;
      }
      return false;
    }
    for (ll i = 0; i < n - 2; i++) {
      for (ll j = i + 1; j < n - 1; j++) {
        for (ll k = j + 1; k < n; k++) {
          ans[idx][i] = r[idx];
          if (r[idx] == 'A')ans[idx][j] = 'B', ans[idx][k] = 'C';
          else if (r[idx] == 'B')ans[idx][j] = 'A', ans[idx][k] = 'C';
          else ans[idx][j] = 'A', ans[idx][k] = 'B';
          bool f = dfs(idx + 1);
          if (f)return true;
          swap(ans[idx][j], ans[idx][k]);
          f = dfs(idx + 1);
          if (f)return true;
          ans[idx][i] = '.'; ans[idx][j] = '.'; ans[idx][k] = '.';
        }
      }
    }
    return false;
  };
  bool f = dfs(0);
  if (not f) {
    puts("No"); return;
  }
  puts("Yes");
  for (ll i = 0; i < n; i++) {
    cout << res[i] << endl;
  }
  return;
}
signed main() {
  solve();
}