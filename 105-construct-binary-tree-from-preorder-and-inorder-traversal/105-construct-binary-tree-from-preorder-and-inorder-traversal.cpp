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
    TreeNode* f(vector<int> &a, vector<int> &b) {
        TreeNode* ret = new TreeNode(a[0]);
        unordered_set<int> sl;
        vector<int> left;
        vector<int> right;
        for (auto x : b) {
            if (x==a[0]) break;
            sl.insert(x);
        }
        for (auto x : a) {
            if (x==a[0]) continue;
            if (sl.count(x)) left.push_back(x);
            else right.push_back(x);
        }
        if (left.size()) ret->left = f(left,b);
        if (right.size()) ret->right = f(right,b);
        return ret;        
    }
    TreeNode* buildTree(vector<int>& a, vector<int>& b) {
        TreeNode* ans = f(a,b);
        return ans;
    }
};