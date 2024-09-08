/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        vector<int> a;
        while (head) {
            a.push_back(head->val);
            head = head->next;
        }
        int n = a.size();
        
        function<bool(TreeNode*,int)> g = [&] (TreeNode* v, int d) {
            bool ret = false;
            if (!v || v->val != a[d]) return ret;
            if (d == n-1) return true;
            ret |= g(v->left,d+1);
            ret |= g(v->right,d+1);
            return ret;
        };
        
        function<bool(TreeNode*)> f = [&] (TreeNode* v) {
            bool ret = false;
            if (!v) return ret;
            ret |= g(v,0);
            ret |= f(v->left);
            ret |= f(v->right);
            return ret;
        };
        
        return f(root);
    }
};