using ti3 = tuple<int,int,int>;
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& ev) {
        map<int,int> comp;
        vector<ti3> a;
        for (auto v : ev) {
            int s = v[0], e = v[1], w = v[2];
            a.push_back({s,e,w});
            comp[s];
            comp[e];
        }
        int sz = 0;
        for (auto &[k,v] : comp) v = sz++;
        vector<int> b(sz+1);
        for (auto &[s,e,w] : a) {
            s = comp[s];
            e = comp[e];
            b[s] = max(b[s], w);
        }
        for (int i=sz-1; i>=0; i--) {
            b[i] = max(b[i], b[i+1]);
        }
        int ans = 0;
        for (auto &[s,e,w] : a) {
            ans = max(ans, b[e+1] + w);
        }
        return ans;
    }
};