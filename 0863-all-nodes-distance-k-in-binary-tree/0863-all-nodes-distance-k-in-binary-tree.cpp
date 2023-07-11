using vi = vector<int>;
using vvi = vector<vi>;
const int inf = 1e9;
const int n = 501;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int src = -1;
        vvi adj(n);
        function<void(TreeNode*)> f = [&](TreeNode* u) {
            if (u == target) src = u->val;
            if (u->left) {
                int uu = u->val;
                int vv = u->left->val;
                adj[uu].push_back(vv);
                adj[vv].push_back(uu);
                f(u->left);
            }
            if (u->right) {
                int uu = u->val;
                int vv= u->right->val;
                adj[uu].push_back(vv);
                adj[vv].push_back(uu);
                f(u->right);
            }
        };
        f(root);
        queue<int> q;
        q.push(src);
        vi dist(n,inf);
        dist[src] = 0;
        vi ans;
        while (q.size()) {
            int u = q.front();
            q.pop();
            if (dist[u] == k) ans.push_back(u);
            if (dist[u] > k) break;
            for (auto v : adj[u]) {
                if (dist[v] < inf) continue;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
        return ans;
    }
};