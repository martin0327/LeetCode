class Solution {
public:
    vector<int> getMaximumXor(vector<int>& a, int m) {
        vector<int> ans;
        int n = a.size(), x = (1<<m)-1;
        for (auto y : a) x ^= y;
        for (int i=n-1; i>=0; i--) {
            ans.push_back(x);
            x ^= a[i];
        }
        return ans;        
    }
};