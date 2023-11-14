typedef long long ll;
const ll mod = 1e9 + 7;
class Solution {
public:
  int countKSubsequencesWithMaxBeauty(string s, int k) {
    vector C(30, vector<ll>(30, 0));
    for (int i = 0; i <= 26; i++) {
      for (int j = 0; j <= i; j++) {
        if (not j)C[i][j] = 1;
        else C[i][j] = (C[i - 1][j] % mod + C[i - 1][j - 1]) % mod;
      }
    }
    map<int, int>cnt;
    vector<int>f(30, 0);
    iota(f.begin(), f.begin() + 26, 0);
    for (auto c : s) {
      cnt[c - 'a']++;
    }
    if (cnt.size() < k)return 0ll;
    std::sort(f.begin(), f.begin() + 26, [&](int a, int b)->bool{
      return cnt[a] > cnt[b];
    });
    int l = k - 1, r = k - 1;
    while (r + 1 < 26 and cnt[f[r + 1]] == cnt[f[r]])r++;
    while (l - 1 >= 0 and cnt[f[l - 1]] == cnt[f[l]])l--;
    int d1 = l, d2 = k - l;
    ll ret = 1;
    for (int i = 0; i < l; i++) {
      ret = (ret % mod * cnt[f[i]]) % mod;
    }
    vector dp(30, vector<ll>(k - l + 5, 0)); dp[0][0] = 1;
    vector<ll>c(r - l + 5);
    for (int i = l; i <= r; i++) {
      c[i - l + 1] = cnt[f[i]];
    }
    for (ll i = 1; i <= r - l + 1; i++) {
      for (ll j = 0; j <= k - l; j++) {
        dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
        if (j >= 1) {
          dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - 1] % mod * c[i]) % mod;
        }
      }
    }
    ret = (ret % mod * dp[r - l + 1][k - l]) % mod;
    return ret % mod;
  }
};