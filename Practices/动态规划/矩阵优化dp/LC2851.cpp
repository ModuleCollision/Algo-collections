typedef long long ll;
const ll mod = 1e9 + 7;
class Solution {
public:
  int numberOfWays(string s, string t, long long k) {
    string p = s + s; string f = t + '#' + p;
    vector<ll>w(f.size() + 1);
    ll len = f.size();
    for (ll i = 1; i < len; i++) {
      ll j = w[i - 1];
      while (j > 0 and f[i] != f[j])j = w[j - 1];
      if (f[i] == f[j])j++;
      w[i] = j;
    }
    ll c = 0;
    for (ll i = t.size() + 1; i < f.size() - 1; i++) {
      if (w[i] == t.size())c++;
    }
    cout << c << endl;
    auto mul = [&](vector<vector<ll>>x, vector<vector<ll>>y) {
      vector ret(2, vector<ll>(2, 0));
      for (ll i = 0; i < 2; i++) {
        for (ll j = 0; j < 2; j++) {
          ll v = 0;
          for (ll k = 0; k < 2; k++) {
            v = (v % mod + x[i][k] % mod * y[k][j] % mod) % mod;
          }
          ret[i][j] = (ret[i][j] % mod + v) % mod;
        }
      }
      return ret;
    };
    auto ksm = [&](vector<vector<ll>>w, ll b) {
      vector ret(2, vector<ll>(2, 0)); ret[0][0] = 1; ret[1][1] = 1;
      while (b) {
        if (b & 1)ret = mul(w, ret);//次序不能错
        w = mul(w, w);
        b >>= 1;
      }
      return ret;
    };
    vector q(2, vector<ll>(2, 0)); ll n = s.size();
    q[0][0] = c - 1, q[0][1] = c, q[1][0] = n - c, q[1][1] = n - c - 1;
    auto res = ksm(q, k);
    ll ans = 0;
    if (s == t)ans = res[0][0];
    else ans = res[0][1];
    return ans % mod;
  }
};