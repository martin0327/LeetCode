class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& a) {
        set<int> s;
        map<int,int> l;
        for (auto b : a) {
            int u = b[0];
            int v = b[1];
            s.insert(u);
            s.insert(v);
            l[v]++;
        }
        vector<int> ans0, ans1;
        for (auto x : s) {
            if (!l.count(x)) ans0.push_back(x);
            if (l[x] == 1) ans1.push_back(x);
        }
        return {ans0,ans1};
    }
};