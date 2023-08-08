class Solution {
public:

    typedef long long ll;

    int maxIncreasingGroups(vector<int>& usageLimits) {
        auto check = [&](ll m) {
            auto u = usageLimits;
            ll n = u.size();
            if (u.size() < m)return false;
            ll l = 0;
            vector<ll>v(n, 0);
            for (ll i = 0; i < u.size(); i++) {
                ll tar = max(0ll, m - i);
                v[i] = min(tar, (ll)u[i]);
                u[i] -= v[i];
                while (u[i] and l < i) {
                    ll tal = max(0ll, m - l);
                    ll ned = tal - v[l];
                    ll give = min({ned, i - l, (ll)u[i]});
                    u[i] -= give;
                    v[i] += give;
                    if (v[l] == max(0ll, m - l))l++;
                }
            }
            while (l < n and max(0ll, m - l) == v[l])l++;
            return l == n;
        };
        ll n = usageLimits.size();
        std::sort(usageLimits.begin(), usageLimits.end(), greater<ll>());
        ll l = 0, r = 1e7 + 7; ll ans = 0;
        while (l < r) {
            ll mid = (l + r + 1) >> 1;
            if (check(mid))l = mid;
            else r = mid - 1;
        }
        return l;
    }
};