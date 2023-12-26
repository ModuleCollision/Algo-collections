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
signed main() {
  string tar = "123804765"; std::map<string, int>dis;
  string f; cin >> f; dis[f] = 0;
  queue<string>q; q.push(f);
  vector<pair<i64, i64>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
  auto check = [&](i64 x, i64 y) {
    return x >= 0 and x<3 and y >= 0 and y < 3;
  };
  while (q.size()) {
    auto cur = q.front(); q.pop();
    if (cur == tar) {
      cout << dis[cur] << "\n"; return 0;
    }
    i64 x, y;
    for (i64 i = 0; i < 9; i++) {
      if (cur[i] == '0') {
        x = i / 3, y = i % 3; break;
      }
    }
    for (auto [dx, dy] : dir) {
      i64 xx = x + dx, yy = y + dy;
      if (check(xx, yy)) {
        string tmp = cur;
        swap(tmp[xx * 3 + yy], tmp[x * 3 + y]);
        if (not dis.count(tmp)) {
          dis[tmp] = dis[cur] + 1;
          q.push(tmp);
        }
      }
    }
  }
}