
 
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<int,int,int>;
using vti3 = vector<ti3>;
class Solution {
public:
    string getDirections(TreeNode* root, int src, int tg) {
        vti3 a;
        int n = 0;
        function<void(TreeNode*)> f = [&] (TreeNode* u) {
            if (!u) return;
            n = max(n, u->val);
            if (u->left) {
                int uu = u->val;
                int vv = u->left->val;
                a.push_back({uu,vv,0});
                a.push_back({vv,uu,2});
            }
            if (u->right) {
                int uu = u->val;
                int vv = u->right->val;
                a.push_back({uu,vv,1});
                a.push_back({vv,uu,2});
            }
            f(u->left);
            f(u->right);
        };
        f(root);
        n++;
        vvp adj(n);
        
        for (auto [u,v,w] : a) {
            adj[u].push_back({v,w});
        }
        string ans;
        function<bool(int,int)> g = [&] (int u, int p) {
            if (u == tg) return true;
            bool ret = false;
            for (auto [v,w] : adj[u]) {
                if (v == p) continue;
                if (g(v,u)) {
                    ret = true;
                    if (w == 0) ans += 'L';
                    else if (w == 1) ans += 'R';
                    else ans += 'U';
                }
            }
            return ret;
        };

        g(src,-1);
        reverse(ans.begin(), ans.end());
        return ans;

    }
};