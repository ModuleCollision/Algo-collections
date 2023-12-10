typedef long long ll;
const ll mod = 1e9 + 7;
class Solution {
public:
  ll ksm(ll x, ll y) {
    ll ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ret % mod;
  }
  ll inv(ll x) {
    return ksm(x, mod - 2) % mod;
  }
  ll fac[100005];
  void init() {
    fac[0] = 1;
    for (int i = 1; i <= 1e5; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
  }
  ll comb(ll n, ll m) {
    return fac[n] % mod * inv(fac[n - m] % mod * fac[m] % mod) % mod;
  }
  ll arrn(ll n, ll m) {
    return comb(n, m) % mod * fac[m] % mod;
  }
  int waysToBuildRooms(vector<int>& prevRoom) {
    int n = prevRoom.size();
    vector<vector<int>>tr(n + 1);
    for (int i = 0; i < n; i++) {
      if (i == 0)continue;
      tr[i + 1].push_back(prevRoom[i] + 1);
      tr[prevRoom[i] + 1].push_back(i + 1);
    }
    init();
    vector<ll>sz(n + 1); vector<ll>dp(n + 1, 0);
    function<void(int, int)>dfs = [&](int u, int f) {
      sz[u] = 1;  ll tot = 0;
      ll sx = 1; ll sy = 1;
      for (auto v : tr[u]) {
        if (v == f)continue;
        dfs(v, u);
        sz[u] = (sz[u] % mod + sz[v]) % mod;
        tot = (tot % mod + sz[v]) % mod;
        sx = (sx % mod * fac[sz[v]]) % mod; sy = (sy % mod * dp[v]) % mod;
      }
      dp[u] = (fac[tot] % mod * inv(sx) % mod) % mod * sy % mod;
    };
    dfs(1, 0); return dp[1] % mod;
  }
};