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
    // [1,2,4,6,9,13,14,15] sorted array(list, vector)
    vector<int> a;
    
    void f(TreeNode *node) {
        // dfs on bst
        if (!node) return;
        a.push_back(node->val);
        f(node->left);
        f(node->right);
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& qr) {
        f(root); // O(n) graph treversal O(V+E) = O(n)
        sort(a.begin(), a.end());
        int n = a.size();
        vector<vector<int>> ret;
        for (auto x : qr) {
            vector<int> temp;
            {
                int lo = 0;
                int hi = n-1;
                int ans = -1;
                while (lo <= hi) {
                    int mid = (lo+hi)/2;
                    if (a[mid] <= x) {
                        ans = a[mid];
                        lo = mid + 1;
                    }
                    else hi = mid - 1;
                }
                temp.push_back(ans);
            }
            {
                int lo = 0;
                int hi = n-1;
                int ans = -1;
                while (lo <= hi) {
                    int mid = (lo+hi) / 2;
                    if (a[mid] >= x) {
                        ans = a[mid];
                        hi = mid - 1;
                    }
                    else lo = mid + 1;
                }
                temp.push_back(ans);
            }
            ret.push_back(temp);
        }
        return ret;
    }
};

