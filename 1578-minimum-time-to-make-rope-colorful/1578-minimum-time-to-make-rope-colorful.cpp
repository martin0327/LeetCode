class Solution {
public:
    int minCost(string s, vector<int>& a) {
        int n = s.size();
        int len = 1;
        int ans = 0;
        s.push_back(' ');
        for (int i=1; i<=n; i++) {
            if (s[i]==s[i-1]) len++;
            else {
                if (len > 1) {
                    int s = 0;
                    int m = 0;
                    for (int j=i-len; j<i; j++) {
                        s += a[j];
                        m = max(m, a[j]);
                    }
                    ans += s - m;
                }
                len = 1;
            }
        }
        return ans;
    }
};