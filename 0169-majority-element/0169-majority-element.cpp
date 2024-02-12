class Solution {
public:
    int majorityElement(vector<int>& nums) {
      int n = nums.size();
        int m = n / 2;
      map<int,int> cnt;
      for (auto x : nums) {
        cnt[x]++;
        if (cnt[x] > m) return x;
      }
      return 0;
    }
};