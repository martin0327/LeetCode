class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }

        int ancestor[26];
        ranges::fill(ancestor, -1);
        auto rebuild = [&](this auto&& rebuild, int x) -> void {
            int sx = s[x] - 'a';
            int old = ancestor[sx];
            ancestor[sx] = x;
            for (int i = g[x].size() - 1; i >= 0; i--) {
                int y = g[x][i];
                int anc = ancestor[s[y] - 'a'];
                if (anc != -1) {
                    g[anc].push_back(y);
                    g[x][i] = -1; // -1 表示删除 y
                }
                rebuild(y);
            }
            ancestor[sx] = old; // 恢复现场
        };
        rebuild(0);

        vector<int> size(n, 1); // 注意这里已经把 1 算进去了
        auto dfs = [&](this auto&& dfs, int x) -> void {
            for (int y : g[x]) {
                if (y != -1) { // y 没被删除
                    dfs(y);
                    size[x] += size[y];
                }
            }
        };
        dfs(0);
        return size;
    }
};