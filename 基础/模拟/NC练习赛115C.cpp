#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed  long  long;
using u64 = unsigned  long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct cmp {
  bool operator()(const  i64&x, const  i64&y)const {
    return abs(x) > abs(y);
  }
};
void solve() {
  std::multiset< i64, cmp>st;
  i64 n; std::cin >> n;  i64 q; std::cin >> q; vector< i64>A(n + 5), d(n + 5);
  for ( i64 i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for ( i64 i = 2; i <= n; i++) {
    d[i] = A[i] - A[i - 1]; st.insert(d[i]);
    //cout << d[i] << endl;
  }
  //cout << st.count(0) << endl;
  printf("% lld.00000000\n", abs(*st.begin()));
  while (q--) {
    i64 l, r, x; std::cin >> l >> r >> x;
    if (l >= 2) {
      st.erase(st.find(d[l])); d[l] += x; st.insert(d[l]);
    }
    if (r <= n - 1) {
      //cout << d[r + 1] << endl;
      //cout << st.count(d[r + 1]) << endl;
      st.erase(st.find(d[r + 1]));
      d[r + 1] -= x;
      st.insert(d[r + 1]);
    }
    printf("%lld.00000000\n", abs(*st.begin()));
  }
}
signed main() {
  solve();
}