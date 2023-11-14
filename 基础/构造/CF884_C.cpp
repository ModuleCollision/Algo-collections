#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1000005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
  ll pre; ll nxt; ll v;
} tr[maxn];
struct cmp {
  bool operator()(const pair<ll, ll>x, const pair<ll, ll>y)const {
    return x.first < y.first;
  }
};
void solve() {
  ll n; std::cin >> n;
  vector<ll>A(n + 5, 0);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  ll pos = 0;
  for (ll i = 1; i <= n; i++) {
    if (A[i] > 0) {
      pos = i; break;
    }
  }
  if (not pos) {
    std::sort(A.begin() + 1, A.begin() + 1 + n);
    cout << A[n] << endl;
  } else {
    ll s1 = 0, s2 = 0;
    for (ll i = 1; i <= n; i++) {
      if (A[i] > 0) {
        if (i & 1) {
          s1 += A[i];
        } else {
          s2 += A[i];
        }
      }
    }
    cout << max(s1, s2) << endl;
  }
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}