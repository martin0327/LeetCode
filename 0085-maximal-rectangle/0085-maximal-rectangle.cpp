

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
      typedef vector<int> vi;
      typedef vector<vi> vvi;
      typedef pair<int,int> pii;

      int n = a.size();
      if (n==0) return 0;

      int m = a[0].size();
      if (m==0) return 0;

      vvi b(n, vi(m));
      for (int i=0; i<n; i++) {
        for (int j=m-1; j>=0; j--) {
          if (j==m-1) {
            if (a[i][j] == '1') {
              b[i][j] = 1;
            }
          }
          else {
            if (a[i][j] == '1') {
              b[i][j] = b[i][j+1] + 1;
            }
          }
        }
      }

      int ans = 0;

      for (int j=0; j<m; j++) {
        stack<pii>st;
        st.push({b[0][j],0});
        for (int i=1; i<n; i++) {
          int pos = i;
          while (!st.empty()) {
            auto [val,idx] = st.top();
            ans = max(ans, val * (i-idx));
            if (val <= b[i][j]) break;
            pos = idx;
            st.pop();
          }
          st.push({b[i][j],pos});
        }
        while (!st.empty()) {
          auto [val,idx] = st.top();
          ans = max(ans, val * (n-idx));
          st.pop();
        }
      }
      return ans;            
    }
};