class Solution {
public:
    int longestSubsequence(vector<int>& a, int d) {
        map<int,int> mp;
        for (auto x : a) {
            if (mp.count(x-d)) {
                mp[x] = mp[x-d]+1;
            }
            else mp[x] = 1;
        }
        int ans = 0;
        for (auto &[k,v] : mp) {
            ans = max(ans, v);
        }
        return ans;
    }
};