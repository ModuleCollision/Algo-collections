#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void rotate(vector<string>&str) {
  auto ret = str;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ret[i][j] = str[3 - j][i];
    }
  }
  str = ret;
}
bool in(int x, int y) {
  return x >= 0 and x<4 and y >= 0 and y < 4;
}
bool check(vector<vector<int>>&tmp, vector<string>&s, int dx, int dy) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (s[i][j] == '#') {
        int nx = i + dx, ny = j + dy;
        if (not in(nx, ny))return false;
        if (tmp[nx][ny])return false;
        tmp[nx][ny] = 1;
      }
    }
  }
  return true;
}

void solve() {
  vector p(3, vector<string>(4));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++)cin >> p[i][j];
  }
  function<bool(int , vector<vector<int>>, vector<vector<string>>&)> dfs = [&](int i, vector<vector<int>>tmp, vector<vector<string>>&p) {
    if (i == 3) {
      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          if (tmp[j][k] == 0)return false;
        }
      }
      puts("Yes"); return true;
    } else {
      for (int dx = -3; dx <= 3; dx++) {
        for (int dy = -3; dy <= 3; dy++) {
          auto tmp2 = tmp;
          if (check(tmp2, p[i], dx, dy)) {
            bool f = dfs(i + 1, tmp2, p);
            if (f)return true;
          }
        }
      }
    }
    return false;
  };
  bool ans = false;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ans = dfs(0, vector(4, vector<int>(4, 0)), p);
      if (ans) {
        return;
      }
      rotate(p[2]);
    }
    rotate(p[1]);
  }
  puts("No");
}
signed main() {
  solve();
}