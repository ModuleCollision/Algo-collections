#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e2 + 5;
const ll inf = 1e16;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn]; char s[maxn];
ll add[30], del[30], trans[30][30], c[30];
void solve() {
    for (ll i = 0; i < 26; i++) {
        add[i] = del[i] = inf;
        for (ll j = 0; j < 26; j++) {
            if (i == j) {
                continue;
            }
            trans[i][j] = inf;
        }
    }//Floyd的初始化
    std::cin >> (s + 1); ll T; std::cin >> T;
    while (T--) {
        string opt;
        std::cin >> opt;
        if (opt == "add") {
            string c; ll x; std::cin >> c >> x;
            add[c[0] - 'a'] = min(add[c[0] - 'a'], x);
        } else if (opt == "erase") {
            string c; ll x;
            std::cin >> c >> x;
            del[c[0] - 'a'] = min(del[c[0] - 'a'], x);
        } else {
            string c1, c2; ll x;
            std::cin >> c1 >> c2 >> x;
            trans[c1[0] - 'a'][c2[0] - 'a'] = min(trans[c1[0] - 'a'][c2[0] - 'a'], x);
        }
    }
    for (ll k = 0; k < 26; k++) {
        for (ll i = 0; i < 26; i++) {
            for (ll j = 0; j < 26; j++) {
                trans[i][j] = min(trans[i][j], trans[i][k] + trans[k][j]);
            }
        }
    }
    for (ll i = 0; i < 26; i++) {
        c[i] = min(add[i], del[i]);
        for (ll j = 0; j < 26; j++) {
            c[i] = min(c[i], trans[i][j] + min(add[j], del[j]));
            c[i] = min(c[i], trans[j][i] + add[j]);
            for (ll k = 0; k < 26; k++) {
                c[i] = min(c[i], trans[i][k] + add[j] + trans[j][k]);
            }
        }//使得子段[i, j]转移到[i + 1, j]的最小代价
    }
    ll len = strlen(s + 1);
    for (ll i = 0; i <= len; i++) {
        dp[i][i] = 0; dp[i + 1][i] = 0;
    }//区间dp的初始化
    for (ll l = 2; l <= len; l++) {
        for (ll i = 1; i + l - 1 <= len; i++) {
            ll j = i + l - 1; dp[i][j] = inf;
            if (s[i] == s[j])dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + c[s[i] - 'a']);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + c[s[j] - 'a']);
            dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + min(trans[s[i] - 'a'][s[j] - 'a'], trans[s[j] - 'a'][s[i] - 'a']));
            for (ll k = 0; k < 26; k++) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + trans[s[i] - 'a'][k] + trans[s[j] - 'a'][k]);
            }
        }
    }
    if (dp[1][len] == inf) {
        puts("-1");
    } else {
        cout << dp[1][len] << endl;
    }
}
signed main() {
    solve();
}