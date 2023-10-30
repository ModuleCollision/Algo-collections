#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 505;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n;
std::set<ll>st2[maxn];
struct cmp2 {
  bool operator()(const ll&x, const ll&y)const {
    return st2[x].size() < st2[y].size();//因子数越小
  }
};
std::set<ll>st1[maxn];
struct cmp1 {
  bool operator()(const ll&x, const ll&y)const {
    return st1[x].size() > st1[y].size();
  }
};
priority_queue<ll, vector<ll>, cmp1>pq;

void solve() {
  cin >> n; vector<ll>a(n + 1), b(n + 1);
  for (ll i = 1; i <= n; i++)cin >> a[i];
  for (ll i = 1; i <= n; i++)cin >> b[i];
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      ll cur = __gcd(a[i], b[j]);
      if (cur == 1) {
        st1[i].insert(j);
        st2[j].insert(i);
      }
    }
  }
  for (ll i = 1; i <= n; i++)pq.push(i);
  for (ll i = 1; i <= n; i++) {
    auto f = pq.top(); pq.pop();
    if (not st1[f].size()) {
      puts("Alice"); return;
    }
    ll t = -1; ll cur = inf;
    for (auto c : st1[f]) {
      if (st2[c].size() <= cur)cur = st2[c].size(), t = c;
    }
    for (auto c : st2[t]) {
      st1[c].erase(t);
    }
    for (auto c : st1[f]) {
      st2[c].erase(f);
    }
  }
  puts("Bob");
}
signed main() {
  solve();
}