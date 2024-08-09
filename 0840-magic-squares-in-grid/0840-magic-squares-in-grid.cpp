using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& a) {
        vi tg = {1,2,3,4,5,6,7,8,9};
        auto f = [&] (int r, int c) {
            int n = 3;
            vi b;
            for (int i=0; i<n; i++) {
                int cum = 0;
                for (int j=0; j<n; j++) {
                    int x = a[r+i][c+j];
                    cum += x;
                    b.push_back(x);
                }
                if (cum != 15) return false;
            }
            for (int j=0; j<n; j++) {
                int cum = 0;
                for (int i=0; i<n; i++) {                
                    int x = a[r+i][c+j];
                    cum += x;
                }
                if (cum != 15) return false;
            }
            {
                int cum = 0;
                for (int i=0; i<n; i++) {
                    int x = a[r+i][c+i];
                    cum += x;
                }
                if (cum != 15) return false;
            }
            {
                int cum = 0;
                for (int i=0; i<n; i++) {
                    int x = a[r+i][c+n-1-i];
                    cum += x;
                }
                if (cum != 15) return false;
            }
            sort(b.begin(), b.end());
            return (b == tg);
        };
        int n = a.size(), m = a[0].size(), ans = 0;
        for (int i=0; i+2<n; i++) {
            for (int j=0; j+2<m; j++) {
                if (f(i,j)) ans++;
            }
        }
        return ans;
    }
};