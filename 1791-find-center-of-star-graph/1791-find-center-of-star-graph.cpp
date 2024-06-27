class Solution {
public:
    int findCenter(vector<vector<int>>& e) {
        int n = e.size()+1;
        vector<int> d(n+1);
        for (auto v : e) {
            if (++d[v[0]] > 1) return v[0];
            if (++d[v[1]] > 1) return v[1];
        }
        return -1;
    }
};