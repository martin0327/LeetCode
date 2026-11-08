template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
using vi = vector<int>;
class Solution {
public:
    int countSuffix(vector<int>& a, vector<int>& b) {
        int n = a.size(), ans = 0;
        auto sa = a, sb = b;
        asort(sa);
        asort(sb);
        if (sa != sb) return ans;

        vi pre(n), suf(n);
        for (int i=0; i<n; i++) {
            if (a[i] == b[i]) pre[i] = 1;
            else break;
        }
        suf[n-1] = 1;
        for (int i=n-2; i>=0; i--) {
            if (b[i] >= b[i+1]) suf[i] = 1;
            else break;
        }
        for (int i=0; i<n; i++) {
            if (suf[i]) {
                if (i == 0 || pre[i-1]) ans++;
            }
        }
        return ans;
    }
};