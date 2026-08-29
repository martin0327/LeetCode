template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }

const int maxn = 1e5+5, maxm = 20;
int n,m;
int table[maxm][maxn];
int a[maxn];

int query(int l, int r) {
    chmax(l,0);
    chmin(r,n-1);
    int u = __lg(r-l+1);
    if (l <= r) return gcd(table[u][l], table[u][r-(1<<u)+1]);
    else return 0;
}

class Solution {
public:
    int maxValidSplits(vector<int>& aa) {
        n = aa.size(), m = 20;
        for (int i=0; i<n; i++) a[i] = aa[i];
        for (int i=0; i<n; i++) table[0][i] = a[i];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j + (1<<i) <= n; j++) {
                table[i][j] = gcd(table[i-1][j], table[i-1][j + (1<<(i-1))]);
            }
        }

        auto g = [&] (int l, int r, int i) {
            if (i < l || i > r) return query(l,r);
            int x = query(l,i-1);
            int y = query(i+1,r);
            return gcd(x,y);
        };

        auto f = [&] (int i) {
            int l = -1, r = -2;
            if (n > 1) {
                int lo = 0, hi = n-2, ans = -2;
                if (i == 0) lo = 1;
                if (i == n-1) hi--;
                while (lo <= hi) {
                    int mid = (lo+hi)/2;
                    auto x = g(0,mid,i);
                    auto y = g(mid+1,n-1,i);
                    if (x >= y) {
                        ans = mid;
                        lo = mid + 1;
                    }
                    else hi = mid - 1;
                }
                if (ans != -2 && g(0,ans,i) == g(ans+1,n-1,i)) r = ans;
            }
            if (n > 1) {
                int lo = 0, hi = n-2, ans = -1;
                if (i == 0) lo = 1;
                if (i == n-1) hi--;
                while (lo <= hi) {
                    int mid = (lo+hi)/2;
                    auto x = g(0,mid,i);
                    auto y = g(mid+1,n-1,i);
                    if (y >= x) {
                        ans = mid;
                        hi = mid - 1;
                    }
                    else lo = mid + 1;
                }
                if (ans != -1 && g(0,ans,i) == g(ans+1,n-1,i)) l = ans;
            }
            if (l == i) l++;
            if (r == i) r--;
            int res = 0; 
            if (l <= r) {
                res = r-l+1;
                if (l <= i && i <= r) res--;
            }
            return res;
        };
        int ans = f(-1);
        for (int i=0; i<n; i++) {
            int t = f(i);
            chmax(ans, t);
        }
        return ans;
    }
};