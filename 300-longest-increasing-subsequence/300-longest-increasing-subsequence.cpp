class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> dp = {a[0]};
        for (int &x : a) {
            if (x > dp.back()) dp.push_back(x);
            else *lower_bound(dp.begin(),dp.end(),x) = x;
        }
        return dp.size();           
    }
};