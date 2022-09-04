/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    using pii = pair<int,int>;
    using vp = vector<pii>;
    map<int,vp> mp;
    void f(TreeNode *node, int col, int row) {
        if (!node) return;
        mp[col].push_back({row,node->val});
        f(node->left, col-1, row+1);
        f(node->right, col+1, row+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        f(root,0,0);
        vector<vector<int>> ret;
        for (auto &[k,v] : mp) {
            sort(v.begin(), v.end());
            vector<int> temp;
            for (auto [row,val] : v) {
                temp.push_back(val);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};