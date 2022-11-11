class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int idx = 1;
    for (int i=0; i<n-1; i++) {
      if (nums[i] < nums[i+1]) nums[idx++] = nums[i+1];
    }
    return idx;
  }
};