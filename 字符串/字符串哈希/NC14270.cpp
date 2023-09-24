#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 4e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	string s; std::cin >> s;
	ll len = s.size();
	s = " " + s;
	auto check = [&](ll x) ->bool {
		if (x >= 20) return true ;
		ll tot = 1 << x ;
		if (tot > len - x + 1) return true ;
		std::set<string>st;
		for (ll i = 1; i + x - 1 <= len; i++) {
			st.insert(s.substr(i, x));
		}//比总数少,说明没出现过
		return st.size() < tot;//说明未曾出现过
	};
	ll l = 1, r = len;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
}
signed main() {
	solve();
}
/*字符串哈希解法*/

#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	string s; std::cin >> s;
	ll len = s.size();
	s = " " + s;
	ll p = 23; ll n = s.size();
	vector<ll>Hash(n + 5, 0);
	auto ksm = [&](ll a, ll b) {
		ll ret = 1;
		while (b) {
			if (b & 1)ret = ret * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return ret;
	};
	for (ll i = 1; i <= n; i++) {
		Hash[i] = (Hash[i - 1] % mod * p % mod + s[i] - '0') % mod;
	}
	auto get = [&](ll l, ll r) {
		return ((Hash[r] - Hash[l - 1] % mod * ksm(p, r - l + 1)) % mod + mod) % mod;
	};
	/*代表取一个字串的哈希值*/
	/*不同字串取到相同哈希值(碰撞)的概率很小*/
	auto check = [&](ll x) ->bool {
		if (x >= 20) return true ;
		ll tot = 1 << x ;
		if (tot > len - x + 1) return true ;
		std::set<ll>st;
		for (ll i = 1; i + x - 1 <= len; i++) {
			st.insert(get(i, i + x - 1));
		}
		return st.size() < tot;//说明未曾出现过
	};
	ll l = 1, r = len;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	cout << r << endl;
}
signed main() {
	solve();
}