using vi = vector<int>;

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vi b(max(n,m));
        for (int k=0; k<n; k++) {
            int sz = min(n-k, m);
            for (int d=0; d<sz; d++) {
                b[d] = a[k+d][d];
            }
            sort(b.begin(), b.begin()+sz);
            for (int d=0; d<sz; d++) {
                a[k+d][d] = b[d];
            }
        }
        for (int k=1; k<m; k++) {
            int sz = min(n, m-k);
            for (int d=0; d<sz; d++) {
                b[d] = a[d][k+d];
            }
            sort(b.begin(), b.begin()+sz);
            for (int d=0; d<sz; d++) {
                a[d][k+d] = b[d];
            }
        }
        return a;
    }
};