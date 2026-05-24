const int inf = 2e9;
class Solution {
public:
    int minOperations(vector<int>& a) {
        int n = a.size();
        
        auto f = [&] (vector<int> a) {
            int idx = -1, ret = inf;
            for (int i=0; i<n; i++) {
                if (a[i] == 0) {
                    idx = i;
                    break;
                }
            }
            for (int i=1; i<idx; i++) {
                int x = a[i-1];
                int y = a[i];
                if (x+1 != y) return ret;
            }
            for (int i=idx; i+1<n; i++) {
                int x = a[i];
                int y = a[i+1];
                if (x+1 != y) return ret;
            }
            if (a[0] == 0) ret = 0;
            else ret = n-a[0];
            return ret;
        };

        auto g = [&] (vector<int> a) {
            int idx = -1, ret = inf;
            for (int i=0; i<n; i++) {
                if (a[i] == 0) {
                    idx = i;
                    break;
                }
            }
            for (int i=1; i<=idx; i++) {
                int x = a[i-1];
                int y = a[i];
                if (x-1 != y) return ret;
            }
            for (int i=idx+1; i+1<n; i++) {
                int x = a[i];
                int y = a[i+1];
                if (x-1 != y) return ret;
            }
            if (a[0] == n-1) ret = 1;
            else ret = a[0] + 2;
            return ret;
        };
        
        int ans = inf;
        ans = min(ans, f(a));
        ans = min(ans, g(a));
        reverse(a.begin(), a.end());
        ans = min(ans, f(a)+1);
        ans = min(ans, g(a)+1);
        
        if (ans == inf) ans = -1;
        return ans;
    }
};