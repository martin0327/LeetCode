using vs = vector<string>;
class Solution {
public:
    vector<string> findRestaurant(vector<string>& a, vector<string>& b) {
        int n = a.size(), m = b.size(), sz = 2001;
        map<string,int> mp;
        for (int i=0; i<n; i++) {
            auto &s = a[i];
            if (mp.count(s)) continue;
            mp[s] = i;
        }
        vector<vs> res(sz);
        for (int j=0; j<m; j++) {
            auto &s = b[j];
            if (mp.count(s)) {
                res[j + mp[s]].push_back(s);
            }
        }
        for (auto &v : res) {
            if (v.size()) return v;
        }
        return a;
    }
};