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
    int mx = -1, pr = -1;
    bool ret = true;
    void f(TreeNode* v, int d) {
        if (!v) {
            if (mx==-1) {
                mx = d;
                pr = d;
            }
            else {
                ret &= (mx - d <= 1) && (pr >= d);
                pr = d;
            }
            return;
        }
        f(v->left, d+1);
        f(v->right, d+1);
    }
    bool isCompleteTree(TreeNode* root) {
        f(root, 0);        
        return ret;    
    }
};        