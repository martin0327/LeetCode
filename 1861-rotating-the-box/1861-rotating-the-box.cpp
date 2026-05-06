using vi = vector<int>;
using vc = vector<char>;

template <typename T>
void debug(vector<T> &a) {
    for (auto x : a) {
        cout << x << " ";
    }   cout << endl;
}

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& a) {
        auto f = [&] (vc &a) {
            int n = a.size();
            vi b, c = {0};
            for (int i=0; i<n; i++) {
                if (a[i] == '#') {
                    c.back()++;
                    a[i] = '.';
                }
                else if (a[i] == '*') c.push_back(0);
            }
            for (int i=n-1,flag=(c.back()>0); i>=0; i--) {
                if (a[i]=='.') {
                    if (flag) {
                        c.back()--;
                        a[i] = '#';
                    }
                    flag &= (c.back() > 0);
                }
                else {
                    c.pop_back();
                    flag = c.back() > 0;
                }
            }
        };
        
        for (auto &v : a) {
            f(v);
        }
        
        auto g = [&] (vector<vc> &a) {
            int n = a.size(), m = a[0].size();
            vector<vc> ret(m,vc(n));
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    ret[j][n-1-i] = a[i][j];
                }
            }
            return ret;
            
        };
        return g(a);
    }
};