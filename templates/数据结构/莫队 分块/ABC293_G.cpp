#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct query {
  ll l; ll r; ll idx;
};
ll cnt[maxn];
void solve() {
  ll n, q; cin >> n >> q;
  vector<ll>A(n + 1, 0);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  vector<query>qs(q + 1);
  for (ll i = 1; i <= q; i++) {
    cin >> qs[i].l >> qs[i].r;
    qs[i].idx = i;
  }
  ll k = sqrt(n); vector<ll>ans(q + 1);
  sort(qs.begin() + 1, qs.begin() + 1 + q, [&](auto a, auto b)->bool{
    ll x = (a.l - 1) / k + 1; ll y = (b.l - 1) / k + 1;
    if (x == y)return a.r < b.r;
    return a.l < b.l;
  });
  ll cur = 0;
  auto add = [&](ll i) {
    cur += (cnt[A[i]] * (cnt[A[i]] - 1)) / 2;
    cnt[A[i]]++;
  };
  auto del = [&](ll i) {
    cur -= ((cnt[A[i]] - 1) * (cnt[A[i]] - 2)) / 2;
    cnt[A[i]]--;
  };
  for (ll i = 1, L = 1, R = 0; i <= q; i++) {
    while (R < qs[i].r) {
      add(++R);
    }
    while (L > qs[i].l) {
      add(--L);
    }
    while (R > qs[i].r) {
      del(R--);
    }
    while (L < qs[i].l) {
      del(L++);
    }
    ans[qs[i].idx] = cur;
  }
  for (ll i = 1; i <= q; i++)cout << ans[i] << endl;

}
signed main() {

  solve();
}