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
const int inf = 1e9;
class Solution {
public:
    int n;
    vector<int> a,b;
    map<int,int> mp1, mp2;
    TreeNode* f(int l, int r) {
        if (l > r) return nullptr;
        int idx = mp1[b[r]];
        int llim = inf, rlim = -inf;
        for (int i=idx+1; i<n; i++) {
            if (mp2[a[i]] >= r) break;
            llim = min(llim, mp2[a[i]]);
        }
        for (int i=idx-1; i>=0; i--) {
            if (mp2[a[i]] >= r) break;
            rlim = max(rlim, mp2[a[i]]);
        }
        TreeNode* right = (llim!=inf) ? f(llim,r-1) : nullptr;
        TreeNode* left = (rlim!=-inf) ? f(l,rlim) : nullptr;
        return new TreeNode(b[r],left, right);
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        a = inorder, b = postorder;
        n = a.size();
        for (int i=0; i<n; i++) {
            mp1[a[i]] = i;
            mp2[b[i]] = i;
        }
        return f(0,n-1);
        
    }
};