class Solution {
public:
    vector<int> limitOccurrences(vector<int>& a, int k) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        vector<int> ans;
        for (auto [x,cnt] : mp) {
            int t = min(cnt,k);
            while (t--) ans.push_back(x);
        }
        return ans;
    }
};