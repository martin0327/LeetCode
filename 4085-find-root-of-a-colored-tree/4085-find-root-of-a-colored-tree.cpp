using vi = vector<int>;
using vvi = vector<vi>;
const int sz = 1e5+5;
vi adj[sz];
int deg[sz];
int root;
bool ok;
string s;
map<char,int> c2i;

void f(int u, int p) {
    int i = c2i[s[u]];
    if (p != -1) {
        int pi = c2i[s[p]];
        if (i == pi) ok = false;
        if ((i+1)%3 == pi && deg[u] < 3) {
            root = u;
        }
    }
    for (auto v : adj[u]) {
        if (v == p) continue;
        f(v,u);
    }
}

void g(int u, int p) {
    int i = c2i[s[u]];
    if (p != -1) {
        int pi = c2i[s[p]];
        ok &= ((pi+1)%3 == i);
    }
    for (auto v : adj[u]) {
        if (v == p) continue;
        g(v,u);
    }
}

class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edg, string _s) {
        s = _s;
        int n = edg.size() + 1;
        for (int i=0; i<n; i++) adj[i].clear();
        memset(deg,0,sizeof(deg));
        for (auto &uv : edg) {
            int u = uv[0], v = uv[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        if (c2i.empty()) {
            string t = "RBW";
            for (int i=0; i<3; i++) {
                c2i[t[i]] = i;
            }
        }
        ok = true;
        root = 0;
        f(0,-1);
        if (!ok) return -1;
        if (root == 0 && deg[0] > 2) return -1;

        g(root,-1);
        if (ok) return root;
        else return -1;
    }
};