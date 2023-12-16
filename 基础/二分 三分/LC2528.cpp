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

class Solution {
public:
  long long maxPower(vector<int>& stations, int r, int k) {
    int n = stations.size();
    vector< i64>d(n + 5, 0);
    for (int i = 1; i <= n; i++) {
      int s = max(1, i - r);
      int t = i + r;
      d[s] += stations[i - 1];
      d[min(t + 1, n + 1)] -= stations[i - 1];
    }
    vector< i64>ff(n + 5);
    for (int i = 1; i <= n; i++)ff[i] = ff[i - 1] + d[i];
    auto check = [&](long long mid) {
      vector< i64>dd(n + 5); int cnt = 0;
      for (int i = 1; i <= n ; i ++)dd[i] = d[i];
      for (int i = 1; i <= n; i++) {
        dd[i] += dd[i - 1];
        if (dd[i] < mid) {
          cnt += mid - dd[i];
          int f = mid - dd[i];
          dd[i] += f; dd[min(n + 1, i + 2 * r + 1)] -= f;
        }
      }
      if (cnt > k)return false;
      return true;
    };
    long ans = 0;
    long long L = *min_element(ff.begin() + 1, ff.begin() + 1 + n), R = L + k + 1;
    while (L <= R) {
      long long mid = (L + R) >> 1;
      if (check(mid))L = mid + 1, ans = mid;
      else R = mid - 1;
    }
    return ans;
  }
};