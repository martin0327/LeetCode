template<typename T>
T spt_min(T x, T y) {return min(x,y);}

template<typename T>
T spt_max(T x, T y) {return max(x,y);}

template<typename T,  T (*op)(T, T)>
struct sparse_table {
  int n,m;
  vector<vector<T>> table;

  inline T merge(T x, T y) {
    return op(x, y);
  }

  sparse_table(vector<T> &a) {
    n = a.size();
    m = __lg(n) + 1;
    table.assign(m, vector<T>(n));
    for (int i = 0; i < n; i++) table[0][i] = a[i];
    for (int i = 1; i < m; i++) {
      for (int j = 0; j + (1 << i) <= n; j++) {
        table[i][j] = merge(table[i-1][j], table[i-1][j + (1 << (i-1))]);
      }
    }
  }

  T query(int l, int r, const int index = 0) {
    // l, r : inclusive
    assert(l <= r && 0 <= l && r < n);
    int u = __lg(r-l+1);
    return merge(table[u][l-index], table[u][r-index-(1 << u)+1]);
  }
};

template<typename T>
using min_spt = sparse_table<T,spt_min>;

template<typename T>
using max_spt = sparse_table<T,spt_max>;

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
using vi = vector<int>;

class Solution {
public:
  int n = 0, m = 0;
  vi height, euler;
  map<int,int> left, right;
  
  void cnt_sz(TreeNode *node) {
    if (!node) return;
    n++;
    cnt_sz(node->left);
    cnt_sz(node->right);
  }
  
  void f(TreeNode *node, int h) {
    if (!node) return;
    height[node->val] = h;
    left[node->val] = m++;
    f(node->left, h+1);
    f(node->right, h+1);
    right[node->val] = m++;
  }
    
  vector<int> treeQueries(TreeNode* root, vector<int>& qr) {
    cnt_sz(root);
    height = vi(n+1);
    f(root,0);
    euler = vi(m+1);
    
    for (auto [k,v] : left) euler[v] = height[k];
    for (auto [k,v] : right) euler[v] = height[k];
    
    max_spt<int> spt(euler);
    vector<int> ans;
    
    for (auto q : qr) {
      int l = left[q];
      int r = right[q];
      int h = max(spt.query(0,l-1), spt.query(r+1,m));
      ans.push_back(h);
    }    
    
    return ans;
  }
};