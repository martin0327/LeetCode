#define ll long long
#define int ll

using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
// using vm = vector<mint>;
// using vvm = vector<vm>;
using pii = pair<int,int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using ti3 = tuple<int,int,int>;
using vti3 = vector<ti3>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        vi cnt(n+1);
        x--; y--;
        if (x > y) swap(x,y);
        vi a(n+1), b(n+1);
        if (x == y || x+1 == y) {
            for (int i=0; i<n; i++) {
                a[0]++;
                a[n-i]--;
            }
        }
        else {
            for (int i=0; i<n; i++) {
                if (i < x) {
                    int dx = x-i;
                    int dy = dx+1;
                    a[0]++;
                    a[dx]--;

                    a[dy+1]++;
                    a[dy+n-y]--;

                    int lo = x, hi = y, tg = -1;
                    while (lo <= hi) {
                        int mid = (lo+hi)/2;
                        if (dx+mid-x <= dy+y-mid) {
                            tg = mid;
                            lo = mid + 1;
                        }
                        else hi = mid - 1;
                    }
                    a[dx]++;
                    a[dx+tg-x+1]--;
                    a[dy]++;
                    a[dy+y-tg]--;
                }
                else if (i < y) {
                    int dy = min(y-i, i-x+1);
                    a[dy+1]++;
                    a[dy+n-y]--;

                    int lo = i, hi = y, tg = -1;
                    while (lo <= hi) {
                        int mid = (lo+hi)/2;
                        if (mid-i <= dy+y-mid) {
                            tg = mid;
                            lo = mid + 1;
                        }
                        else hi = mid - 1;
                    }
                    a[0]++;
                    a[tg-i+1]--;
                    a[dy]++;
                    a[dy+y-tg]--;
                }
                else {
                    a[0]++;
                    a[n-i]--;
                }
            }
        }
        for (int i=1; i<=n; i++) a[i] += a[i-1];
        for (int i=1; i<=n; i++) {
            cnt[i] += a[i];
        }
        for (auto &x : cnt) x *= 2;
        cnt.erase(cnt.begin());
        return cnt;
    }
};

#define ll int

