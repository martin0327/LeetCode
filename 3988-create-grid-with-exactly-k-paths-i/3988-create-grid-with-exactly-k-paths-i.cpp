using vs = vector<string>;
class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {
        bool flip = false;
        if (m < n) {
            swap(n,m);
            flip = true;
        }
        auto g = [&] (vector<string> a) {
            if (a.empty()) return a;
            int n = a.size(), m = a[0].size();
            vs b(m, string(n, ' '));
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    b[j][i] = a[i][j];
                }
            }
            return b;
        };
        vs a(n, string(m, '#'));
        if (n == 1) {
            if (k > 1) a.clear();
            else a = vs(n, string(m, '.'));
        }
        else {            
            if (k == 1) {
                for (int j=0; j<m; j++) a[0][j] = '.';
                for (int i=0; i<n; i++) a[i][m-1] = '.';
            }
            else if (k == 2) {
                a[0][0] = a[0][1] = a[1][0] = a[1][1] = '.';
                for (int j=1; j<m; j++) a[1][j] = '.';
                for (int i=1; i<n; i++) a[i][m-1] = '.';
            }
            else if (k == 3) {
                if (m == 2) {
                    a.clear();
                }
                else {
                    for (int j=0; j<3; j++) {
                        a[0][j] = '.';
                        a[1][j] = '.';
                    }
                    for (int j=3; j<m; j++) {
                        a[1][j] = '.';
                    }
                    for (int i=1; i<n; i++) {
                        a[i][m-1] = '.';
                    }
                }
            }
            else if (k == 4) {
                if (m >= 4) {
                    for (int j=0; j<4; j++) {
                        a[0][j] = '.';
                        a[1][j] = '.';
                    }
                    for (int j=4; j<m; j++) {
                        a[1][j] = '.';
                    }
                    for (int i=1; i<n; i++) {
                        a[i][m-1] = '.';
                    }
                }
                else if (m < 3) {
                    a.clear();
                }
                else {
                    if (n == 3) {
                        a = vs(3, string(3, '.'));
                        a[0][2] = a[2][0] = '#';
                    }
                    else {
                        a.clear();
                    }
                }
            }
        }
        if (flip) a = g(a);
        return a;
    }
};