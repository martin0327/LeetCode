class Solution {
public:
    vector<int> frequencySort(vector<int>& a) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        vector<pair<int,int>> b;
        for (auto [k,v] : mp) {
            b.push_back({v,-k});
        }
        sort(b.begin(), b.end());
        vector<int> ans;
        for (auto [cnt,x] : b) {
            x *= -1;
            while (cnt--) ans.push_back(x);
        }
        return ans;
    }
};