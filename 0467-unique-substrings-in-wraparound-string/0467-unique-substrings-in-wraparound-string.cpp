using pii = pair<int,int>;
using vi = vector<int>;
const int sz = 26;
class Solution {
public:
    int findSubstringInWraproundString(string s) {
        int n = s.size();
        vi a(n,1), b(sz);
        for (int i=0; i<n; i++) {
            int x = s[i] - 'a';
            if (i > 0) {
                int y = s[i-1] - 'a';
                if (x == (y+1) % sz) a[i] = a[i-1] + 1;
            }
            b[x] = max(b[x], a[i]);
        }
        int ans = accumulate(b.begin(), b.end(), 0);
        return ans;
    }
}; 