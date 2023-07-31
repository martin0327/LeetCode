template<typename T> T spt_op_max(T x, T y) {return max(x,y);}
template<typename T> T spt_op_min(T x, T y) {return min(x,y);}
template<typename T> T spt_op_gcd(T x, T y) {return gcd(x,y);}
template<typename T> T spt_op_lcm(T x, T y) {return lcm(x,y);}

template<typename T,  T (*op)(T, T)>
struct sparse_table {
    int n,m;
    vector<vector<T>> table;

    inline T merge(T x, T y) {
        return op(x, y);
    }

    sparse_table(vector<T> &a) {
        n = a.size();
        m = __lg(n) + 1;
        table.assign(m, vector<T>(n));
        for (int i = 0; i < n; i++) table[0][i] = a[i];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j + (1<<i) <= n; j++) {
                table[i][j] = merge(table[i-1][j], table[i-1][j + (1<<(i-1))]);
            }
        }
    }

    T query(int l, int r) {
        // l, r : inclusive
        assert(l<=r && 0<=l && r< n);
        int u = __lg(r-l+1);
        return merge(table[u][l], table[u][r-(1<<u)+1]);
    }

};

template<typename T> using max_spt = sparse_table<T,spt_op_max>;
template<typename T> using min_spt = sparse_table<T,spt_op_min>;
template<typename T> using gcd_spt = sparse_table<T,spt_op_gcd>;
template<typename T> using lcm_spt = sparse_table<T,spt_op_lcm>;

using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    int validSubarraySize(vector<int>& a, int t) {
        ll n = a.size();
        vi b(n);
        for (int i=0; i<n; i++) {
            ll lo = 1, hi = t+1;
            while (lo <= hi) {
                ll mid = (lo+hi)/2;
                if (a[i] > t / mid) {
                    b[i] = mid;
                    hi = mid - 1;
                }
                else lo = mid + 1;
            }
        }
        
        max_spt<ll> spt(b);
        for (int i=0; i<n; i++) {
            int l = i, r = i;
            if (i > 0) {
                ll lo = 0, hi = i-1;
                while (lo <= hi) {
                    ll mid = (lo+hi)/2;
                    ll x = spt.query(mid,i);
                    if (x <= b[i]) {
                        l = mid;
                        hi = mid - 1;
                    }
                    else lo = mid + 1;
                }
            }
            if (i < n-1) {
                ll lo = i+1, hi = n-1;
                while (lo <= hi) {
                    ll mid = (lo+hi)/2;
                    ll x = spt.query(i,mid);
                    if (x <= b[i]) {
                        r = mid;
                        lo = mid + 1;
                    }
                    else hi = mid - 1;
                }
            }
            if (r-l+1 >= b[i]) return b[i];
        }
        return -1;
    }
};
