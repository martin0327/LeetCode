using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& a) {
        int n = a.size();
        vvi ret(n-2, vi(n-2));
        for (int i=0; i<n-2; i++) {
            for (int j=0; j<n-2; j++) {
                int temp = 0;
                for (int k=i; k<i+3; k++) {
                    for (int l=j; l<j+3; l++) {
                        temp = max(temp, a[k][l]);
                    }
                }
                ret[i][j] = temp;
            }
        }
        return ret;
    }
};