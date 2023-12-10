class Solution {
public:
    /*栈模拟求值*/
    typedef long long ll;
    int evalRPN(vector<string>& tokens) {
        vector<int>v;
        for (auto s : tokens) {
            if (isdigit(s[0]) or s.size() != 1) {
                v.push_back(stoi(s));
            } else {
                int c = 0;
                if (s == "+") {
                    int c1 = v.back(); v.pop_back();
                    int c2 = v.back(); v.pop_back();
                    c = c1 + c2; v.push_back(c);
                } else if (s == "-") {
                    int c1 = v.back(); v.pop_back();
                    int c2 = v.back(); v.pop_back();
                    c = c2 - c1; v.push_back(c);
                } else if (s == "*") {
                    int c1 = v.back(); v.pop_back();
                    int c2 = v.back(); v.pop_back();
                    c = c1 * c2; v.push_back(c);
                } else if (s == "/") {
                    int c1 = v.back(); v.pop_back();
                    int c2 = v.back(); v.pop_back();
                    c = c2 / c1; v.push_back(c);
                }
            }
        }
        return v.back();
    }
};

class Solution {
public:
    /*逆波兰表达式可以直接模拟二叉树求值*/
    typedef long long ll;
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        function<pair<int, int>(int)>dfs = [&](int cur)->pair<int, int> {
            if (isdigit(tokens[cur][0]) or tokens[cur].length() != 1) {
                return make_pair(stoi(tokens[cur]), 1);//如果是操作数则是底层,直接返回
            }
            char opt = tokens[cur][0];
            pair<int, int> ret1 = dfs(cur - 1);
            int c1 = ret1.first, len1 = ret1.second;
            pair<int, int> ret2 = dfs(cur - 1 - len1);
            int c2 = ret2.first, len2 = ret2.second;
            int ans = 0;
            /*回溯的过程中求解*/
            if (opt == '+')ans = c2 + c1;
            else if (opt == '-')ans = c2 - c1;
            else if (opt == '*')ans = c2 * c1;
            else if (opt == '/')ans = c2 / c1;
            return {ans, len2 + len1 + 1};//同时维护表达式长度和答案
        };
        pair<int, int> ans = dfs(len - 1);
        return ans.first;
    }
    
};