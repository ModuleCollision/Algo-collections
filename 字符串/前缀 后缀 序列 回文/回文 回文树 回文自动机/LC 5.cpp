class Solution {
public:
    string longestPalindrome(string s) {
        vector<int>d1(2005);
        int SZ = s.size();
        for (int i = 0; i < 2 * SZ + 1; i += 2)s.insert(i, "#");
        for (int i = 0, l = 0, r = -1; i < (int)s.size(); i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < (int)s.size() && s[i - k] == s[i + k]) {
                k++;
            }
            d1[i] = k--;
            if (i + k > r) {

                r = i + k;
                l = i - k;
            }
        }
        int pos = max_element(d1.begin(), d1.end(), [](int a, int b)->bool{
            return ((a << 1 ) - 1) / 2 < ((b << 1) - 1) / 2;
        }) - d1.begin();
        std::string ret;
        for (int j = pos - d1[pos] + 1; j <= pos + d1[pos] - 1; j++) {
            if (s[j] != '#') {
                ret += s[j];
            }
        }
        return ret;
    }
};