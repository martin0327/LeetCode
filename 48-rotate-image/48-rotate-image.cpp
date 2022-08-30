using vi = vector<int>;
class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n = a.size();
        for (int i=0; i<n/2; i++) {
            int m = n-2*i-1;
            vi b(4*m);
            for (int j=0; j<m; j++) {
                b[j] = a[i][i+j];
                b[m+j] = a[i+j][m+i];
                b[2*m+j] = a[m+i][m+i-j];
                b[3*m+j] = a[m+i-j][i];
            }
            for (int j=0; j<m; j++) {
                a[i][i+j] = b[3*m+j];
                a[i+j][m+i] = b[j];
                a[m+i][m+i-j] = b[m+j];
                a[m+i-j][i] = b[2*m+j];
            }
        }
    }
};