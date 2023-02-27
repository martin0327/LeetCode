class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& a) {
        int n = a.size();
        vector<int> b(n);
        for (int i=0; i<n; i++) {
            int l = 0, r = 0;
            for (int j=0; j<i; j++) l += a[j];
            for (int j=i+1; j<n; j++) r += a[j];
            b[i] = abs(l-r);
        }
        return b;
    }
};