// 单组测试数据开vector 多组测试数据开全局数组
#include<bits/stdc++.h>

using namespace std;

const long long maxn = 1e5 + 5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
char s[maxn]; int tot = 0;
long long nums[maxn];
int opt[maxn];
long long ksm(long long x, long long y, long long z) {
  long long ret = 1; x %= z;
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
    long long cur = nums[1];
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
