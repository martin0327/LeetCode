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
    int widthOfBinaryTree(TreeNode* root) {
      typedef vector<int> vi;
      typedef vector<vi> vvi;
      queue<tuple<TreeNode*,int,vi>> q;
      q.push({root,0,vi(0)});
      map<int,vvi> mp;
      mp[0].push_back(vi(0));
      while (q.size()) {
        auto [node, depth, pos] = q.front();
        q.pop();
        if (node->left) {
          vi temp = pos;
          temp.push_back(0);
          q.push({node->left, depth+1, temp});
          mp[depth+1].push_back(temp);
        }
        if (node->right) {
          vi temp = pos;
          temp.push_back(1);
          q.push({node->right, depth+1, temp});
          mp[depth+1].push_back(temp);
        }
      }
      int ans = 1;
      for (auto [k,v] : mp) {
        if (v.size()==1) continue;
        sort(v.begin(), v.end());
        vi left = v.front();
        vi right = v.back();
        int cnt = 0;
        int n = left.size();
        int bt = -1;
        for (int i=0; i<n; i++) {
          if (bt==-1) {
            if (left[i] == right[i]) continue;
            else bt = 0;
          }
          else {
            if (left[i]==right[i]) bt = 2*bt + 1;
            else if (left[i]<right[i]) bt = 2*bt + 2;
            else bt = 2*bt;
          }
        }
        ans = max(ans, bt + 2);        
      }
      return ans;
    }
};