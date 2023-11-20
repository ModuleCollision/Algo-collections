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
const i64 mod = 9901;
const i64 maxn = 2e5 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 nums1[5005], nums2[5005];
void solve() {
  i64 n; cin >> n;
  for (i64 i = 1; i <= n; i++) {
    i64 x; cin >> x;
    for (i64 j = 2; j <= sqrt(x); j++) {
      if (x % j == 0) {
        while (x % j == 0)x /= j; nums1[j]++;
      }
    }
    if (x > 1)nums1[x]++;
  }
  for (i64 i = 1; i <= n; i++) {
    i64 x; cin >> x;
    for (i64 j = 2; j <= sqrt(x); j++) {
      if (x % j == 0) {
        while (x % j == 0)x /= j; nums2[j]++;
      }
    }
    if (x > 1)nums2[x]++;
  }
  for (i64 j = 2; j <= 500; j++) {
    if (nums1[j] and nums2[j] and nums1[j] + nums2[j] > n) {
      puts("Alice"); return;
    }
  }
  puts("Bob");
}
signed main() {
  solve();
}