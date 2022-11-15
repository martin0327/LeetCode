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
    
    int f(TreeNode* node) {
        if (!node) return 0;
        TreeNode *r=node, *l=node;
        int lcnt = 1, rcnt = 1;
        while (l = l->left) ++lcnt;
        while (r = r->right) ++rcnt;
        if (lcnt==rcnt) return (1<<lcnt)-1;
        return 1 + f(node->left) + f(node->right);
    }
    int countNodes(TreeNode* root) {
        return f(root);
    }
};
