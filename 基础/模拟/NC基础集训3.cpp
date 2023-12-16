// 单组测试数据开vector 多组测试数据开全局数组
#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed  i64;
using u64 = unsigned  i64;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

char s[maxn]; int tot = 0;
i64 nums[maxn];
int opt[maxn];
i64 ksm( i64 x,  i64 y,  i64 z) {
  i64 ret = 1; x %= z;
  while (y) {
    if (y & 1)ret = ret % z * x % z;
    x = x  % z * x % z;
    y >>= 1;
  }
  return ret % z;
}
bool f = false;
void dfs(int now) {
  if (f)return;
  if (now > tot - 2) {
    i64 cur = nums[1];
    for (int i = 1; i <= tot - 2; i++) {
      if (opt[i] == 1) {
        cur += nums[i + 1];
      } else if (opt[i] == 2) {
        cur -= nums[i + 1];
      } else {
        if (nums[i + 1] <= 0 or cur <= 0)return;
        cur = ksm(cur, cur, nums[i + 1]);
      }
    }
    if (cur == nums[tot]) {
      f = true;
      for (int i = 1; i < tot; i++) {
        cout << nums[i];
        if (opt[i] == 1)putchar('+');
        else if (opt[i] == 2)putchar('-');
        else if (opt[i] == 3)putchar('#');
        else putchar('=');
      }
      cout << nums[tot] << "\n";
      //exit(0);
    }
    return;
  }
  if (opt[now] == -1) {
    for (int i = 1; i <= 3; i++)opt[now] = i, dfs(now + 1);
  } else {
    dfs(now + 1);
  }
}
void solve() {
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int i = 1; i <= len; i++) {
    int cur = 0;
    while (i <= len and isdigit(s[i])) {
      cur = (cur * 10 + s[i] - '0'); i++;
    }
    nums[++tot] = cur;
    if (i > len)break;
    if (s[i] == '+') {
      opt[tot] = 1;
    } else if (s[i] == '-') {
      opt[tot] = 2;
    } else if (s[i] == '#') {
      opt[tot] = 3;
    } else if (s[i] == '?')opt[tot] = -1;
  }
  dfs(1);
  if (not f) {
    puts("-1");
  }
}

int main() {
  solve();
  return 0;
}
