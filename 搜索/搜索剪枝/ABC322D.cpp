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
int main() {
  solve();
}