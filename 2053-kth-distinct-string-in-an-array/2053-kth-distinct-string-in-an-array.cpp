class Solution {
public:
    string kthDistinct(vector<string>& a, int k) {
        map<string,int> mp;
        for (auto &s : a) mp[s]++;
        int idx = 0;
        for (auto &s : a) {
            if (mp[s] == 1) idx++;
            if (idx == k) return s;
        }
        return "";
    }
};