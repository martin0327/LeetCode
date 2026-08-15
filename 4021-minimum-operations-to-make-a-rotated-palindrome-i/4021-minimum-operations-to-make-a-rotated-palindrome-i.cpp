class Solution {
public:
    int minOperations(string s) {
        int n = s.size(), ans = 2e9;
        s = s + s;
        for (int i=0; i<n; i++) {
            int t = 0;
            for (int j=0; j<n; j++) {
                int k1 = i+j, k2 = i+n-1-j;
                if (k1 >= k2) break;
                int x = s[k1] - 'a';
                int y = s[k2] - 'a';
                if (x > y) swap(x,y);
                t += min(y-x, x+26-y);
            }
            ans = min(ans, t+i);
        }
        return ans;
    }
};