class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), ans = 2e9;
        s = s + s;
        for (int i=0; i<n; i++) {
            int t = 0;
            for (int j=0; j<n; j++) {
                if (i+j >= i+n-1-j) break;
                int x = s[i+j] - 'a';
                int y = s[i+n-1-j] - 'a';
                if (x > y) swap(x,y);
                t += min(y-x, x+26-y);
            }
            ans = min(ans, t+i);
        }
        return ans;
    }
};