#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	while (T--) {
		ll a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (a == 1 && a == b) {
			cout << "niumei" << endl;
			continue;
		}
		if (a == b && a > 2) {
			a -= 2;
			b -= 1;
			if (a % 3 == 1 || a % 3 == 2) {
				cout << "niumei" << endl;

			}
			else {
				cout << "niuniu" << endl;
			}
			continue;
		}
		if (a % 3 == 1 || a % 3 == 2) {
			cout << "niuniu" << endl;

		}
		else {
			cout << "niumei" << endl;
		}

	}
	return 0;
}

