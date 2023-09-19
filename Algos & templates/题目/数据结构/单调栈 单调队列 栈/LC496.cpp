class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    vector<int>id(m, -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (nums2[j] == nums1[i]) {
          id[j] = i; break;
        }
      }
    }
    std::vector<int>st; vector<int>ans(n, -1);
    for (int i = 0; i < m; i++) {
      while (st.size() and nums2[st.back()] < nums2[i]) {
        if (id[st.back()] != -1) {
          ans[id[st.back()]] = nums2[i];
        }
        st.pop_back();
      }
      st.push_back(i);
    }
    return ans;
  }
};