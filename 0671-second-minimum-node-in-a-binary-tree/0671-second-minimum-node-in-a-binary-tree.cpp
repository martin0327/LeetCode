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
    int findSecondMinimumValue(TreeNode* root) {
        set<int> s;
        function<void(TreeNode*)> f = [&] (TreeNode* v) {
            if (!v) return;
            s.insert(v->val);
            f(v->left);
            f(v->right);
        };
        f(root);
        if (s.size() < 2) return -1;
        return *next(s.begin());
    }
};