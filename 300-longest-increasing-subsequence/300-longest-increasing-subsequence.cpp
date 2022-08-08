const int inf = 1e9;
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> dp = {-inf};
        for (auto x : a) {
            if (x > dp.back()) dp.push_back(x);
            else *lower_bound(dp.begin(),dp.end(),x) = x;
        }
        int ans = dp.size()-1;
        return ans;        
    }
};