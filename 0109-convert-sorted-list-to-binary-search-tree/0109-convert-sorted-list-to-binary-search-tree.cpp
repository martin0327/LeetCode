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
    vector<int> a;
    void f(ListNode* v) {
        while (v) {
            a.push_back(v->val);
            v = v->next;
        }
    }
    TreeNode* g(int l, int r) {
        if (l >= r) return nullptr;
        int m = (l+r)/2;
        TreeNode* v = new TreeNode(a[m]);
        v->left = g(l, m);
        v->right = g(m+1, r);
        return v;        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        f(head);
        int n = a.size();
        sort(a.begin(), a.end());
        return g(0, n);
    }
};