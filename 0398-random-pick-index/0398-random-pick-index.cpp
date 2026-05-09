mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
class Solution {
public:
    map<int,vector<int>> mp;
    Solution(vector<int>& a) {
        int n = a.size();
        for (int i=0; i<n; i++) {
            mp[a[i]].push_back(i);
        }
    }
    
    int pick(int tg) {
        auto &v = mp[tg];
        return v[rng() % v.size()];
    }
};