class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) return nums;
        int left = -1, n = nums.size();
        vector<int> result;
        for (int i = 1; i < n; i++) {
            bool consecutive = nums[i] - 1 == nums[i-1];
            if (consecutive) {
                if (i - left > k - 1) // actually this is not needed
                    left++; //
            } else {
                left = i;
            }
            if (i < k - 1) 
                continue;
            result.push_back(i - left + 1 >= k ? nums[i] : -1);
        }
        
        return result;
    }
};
