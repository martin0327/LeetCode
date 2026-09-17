using vi = vector<int>;
class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& a, vector<int>& rowShift, vector<int>& colShift) {
        for (int i=0; i<n; i++) {
            auto v = a[i];
            auto t = rowShift[i];
            for (int j=0; j<n; j++) {
                a[i][j] = v[(j+t)%n];
            }
        }
        for (int j=0; j<n; j++) {
            vi v(n);
            auto t = colShift[j];
            for (int i=0; i<n; i++) v[i] = a[i][j];
            for (int i=0; i<n; i++) {
                a[i][j] = v[(i+t)%n];
            }
        }
        return a;
    }
};