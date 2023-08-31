#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll norm(ll x) {
	return (x % mod + mod) % mod;
}
template<typename T>
T power(T a, ll b) {
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b % 2) { res *= a; }
	}
	return res;
}
struct Z {
	ll x;
	Z(ll v = 0): x(norm(v % mod)) {}
	ll val() const {
		return x;
	}
	Z operator-() const {
		return Z(norm(mod - x));
	}
	Z inv() const {
		assert(x != 0);
		return power(*this, mod - 2);
	}
	Z& operator*=(const Z& rhs) {
		x = (ll)x * rhs.x % mod;
		return *this;
	}
	Z& operator+=(const Z& rhs) {
		x = norm(x + rhs.x);
		return *this;
	}
	Z& operator-=(const Z& rhs) {
		x = norm(x - rhs.x);
		return *this;
	}
	Z& operator/=(const Z& rhs) {
		return *this *= rhs.inv();
	}
	friend Z operator*(const Z& lhs, const Z& rhs) {
		Z res = lhs; res *= rhs;
		return res;
	}
	friend Z operator+(const Z& lhs, const Z& rhs) {
		Z res = lhs; res += rhs;
		return res;
	}
	friend Z operator-(const Z& lhs, const Z& rhs) {
		Z res = lhs; res -= rhs;
		return res;
	}
	friend Z operator/(const Z& lhs, const Z& rhs) {
		Z res = lhs; res /= rhs;
		return res;
	}
	friend std::istream& operator>>(std::istream& is, Z& a) {
		ll v; is >> v;
		a = Z(v);
		return is;
	}
	friend std::ostream& operator<<(std::ostream& os, const Z& a) {
		return os << a.val();
	}
};

