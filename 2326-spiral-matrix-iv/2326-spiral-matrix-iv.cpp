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
class Solution {
public:
  vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
    using vi = vector<int>;
    using vvi = vector<vi>;
    vvi temp(n+2, vi(m+2, -2));
    for (int i=1; i<=n; i++) {
      for (int j=1; j<=m; j++) {
        temp[i][j] = -1;
      }
    }
    
    vi a;
    while (head) {
      a.push_back(head->val);
      head = head->next;
    }
    
    int r = 1;
    int c = 1;
    vi dr = {0,1,0,-1};
    vi dc = {1,0,-1,0};
    int d = 0;
    for (auto x : a) {
      temp[r][c] = x;
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (temp[nr][nc] == -1) {
        r = nr;
        c = nc;
      }
      else {
        d = (d+1)%4;
        r = r + dr[d];
        c = c + dc[d];
      }
    }
    vvi ret(n, vi(m));
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        ret[i][j] = temp[i+1][j+1];
      }
    }
    return ret;
  }
};