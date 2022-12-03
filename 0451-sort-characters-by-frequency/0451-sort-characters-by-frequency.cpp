class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        for (auto c : s) mp[c]++;
        vector<pair<int,char>> b;
        for (auto &[k,v] : mp) b.push_back({v,k});
        sort(b.rbegin(), b.rend());
        string ans;
        for (auto [x,c] : b) {
            while (x--) ans += c;
        }
        return ans;
    }
};