std::vector<ll> rev;
std::vector<Z> roots{ 0, 1 };
void dft(std::vector<Z>& a) {
	ll n = a.size();

	if (ll(rev.size()) != n) {
		ll k = __builtin_ctz(n) - 1;
		rev.resize(n);
		for (ll i = 0; i < n; i++) {
			rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
		}
	}

	for (ll i = 0; i < n; i++) {
		if (rev[i] < i) {
			std::swap(a[i], a[rev[i]]);
		}
	}
	if (ll(roots.size()) < n) {
		ll k = __builtin_ctz(roots.size());
		roots.resize(n);
		while ((1 << k) < n) {
			Z e = power(Z(3), (mod - 1) >> (k + 1));
			for (ll i = 1 << (k - 1); i < (1 << k); i++) {
				roots[2 * i] = roots[i];
				roots[2 * i + 1] = roots[i] * e;
			}
			k++;
		}
	}
	for (ll k = 1; k < n; k *= 2) {
		for (ll i = 0; i < n; i += 2 * k) {
			for (ll j = 0; j < k; j++) {
				Z u = a[i + j];
				Z v = a[i + j + k] * roots[k + j];
				a[i + j] = u + v;
				a[i + j + k] = u - v;
			}
		}
	}
}
void idft(std::vector<Z>& a) {
	ll n = a.size();
	std::reverse(a.begin() + 1, a.end());
	dft(a);
	Z inv = (1 - mod) / n;
	for (ll i = 0; i < n; i++) {
		a[i] *= inv;
	}
}
struct Poly {
	std::vector<Z> a;
	Poly() {}
	Poly(const std::vector<Z>& a) : a(a) {}
	Poly(const std::initializer_list<Z>& a) : a(a) {}
	ll size() const {
		return a.size();
	}
	void resize(ll n) {
		a.resize(n);
	}
	Z operator[](ll idx) const {
		if (idx < 0 || idx >= size()) {
			return 0;
		}
		return a[idx];
	}
	Z& operator[](ll idx) {
		return a[idx];
	}
	Poly mulxk(ll k) const {
		auto b = a;
		b.insert(b.begin(), k, 0);
		return Poly(b);
	}
	Poly modxk(ll k) const {
		k = std::min(k, size());
		return Poly(std::vector<Z>(a.begin(), a.begin() + k));
	}
	Poly divxk(ll k) const {
		if (size() <= k) {
			return Poly();
		}
		return Poly(std::vector<Z>(a.begin() + k, a.end()));
	}
	friend Poly operator+(const Poly& a, const Poly& b) {
		std::vector<Z> res(std::max(a.size(), b.size()));
		for (ll i = 0; i < ll(res.size()); i++) {
			res[i] = a[i] + b[i];
		}
		return Poly(res);
	}
	friend Poly operator-(const Poly& a, const Poly& b) {
		std::vector<Z> res(std::max(a.size(), b.size()));
		for (ll i = 0; i < ll(res.size()); i++) {
			res[i] = a[i] - b[i];
		}
		return Poly(res);
	}
	friend Poly operator*(Poly a, Poly b) {
		if (a.size() == 0 || b.size() == 0) {
			return Poly();
		}
		ll sz = 1, tot = a.size() + b.size() - 1;
		while (sz < tot)
			sz *= 2;
		a.a.resize(sz);
		b.a.resize(sz);
		dft(a.a);
		dft(b.a);
		for (ll i = 0; i < sz; ++i) {
			a.a[i] = a[i] * b[i];
		}
		idft(a.a);
		a.resize(tot);
		return a;
	}
	friend Poly operator*(Z a, Poly b) {
		for (ll i = 0; i < ll(b.size()); i++) {
			b[i] *= a;
		}
		return b;
	}
	friend Poly operator*(Poly a, Z b) {
		for (ll i = 0; i < ll(a.size()); i++) {
			a[i] *= b;
		}
		return a;
	}
	Poly& operator+=(Poly b) {
		return (*this) = (*this) + b;
	}
	Poly& operator-=(Poly b) {
		return (*this) = (*this) - b;
	}
	Poly& operator*=(Poly b) {
		return (*this) = (*this) * b;
	}
	Poly deriv() const {
		if (a.empty()) {
			return Poly();
		}
		std::vector<Z> res(size() - 1);
		for (ll i = 0; i < size() - 1; ++i) {
			res[i] = (i + 1) * a[i + 1];
		}
		return Poly(res);
	}
	Poly integr() const {
		std::vector<Z> res(size() + 1);
		for (ll i = 0; i < size(); ++i) {
			res[i + 1] = a[i] / (i + 1);
		}
		return Poly(res);
	}
	Poly inv(ll m) const {
		Poly x{ a[0].inv() };
		ll k = 1;
		while (k < m) {
			k *= 2;
			x = (x * (Poly{ 2 } - modxk(k) * x)).modxk(k);
		}
		return x.modxk(m);
	}
	Poly log(ll m) const {
		return (deriv() * inv(m)).integr().modxk(m);
	}
	Poly exp(ll m) const {
		Poly x{ 1 };
		ll k = 1;
		while (k < m) {
			k *= 2;
			x = (x * (Poly{ 1 } - x.log(k) + modxk(k))).modxk(k);
		}
		return x.modxk(m);
	}
	Poly pow(ll k, ll m) const {  //快速幂,k是幂数,m是保留的最大位-1
		ll i = 0;
		while (i < size() && a[i].val() == 0) {
			i++;
		}
		if (i == size() || 1LL * i * k >= m) {
			return Poly(std::vector<Z>(m));
		}
		Z v = a[i];
		auto f = divxk(i) * v.inv();
		return (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * power(v, k);
	}
	Poly sqrt(ll m) const {
		Poly x{ 1 };
		ll k = 1;
		while (k < m) {
			k *= 2;
			x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((mod + 1) / 2);
		}
		return x.modxk(m);
	}
	Poly mulT(Poly b) const {
		if (b.size() == 0) {
			return Poly();
		}
		ll n = b.size();
		std::reverse(b.a.begin(), b.a.end());
		return ((*this) * b).divxk(n - 1);
	}
	std::vector<Z> eval(std::vector<Z> x) const {
		if (size() == 0) {
			return std::vector<Z>(x.size(), 0);
		}
		const ll n = std::max(ll(x.size()), size());
		std::vector<Poly> q(4 * n);
		std::vector<Z> ans(x.size());
		x.resize(n);
		std::function<void(ll, ll, ll)> build = [&](ll p, ll l, ll r) {
			if (r - l == 1) {
				q[p] = Poly{ 1, -x[l] };
			}
			else {
				ll m = (l + r) / 2;
				build(2 * p, l, m);
				build(2 * p + 1, m, r);
				q[p] = q[2 * p] * q[2 * p + 1];
			}
		};
		build(1, 0, n);
		std::function<void(ll, ll, ll, const Poly&)> work = [&](ll p, ll l, ll r, const Poly & num) {
			if (r - l == 1) {
				if (l < ll(ans.size())) {
					ans[l] = num[0];
				}
			}
			else {
				ll m = (l + r) / 2;
				work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
				work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
			}
		};
		work(1, 0, n, mulT(q[1].inv(n)));
		return ans;
	}
};
void solve() {
	/*ll n, m, k; cin >> n >> m >> k;
	vector<Z>f(k + 1);
	f[0] = 1;
	for (ll i = 1; i <= min(n, k); i ++)f[i] = f[i - 1] / i * (n - i + 1);
	for (ll i = 1; i <= min(n, k); i += 2)f[i] = 0;
	auto g = Poly(f).pow(m, k + 1);//这里 m (多项式求幂)可以到1e8, 长度可以到1e5
	*/
	srand((unsigned)time(NULL));
	string s1, s2; std::cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	vector<Z>f1(s1.size());
	vector<Z>f2(s2.size());
	for (ll i = 0; i < s1.size(); i++)f1[i] = s1[i] - '0';
	for (ll i = 0; i < s2.size(); i++)f2[i] = s2[i] - '0';
	auto g = Poly(f1) * Poly(f2);
	ll pre = 0; vector<ll>res;
	for (ll i = 0; i < g.size(); i++) {
		ll cur = g[i].val();
		cur += pre;
		res.push_back(cur % 10);
		pre = cur / 10;
	}
	while (pre) {
		res.push_back(pre % 10);
		pre /= 10;
	}
	while (res.back() == 0)res.pop_back();
	ll q; std::cin >> q;
	auto ksm = [&](ll a, ll u, ll n) {
		ll ret = 1;
		while (u) {
			if (u & 1)ret = ret * a % n;
			a = a * a % n;
			u >>= 1;
		}
		return ret % n;
	};
	auto mr = [&](ll n) {
		if (n < 3 or n % 2 == 0)return n == 2;
		ll u = n - 1, t = 0;
		while (u % 2 == 0)u /= 2, t++;
		for (ll i = 0; i <= 15; i++) {
			ll a = rand() % (n - 2) + 2, v = ksm(a, u, n);
			if (v == 1)continue;
			ll s;
			for (s = 0; s < t; s++) {
				if (v == n - 1)break;
				v = v * v % n;
			}
			if (s == t)return false;
		}
		return true;
	};
	//miller rabin素性检验

	while (q--) {
		ll l, r; std::cin >> l >> r;
		ll w = 0;
		for (ll i = r - 1; i >= l - 1; i--)w = (w * 10 + res[i]);
		if (w == 0 or w == 1 or mr(w)) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}

}
signed main() {
	solve();
}