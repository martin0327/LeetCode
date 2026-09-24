using vi = vector<int>;
using vvi = vector<vi>;
void debug(vi a) {
    for (auto x : a) cout << x << " ";
    cout << endl;
}
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edg) {
        int n = edg.size();
        vi deg(n);
        for (auto &e : edg) {
            auto &u = e[0], &v = e[1];
            u--; v--;
            deg[v]++;
        }
        auto f = [&] () {
            vi b;
            for (int i=0; i<n; i++) {
                if (deg[i] == 0) b.push_back(i);
            }
            if (b.size() == 1) return b[0];
            return -1;
        };
        reverse(edg.begin(), edg.end());
        for (int i=0; i<n; i++) {
            auto &e = edg[i];
            auto &u = e[0], &v = e[1];
            deg[v]--;
            auto src = f();
            if (src == -1) {
                deg[v]++;
                continue;
            }
            vvi adj(n);
            for (int j=0; j<n; j++) {
                if (i == j) continue;
                auto &e = edg[j];
                adj[e[0]].push_back(e[1]);
            }
            // cout << src << endl;
            // for (auto &v : adj) debug(v);

            function<int(int)> f = [&] (int u) {
                int ret = 1;
                for (auto v : adj[u]) {
                    ret += f(v);
                }
                return ret;
            };

            if (f(src) == n) {
                e[0]++; e[1]++;
                return e;
            }
            deg[v]++;
        }
        return edg[0];
    }
};