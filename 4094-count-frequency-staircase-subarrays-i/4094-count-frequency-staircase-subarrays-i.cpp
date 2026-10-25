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
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
using vp = vector<pii>;

const int mx_sz = 1e5+5;
const int mx_n = 1e5+5;
const int mx_m = 450;
vi idx[mx_sz];
int b[mx_n][mx_m];
int c[mx_n][mx_m];
int inv[mx_n];
int pts[mx_sz];
int cnt[mx_m];
bool vis[mx_sz];

int L[mx_n], R[mx_n]; 
int last[mx_sz];

vi pre;

int head;

void pop(int u) {
    if (L[u] != -1) R[L[u]] = R[u];
    if (R[u] != -1) L[R[u]] = L[u];
    if (head == u) head = R[u];
}

void push(int u) {
    R[u] = head;
    L[u] = -1;
    if (head != -1) L[head] = u;
    head = u;
}


class Solution {
public:
    int countStaircase(vector<int>& a) {
        auto sz = *max_element(a.begin(), a.end()) + 1;
        for (int i=0; i<sz; i++) {
            idx[i].clear();
        }
        int n = a.size();
        for (int i=0; i<n; i++) {
            idx[a[i]].push_back(i);
        }
        int m = sqrt(2*n+10);
        if (pre.empty()) {
            pre = {1};
            for (int i=2; pre.size()<mx_m; i++) {
                pre.push_back(pre.back()+i);
            }
            for (int i=0; i+1<mx_n; i++) {
                auto x = i+1;
                auto it = lower_bound(pre.begin(), pre.end(), x);
                inv[x] = it - pre.begin();
            }
        }

        for (auto x : a) last[x] = -1;
        head = -1;

        for (int i = n - 1; i >= 0; i--) {
            int x = a[i];
            
            if (last[x] != -1) {
                pop(last[x]);
            }
            
            push(i);
            last[x] = i;

            int curr = head;
            for (int j = 0; j < m; j++) {
                if (curr != -1) {
                    b[i][j] = a[curr];
                    curr = R[curr];
                } else {
                    b[i][j] = -1; 
                }
            }
        }

        // b[i][j] : for a subarray that starts at i, the (j+1)-th distinct elm is b[i][j]

        for (auto x : a) pts[x] = 0;

        memset(cnt,0,sizeof(cnt));
        int ans = 0;
        for (int i=0; i<n; i++) {
            int lim = n;
            int cum = 0;
            for (int j=0; j<m; j++) {
                cum += j+1;
                if (i + cum - 1 >= lim) break;
                auto x = b[i][j];
                if (x == -1) break;
                auto &v = idx[x];
                auto &pt = pts[x];
                while (pt < v.size()) {
                    if (v[pt] < i) pt++;
                    else break;
                }
                assert(pt < v.size());
                int r = (pt + j < v.size()) ? v[pt+j] : n;
                int nr = (pt+j+1 < v.size()) ? v[pt+j+1] : n;
                chmin(lim, nr);
                int d = r - i + 1;
                if (0 <= d && d <= n && 0 <= inv[d] && inv[d] < m) {
                    cnt[inv[d]]++;
                }
            }
            cum = 0;
            for (int j=0; j<m; j++) {
                cum += j+1;
                if (i + cum - 1 >= lim) break;
                if (j > 0) cnt[j] += cnt[j-1];
                if (cnt[j] == j+1) {
                    ans++;
                }
            }
            for (int j=0; j<m; j++) cnt[j] = 0;
        }
        return ans;
    }
};