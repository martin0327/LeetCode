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
    vector<vector<int>> ret;
    int tg;    
    void f(TreeNode *node, vector<int> &a, int cum) {
        if (!node) return;
        a.push_back(node->val);
        cum += node->val;
        if (!node->left && !node->right) {
            if (cum==tg) ret.push_back(a);
            a.pop_back();
            return;
        }
        if (node->left) f(node->left,a,cum);
        if (node->right) f(node->right,a,cum);        
        cum -= node->val;
        a.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        tg = targetSum;
        vector<int> a;
        f(root,a,0);
        return ret;
    }
};