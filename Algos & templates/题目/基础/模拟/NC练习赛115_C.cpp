#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct cmp {
  bool operator()(const ll&x, const ll&y)const {
    return abs(x) > abs(y);
  }
};
void solve() {
  std::multiset<ll, cmp>st;
  ll n; std::cin >> n; ll q; std::cin >> q; vector<ll>A(n + 5), d(n + 5);
  for (ll i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (ll i = 2; i <= n; i++) {
    d[i] = A[i] - A[i - 1]; st.insert(d[i]);
    //cout << d[i] << endl;
  }
  //cout << st.count(0) << endl;
  printf("%lld.00000000\n", abs(*st.begin()));
  while (q--) {
    ll l, r, x; std::cin >> l >> r >> x;
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