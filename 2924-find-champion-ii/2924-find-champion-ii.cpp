class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> deg(n), res;
        for (auto uv : edges) {
            deg[uv[1]]++;
        }
        for (int i=0; i<n; i++) {
            if (deg[i]==0) res.push_back(i);
        }
        return (res.size() > 1) ? -1 : res.back();
    }
};