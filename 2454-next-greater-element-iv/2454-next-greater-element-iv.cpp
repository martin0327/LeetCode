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

class Solution {
public:
  vector<int> secondGreaterElement(vector<int>& a) {
    int n = a.size();
    max_spt<int> spt(a);
    vector<int> ans(n, -1);
    for (int i=0; i<n-2; i++) {
      int lo = i+1;
      int hi = n-1;
      int k = -1;
      while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (spt.query(i+1,mid) > a[i]) {
          k = mid;
          hi = mid -1;        
        }
        else lo = mid + 1;
      }
      if (k==-1) continue;

      lo = k+1;
      hi = n-1;
      int j = -1;
      while (lo <= hi) {
        int mid = (lo+hi) / 2;
        if (spt.query(k+1,mid) > a[i]) {
          j = mid;
          hi = mid - 1;
        }
        else lo = mid + 1;
      }
      if (j == -1) continue;
      
      ans[i] = a[j];
    }
    return ans;
  }
};