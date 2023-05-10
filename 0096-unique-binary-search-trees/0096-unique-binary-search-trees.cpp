using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;

class Solution {
public:
    int numTrees(int n) {
        vi a(n+1);
        // vvi b(n+1);
        // for (int i=1; i<=n; i++) {
        //     b[i] = vi(i);
        // }
        a[0] = a[1] = 1;
        for (int i=2; i<=n; i++) {
            for (int j=0; j<i; j++) {
                a[i] += a[j] * a[i-1-j]; 
            }
        }
        return a[n];
    }
};