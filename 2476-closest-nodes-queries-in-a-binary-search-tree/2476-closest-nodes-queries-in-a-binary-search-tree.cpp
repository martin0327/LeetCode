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
    set<int> s;
    void f(TreeNode* node) {
        if (!node) return;
        s.insert(node->val);
        f(node->left);
        f(node->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& qr) {
        f(root);
        vector<vector<int>> ret;
        for (auto x : qr) {
            vector<int> temp;
            auto it1 = s.upper_bound(x);
            if (it1 == s.begin()) temp.push_back(-1);
            else temp.push_back(*prev(it1));
            auto it2 = s.lower_bound(x);
            if (it2 == s.end()) temp.push_back(-1);
            else temp.push_back(*it2);
            ret.push_back(temp);
        }
        return ret;
    }
};