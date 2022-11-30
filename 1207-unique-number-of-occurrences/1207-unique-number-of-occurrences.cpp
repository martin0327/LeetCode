class Solution {
public:
    bool uniqueOccurrences(vector<int>& a) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        set<int> s;
        for (auto &[k,v] : mp) s.insert(v);
        return s.size() == mp.size();
    }
};