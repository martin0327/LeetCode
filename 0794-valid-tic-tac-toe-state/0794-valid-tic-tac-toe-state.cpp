

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}
template<typename T>
void reverse(vector<T> &a) {reverse(a.begin(), a.end());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;
using vvs = vector<vs>;

class Solution {
public:
    bool validTicTacToe(vector<string>& b) {
        int n = b.size();
        vp a1, a2;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (b[i][j] == 'O') a2.push_back({i,j});
                else if (b[i][j] == 'X') a1.push_back({i,j});
            }
        }
        int sz1 = a1.size(), sz2 = a2.size();
        if (abs(sz1-sz2) > 1) return false;
        if (sz2 > sz1) return false;
        asort(a1);
        asort(a2);
        auto g = [&] (string s) {
            if (s[0] == ' ') return false;
            for (int i=1; i<n; i++) {
                if (s[i] != s[i-1]) return false;
            }
            return true;
        };
        auto f = [&] (vs a) {
            int n = a.size();
            for (int i=0; i<n; i++) {
                if (g(a[i])) return true;
            }
            for (int j=0; j<n; j++) {
                string s;
                for (int i=0; i<n; i++) {
                    s += a[i][j];
                }
                if (g(s)) return true;
            }
            string s;
            for (int i=0; i<n; i++) s += a[i][i];
            if (g(s)) return true;
            s.clear();
            for (int i=0; i<n; i++) s += a[i][n-1-i];
            if (g(s)) return true;
            return false;
        };
        if (sz1 == 0 || sz2 == 0) return true;
        bool ans = false;
        do {
            do {
                vs cur(n, string(n, ' '));
                vp rc;
                for (int i=0,j=0; i<sz1 || j<sz2;) {
                    if (i==j) {
                        rc.push_back(a1[i++]);
                    }
                    else {
                        rc.push_back(a2[j++]);
                    }
                }
                rc.pop_back();
                bool ok = true;
                for (auto [r,c] : rc) {
                    cur[r][c] = b[r][c];
                    if (f(cur)) ok = false;   
                }
                // if (ok) {
                //     for (auto [r,c] : rc) {
                //         cout << r << " " << c << endl;
                //     }
                // }
                if (ok) ans = true;
            } while(next_permutation(a2.begin(), a2.end()));
        } while(next_permutation(a1.begin(), a1.end()));
        return ans;
    }
};