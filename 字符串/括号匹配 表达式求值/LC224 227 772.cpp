#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


/*Leetcode 227,主要求解不带括号的四则运算问题*/
/*基本思路即为把操作符和操作数入栈,然后把优先级高的元素先行合并,然后做总体运算*/
class Solution {
public:
	
	int calculate(string s) {
		i64 len = s.size();
		vector<i64>a; vector<char>opt;
		std::map<char, i64>pr;
		i64 ans = 0;
		auto eval = [&]() {
			i64 y = a.back(); a.pop_back();
			i64 x = a.back(); a.pop_back();
			char op = opt.back(); opt.pop_back();
			if (op == '+')a.push_back(x + y);
			else if (op == '-')a.push_back(x - y);
			else if (op == '*')a.push_back(x * y);
			else if (op == '/')a.push_back(x / y);
		};
		pr['+'] = pr['-'] = 1; pr['*'] = pr['/'] = 2;
		for (i64 i = 0; i < len; i++) {
			if (s[i] == ' ') 	continue;
			else if (isdigit(s[i])) {
				i64 cur = 0;
				while (isdigit(s[i]) and i < len) {
					cur = cur * 10 + s[i] - '0'; i++;
				}
				a.push_back(cur); i--;
			} else {
				char c = s[i];
				while (opt.size() and pr[opt.back()] >= pr[c]) {
					eval();
				}
				opt.push(c);
			}
		}
		while (opt.size())eval();
		return (int)a.back();
	}
};

/*Leetcode224*/
/*求解规定优先级的加减运算表达式*/
/*同理,我们设定操作符栈与操作数栈,注意特判单目运算符的情况*/
class Solution {
public:
	
	int calculate(string s) {
		vector<i64>a; vector<char>opt;
		auto cal = [&]() {
			if (opt.size() and (opt.back() == '+' or opt.back() == '-')) {
				char op = opt.back();opt.pop_back();
				i64 c2 = a.back(); a.pop_back();
				i64 c1 = a.back(); a.pop_back();
				if (op == '+') {
					a.push_back(c1 + c2);
				} else {
					a.push_back(c1 - c2);
				}
			}
		};
		char prev = '(';//括号中或是表达式开始的特判情况
		i64 len = s.size();
		for (i64 i = 0; i < len; i++) {
			if (s[i] == ' ')continue;
			if (isdigit(s[i])) {
				i64 cur = 0;
				while (i < len and isdigit(s[i])) {
					cur = cur * 10 + s[i] - '0';
					i++;
				}
				i--; a.push_back(cur);
			} else if (s[i] == '(') {
				opt.push_back(s[i]);
			} else if (s[i] == ')') {
				cal(); opt.pop_back();
			} else {
				if (prev == '(') {
					a.push_back(0);
				}
				cal();

				opt.push_back(s[i]);
			}
			prev = s[i];
		}
		cal();
		return a.back();
	}
};


/*Leetcode772*/

class Solution {
public:
	typedef long long i64;
	int calculate(string s) {
		i64 len = s.size();
		vector<i64>a; vector<char>opt;
		std::map<char, i64>pr;
		pr['+'] = pr['-'] = 1;
		pr['*'] = pr['/'] = 2;
		auto eval = [&]() {
			if (opt.size() and pr.count(opt.back())) {
				char op = opt.back();opt.pop_back();
				i64 c2 = a.back(); a.pop_back();
				i64 c1 = a.back(); a.pop_back();
				if (op == '+') {
					a.push_back(c1 + c2);
				} else if (op == '-') {
					a.push_back(c1 - c2);
				} else if (op == '*') {
					a.push_back(c1 * c2);
				} else if (op == '/') {
					a.push_back(c1 / c2);
				}
			}
		};
		char prev = '(';
		for (i64 i = 0; i < len; i++) {
			if (s[i] == ' ')continue;
			if (isdigit(s[i])) {
				i64 cur = 0;
				while (i < len and isdigit(s[i])) {
					cur = cur * 10 + s[i] - '0';
					i++;
				}
				i--; a.push_back(cur);
			} else if (s[i] == '(') {
				opt.push_back(s[i]);
			} else if (s[i] == ')') {
				cal(); opt.pop_back();
			} else {
				if (prev == '(') {//单目运算符的特判
					a.push_back(0);
				}
				char c = s[i];
				while (pr[opt.back()] >= pr[c]) {
					cal();
				}
				opt.push_back(s[i]);
			}
			prev = s[i];
		}
		cal();
		return a.back();
	}
};