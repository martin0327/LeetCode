class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        vector<pair<int,int>> b;
        for (auto [k,v] : mp) b.emplace_back(v,k);
        sort(b.rbegin(), b.rend());
        vector<int> ans;
        for (int i=0; i<k; i++) ans.push_back(b[i].second);
        return ans;
    }
};