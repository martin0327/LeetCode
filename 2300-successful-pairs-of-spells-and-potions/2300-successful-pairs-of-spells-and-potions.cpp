class Solution {
public:
    vector<int> successfulPairs(vector<int>& a, vector<int>& b, long long s) {
        int m = b.size();
        sort(b.begin(), b.end());
        vector<int> ans;
        for (auto x : a) {
            long long target = s / x;
            if (s%x) target++;
            auto it = lower_bound(b.begin(), b.end(), target);
            ans.push_back(b.end()-it);
        }
        return ans;
    }
};