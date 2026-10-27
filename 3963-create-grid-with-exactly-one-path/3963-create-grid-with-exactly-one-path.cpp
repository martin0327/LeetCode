class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string> a(n);
        for (int i=0; i<n; i++) {
            if (i == 0) a[i] = string(m, '.');
            else a[i] = string(m, '#');
        }
        for (int i=0; i<n; i++) {
            a[i].back() = '.';
        }
        return a;        
    }
};