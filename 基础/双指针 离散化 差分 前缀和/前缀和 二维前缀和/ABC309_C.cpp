#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll N, K;
  std::cin >> N >> K;
  vector<pair<ll, ll>>w(N + 5);
  std::set<ll>st;
  for (ll i = 1; i <= N; i++) {
    std::cin >> w[i].first >> w[i].second;
    st.insert(w[i].first);
  }
  std::sort(w.begin() + 1, w.begin() + 1 + N, [&](pair<ll, ll> x, pair<ll, ll> y)->bool{
    return x.first < y.first;
  });
  vector<ll>d(N + 5); ll f = 0;
  for (auto c : st) {
    d[++f] = c;
  }
  //cout << "#" << f << endl;
  /*for (ll i = 1; i <= f; i++) {
    d[i] -= d[i - 1];
  }*/
  vector<ll>v(f + 5); f = 0;
  for (ll i = 1; i <= N; i++) {
    f++;
    v[f] += w[i].second;
    while (i + 1 <= N and w[i + 1].first == w[i].first) {
      i++; v[f] += w[i].second;
    }
  }
  ll idx = 0;
  for (ll i = f; i >= 1; i--) {
    v[i] += v[i + 1];
  }
  for (ll i = 1; i <= f; i++) {
    if (v[i] <= K) {
      idx = i; break;
    }
  }
  cout << d[idx - 1] + 1 << endl;
}
signed main() {
  solve();
}