class Solution {
public:
  int numRescueBoats(vector<int>& people, int limit) {
    int n = people.size(); int ans = n;
    sort(people.begin(), people.end());
    for (int l = 0, r = n - 1; l < r; l++) {
      if (people[l] + people[r] <= limit) {
        l ++ ;
      } r--; ans--;
    }
    return ans;
  }
};