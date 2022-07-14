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
    
    map<int,int> mp;
    vector<int> a,b;   
    int n;
    
    TreeNode* f(int l1, int r1, int l2, int r2) {
        if (l1>r1) return nullptr;
        TreeNode* ret = new TreeNode(a[l1]);
        int pivot = mp[a[l1]];
        int llen = pivot - l2;
        int rlen = r2 - pivot;
        ret->left = f(l1+1,l1+llen,l2,l2+llen-1);
        ret->right = f(r1-rlen+1,r1,r2-rlen+1,r2);        
        return ret;
    }
    TreeNode* buildTree(vector<int>& _a, vector<int>& _b) {
        a = _a;
        b = _b;
        n = b.size();
        for (int i=0; i<n; i++) {
            mp[b[i]] = i;
        }
        TreeNode* ans = f(0,n-1,0,n-1);
        
        return ans;
    }
};