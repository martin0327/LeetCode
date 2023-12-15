class Solution {
public:
    string destCity(vector<vector<string>>& p) {
        set<string> a,b;
        for (auto uv : p) {
            a.insert(uv[0]);
            b.insert(uv[1]);
        }
        string ans;
        for (auto s : b) {
            if (!a.count(s)) ans = s;
        }
        return ans;
    }
};